# include "minitalk.h"

static volatile sig_atomic_t g_var;

static void signal_handler(int signum, siginfo_t *info, void __attribute__((unused)) *content)
{

}

static void	ft_send_byte(int server_pid, char c)
{
	int	bit;
	int	i;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 0X01;
		if (bit == 1)
			if (kill(server_pid, SIGUSR1) == -1)
				ft_exit(3);
		else
		if (kill(server_pid, SIGUSR2) == -1)
		ft_exit(3);
		while (g_var)
			usleep(50);
		g_var = 0;
		i--;
	}
}

int	main(int ac, char *av[])
{
	struct sigaction	sa;
	int					server_pid;
	int					i;

	if (ac != 3)
		ft_exit(1);
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0)
		ft_exit(2);
	sa.sa_info = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_exit(4);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_exit(4);
	if (sigaction(SIGINT, &sa, NULL) == -1)
		ft_exit(4);
	i = 0;
	while (av[2][i])
		ft_send_byte(av[2][i++]);
	return (0);
}