#include "../include/ft_ping.h"
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <limits.h>

unsigned short checksum(void *b, int len)
{
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char*)buf;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

int send_ping(t_ping_config *config, int seq)
{
    struct icmphdr icmp_hdr;
    char packet[PACKET_SIZE];

    memset(&icmp_hdr, 0, sizeof(icmp_hdr));
    icmp_hdr.type = ICMP_ECHO;
    icmp_hdr.code = 0;
    icmp_hdr.un.echo.sequence = htons(seq);
    icmp_hdr.un.echo.id = htons(config->pid);

    memcpy(packet, &icmp_hdr, sizeof(icmp_hdr));
    memset(packet + sizeof(icmp_hdr), 0, PACKET_SIZE - sizeof(icmp_hdr));

    icmp_hdr.checksum = checksum(packet, PACKET_SIZE);
    memcpy(packet, &icmp_hdr, sizeof(icmp_hdr));

    int bytes_sent = sendto(config->sockfd, packet, PACKET_SIZE, 0,
                        (struct sockaddr*)&config->addr, sizeof(config->addr));

    if (bytes_sent < 0) {
        perror("ft_ping: sendto");
        return -1;
    }
    return bytes_sent;
}

int recv_ping(t_ping_config *config, int seq, struct timeval *end_time, int *ttl)
{
    char buffer[MAX_PACKET_SIZE];
    struct sockaddr_in r_addr;
    socklen_t addr_len = sizeof(r_addr);
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    if (setsockopt(config->sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        perror("Error setting socket timeout");
        return -1;
    }

    while (1) {
        int bytes_received = recvfrom(config->sockfd, buffer, sizeof(buffer), 0,
                                      (struct sockaddr*)&r_addr, &addr_len);

        if (bytes_received < 0) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                printf("Timeout waiting for response\n");
            } else {
                perror("ft_ping: recvfrom");
            }
            return -1;
        }

        gettimeofday(end_time, NULL);

        struct iphdr *ip_hdr = (struct iphdr *)buffer;
        int ip_header_len = ip_hdr->ihl * 4;
        struct icmphdr *icmp_hdr = (struct icmphdr *)(buffer + ip_header_len);

        *ttl = ip_hdr->ttl;

        if (icmp_hdr->type == ICMP_ECHOREPLY) {
            if (ntohs(icmp_hdr->un.echo.id) == config->pid && ntohs(icmp_hdr->un.echo.sequence) == seq) {
                inet_ntop(AF_INET, &(r_addr.sin_addr), config->responding_ip, INET_ADDRSTRLEN);
                return 0;
            }
        }
    }
}
