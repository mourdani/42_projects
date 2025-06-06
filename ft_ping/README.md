# ft_ping

ft_ping is a custom implementation of the ping utility in C. It sends ICMP ECHO_REQUEST packets to network hosts and displays the responses.

## Features

- Sends ICMP echo requests to specified hosts
- Displays round-trip time (RTT) for each received packet
- Shows packet loss statistics
- Supports verbose output mode
- Handles DNS resolution for hostnames

## Usage

```
./ft_ping [options] <destination>
```

Options:
- `-v`: Enable verbose output
- `-h`: Display help message and exit

## Building the Project

To compile the project, use the following command:
```
make
```
or

```
gcc -o ft_ping ft_ping.c -Wall -Wextra -Werror
```

## Running ft_ping

You need root privileges to run ft_ping due to its use of raw sockets. Use sudo:

```
sudo ./ft_ping www.example.com
```

## Notes

- This implementation requires root privileges to create raw sockets.
- The program uses ICMP protocol for ping operations.
- It handles both IPv4 addresses and hostnames.
