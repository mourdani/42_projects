#include "../include/ft_ping.h"

// Global flag to control the ping loop
volatile sig_atomic_t keep_pinging = 1;

// Signal handler for SIGINT (Ctrl+C)
void sigint_handler(int signo) {
    (void)signo;
    keep_pinging = 0;
}

int main(int argc, char *argv[])
{
    t_ping_config config = {0};
    config.min_rtt = __DBL_MAX__;
    config.max_rtt = 0;
    config.total_rtt = 0;

    if (parse_arguments(argc, argv, &config) != 0) {
        return 1;
    }

    if (config.show_help) {
        print_usage();
        return 0;
    }

    if (initialize_socket(&config) != 0) {
        return 1;
    }

    signal(SIGINT, sigint_handler);

    ping_loop(&config);

    cleanup(&config);
    return 0;
}
