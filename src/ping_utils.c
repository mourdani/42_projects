#include "../include/ft_ping.h"

int parse_arguments(int argc, char *argv[], t_ping_config *config)
{
    int opt;
    while ((opt = getopt(argc, argv, "vh")) != -1) {
        switch (opt) {
            case 'v':
                config->verbose = 1;
                break;
            case 'h':
                config->show_help = 1;
                return 0;
            default:
                fprintf(stderr, "Unknown option: %c\n", opt);
                return 1;
        }
    }

    if (optind >= argc) {
        fprintf(stderr, "Expected argument after options\n");
        return 1;
    }

    config->destination = argv[optind];
    return 0;
}

void print_usage(void)
{
    printf("Usage: ft_ping [options] <destination>\n");
    printf("Options:\n");
    printf("  -v        verbose output\n");
    printf("  -h        display this help and exit\n");
}

char* get_hostname_from_ip(const char* ip_addr) {
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    inet_pton(AF_INET, ip_addr, &(sa.sin_addr));

    char host[NI_MAXHOST];
    if (getnameinfo((struct sockaddr*)&sa, sizeof(sa), host, sizeof(host), NULL, 0, NI_NAMEREQD) != 0) {
        return NULL;
    }
    return strdup(host);
}

void print_statistics(t_ping_config *config)
{
    printf("\n--- %s ping statistics ---\n", config->destination);
    printf("%d packets transmitted, %d received, %.1f%% packet loss\n",
           config->packets_transmitted, config->packets_received,
           config->packet_loss_percentage);

    if (config->packets_received > 0) {
        printf("rtt min/avg/max = %.3f/%.3f/%.3f ms\n",
               config->min_rtt, config->average_rtt, config->max_rtt);
    } else {
        printf("No packets received\n");
    }
}

void cleanup(t_ping_config *config)
{
    close(config->sockfd);
    if (config->resolved_hostname) {
        free(config->resolved_hostname);
    }
    if (config->responding_hostname) {
        free(config->responding_hostname);
    }
}
