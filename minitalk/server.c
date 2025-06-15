#include "minitalk.h"

volatile sig_atomic_t	g_signal_received = 0;

void	signal_handler(int signal)
{
	static int	bit_count = 0;
	static char	current_char = 0;

	if (signal == SIGUSR1)
		current_char |= (0x80 >> bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		ft_putchar(current_char);
		if (current_char == '\0')
			ft_putchar('\n');
		bit_count = 0;
		current_char = 0;
	}
}

void	setup_signal_handlers(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	setup_signal_handlers();
	while (1)
		pause();
	return (0);
} 