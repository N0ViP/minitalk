# include "minitalk.h"

static t_stock g_var;

static void	ft_send_byte(char c)
{
	int	bit;

	g_var.bits = 7;
	while (g_var.bits >= 0)
	{
		bit = (c >> g_var.bits) & 0X01;
		if (bit == 1)
			if (kill(g_var.server_pid, SIGUSR1) == -1)
				ft_exit(3);
		else
			if (kill(g_var.server_pid, SIGUSR2) == -1)
				ft_exit(3);
		while (!g_var.var)
			usleep(50);
		g_var.var = 0;
		g_var.bits--;
	}
}

static void signal_handler(int signum, siginfo_t *info, void __attribute__((unused)) *content)
{
	if (signum == SIGUSR1)
		g_var.var = 1;
	else if (signum == SIGUSR2)
		ft_exit(0);
	{
		g_var.bits += 8;
		while (g_var.bits >= 0)
		{
			if (kill(g_var.server_pid, SIGUSR2) == -1)
				ft_exit(3);
		}
		ft_exit(130);
	}
}

int	main(int ac, char *av[])
{
	struct sigaction	sa;
	int					i;

	if (ac != 3)
		ft_exit(1);
	g_var.server_pid = ft_atoi(av[1]);
	if (g_var.server_pid <= 0)
		ft_exit(2);
	sa.sa_flags = SA_SIGINFO;
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