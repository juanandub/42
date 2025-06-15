#include "minitalk.h"

void	send_char(pid_t server_pid, char c)
{
	int	bit_count;

	bit_count = 0;
	while (bit_count < 8)
	{
		if ((c & (0x80 >> bit_count)) != 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(500);
		bit_count++;
	}
}

void	send_message(pid_t server_pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_char(server_pid, message[i]);
		i++;
	}
	send_char(server_pid, '\0');
}

int	validate_pid(char *pid_str)
{
	int	i;

	i = 0;
	if (!pid_str || !pid_str[0])
		return (0);
	while (pid_str[i])
	{
		if (pid_str[i] < '0' || pid_str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_putstr("Usage: ./client <server_pid> <message>\n");
		return (1);
	}
	if (!validate_pid(argv[1]))
	{
		ft_putstr("Error: Invalid PID\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr("Error: Invalid PID\n");
		return (1);
	}
	send_message(server_pid, argv[2]);
	return (0);
} 