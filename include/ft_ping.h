#ifndef FT_PING_H
#define FT_PING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PACKET_SIZE 56
#define MAX_PACKET_SIZE 84

typedef struct s_ping_config {
    char *destination;
    struct sockaddr_in addr;
    int sockfd;
    int verbose;
    int show_help;
    unsigned short pid;
    char *resolved_hostname;
    char *responding_hostname;
    char responding_ip[INET_ADDRSTRLEN];
    int packets_transmitted;
    int packets_received;
    double packet_loss_percentage;
    double min_rtt;
    double max_rtt;
    double total_rtt;
    double average_rtt;
} t_ping_config;

// Function prototypes
int parse_arguments(int argc, char *argv[], t_ping_config *config);
void print_usage(void);
char* get_hostname_from_ip(const char* ip_addr);
void print_statistics(t_ping_config *config);
void cleanup(t_ping_config *config);
int initialize_socket(t_ping_config *config);
void ping_loop(t_ping_config *config);
unsigned short checksum(void *b, int len);
int send_ping(t_ping_config *config, int seq);
int recv_ping(t_ping_config *config, int seq, struct timeval *end_time, int *ttl);

#endif // FT_PING_H
