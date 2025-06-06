#ifndef FT_PING_H
#define FT_PING_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <errno.h>
#include <sys/time.h>
#include <netinet/ip_icmp.h>

#define PACKET_SIZE 64
#define MAX_PACKET_SIZE 84
#define DEFAULT_TIMEOUT 1

typedef struct s_ping_config {
    char *destination;
    char *resolved_hostname;
    int verbose;
    int show_help;
    struct sockaddr_in addr;
    int sockfd;
    int seq;
    int pid;
    int packets_transmitted;
    int packets_received;
    double min_rtt;
    double max_rtt;
    double total_rtt;
    double packet_loss_percentage;
    double average_rtt;
    char responding_ip[INET_ADDRSTRLEN];
    char *responding_hostname;
    int timeout;
} t_ping_config;

// Function prototypes

// ping_utils.c
int parse_arguments(int argc, char *argv[], t_ping_config *config);
void print_usage(void);
char* get_hostname_from_ip(const char* ip_addr);
void print_statistics(t_ping_config *config);
void cleanup(t_ping_config *config);

// socket_ops.c
int initialize_socket(t_ping_config *config);
void ping_loop(t_ping_config *config);

// icmp_ops.c
unsigned short checksum(void *b, int len);
int send_ping(t_ping_config *config, int seq);
int recv_ping(t_ping_config *config, int seq, struct timeval *end_time, int *ttl);

// Global variables
extern volatile sig_atomic_t keep_pinging;

#endif // FT_PING_H
