#include "../include/ft_ping.h"

extern volatile sig_atomic_t keep_pinging;

int initialize_socket(t_ping_config *config)
{
    struct hostent *host;
    struct protoent *protocol;

    host = gethostbyname(config->destination);
    if (host == NULL) {
        fprintf(stderr, "ft_ping: unknown host %s\n", config->destination);
        return 1;
    }

    config->addr.sin_family = host->h_addrtype;
    config->addr.sin_port = 0;
    config->addr.sin_addr = *((struct in_addr *)host->h_addr);

    config->resolved_hostname = strdup(host->h_name);
    if (config->resolved_hostname == NULL) {
        fprintf(stderr, "ft_ping: failed to allocate memory for hostname\n");
        return 1;
    }

    protocol = getprotobyname("ICMP");
    if (protocol == NULL) {
        fprintf(stderr, "ft_ping: unknown protocol ICMP\n");
        return 1;
    }

    config->sockfd = socket(AF_INET, SOCK_RAW, protocol->p_proto);
    if (config->sockfd < 0) {
        perror("ft_ping: socket");
        return 1;
    }

    config->pid = getpid() & 0xFFFF;
    
    config->responding_ip[0] = '\0';
    config->responding_hostname = NULL;
    return 0;
}

void ping_loop(t_ping_config *config)
{
    int seq = 1;
    struct timeval start, end;
    double rtt;
    int ttl;

    printf("PING %s (%s) %lu(%lu) bytes of data.\n", config->destination,
           config->resolved_hostname, (unsigned long)PACKET_SIZE, (unsigned long)MAX_PACKET_SIZE);

    while (keep_pinging) {
        config->packets_transmitted++;
        gettimeofday(&start, NULL);

        if (send_ping(config, seq) < 0) {
            fprintf(stderr, "Failed to send ping\n");
            continue;
        }

        if (recv_ping(config, seq, &end, &ttl) == 0) {
            config->packets_received++;
            rtt = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;

            config->total_rtt += rtt;
            if (rtt < config->min_rtt || config->min_rtt == 0) config->min_rtt = rtt;
            if (rtt > config->max_rtt) config->max_rtt = rtt;

            char* responding_hostname = get_hostname_from_ip(config->responding_ip);
            printf("%lu bytes from %s (%s): icmp_seq=%d ttl=%d time=%.1f ms\n",
                   (unsigned long)PACKET_SIZE, 
                   responding_hostname ? responding_hostname : config->responding_ip,
                   config->responding_ip, seq, ttl, rtt);
            if (responding_hostname) free(responding_hostname);
        } else {
            printf("Request timeout for icmp_seq %d\n", seq);
        }

        seq++;
        sleep(1);
    }

    config->packet_loss_percentage = 100.0 * (config->packets_transmitted - config->packets_received) / config->packets_transmitted;
    config->average_rtt = config->packets_received > 0 ? config->total_rtt / config->packets_received : 0;

    print_statistics(config);
}
