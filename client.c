#include "minitalk.h"

static t_stock stock;

static void	send_byte(int server_pid, char c)
{
	int	i;
	int	re;

	i = 7;
	re = 0;
	while (i >= 0)
	{
		if ((c >> i) & 0X01 == 1)
			if (kill(server_pid, SIGUSR1) == -1)
				ft_exit(3);
		else
			if (kill(server_pid, SIGUSR2) == -1)
				ft_exit(3);
		while (!stock.check)
		{
			usleep(50);
		}
		stock.check = 0;
		i--;
	}
	return (re);
}

static void signal_handler(int signum, siginfo_t *info, void __attribute__((unused)) *context)
{
	if (signum == SIGUSR1)
	{
		stock.check = 1;
	}
	else if (signum == SIGUSR2)
	{
		ft_exit(0);
	}
	else
	{
		stock.sigint = 1;
	}
}

static int	send_string(int ac, char *av[])
{
	int	i;
	int	re;
	int	server_pid;

	if (ac != 3)
		ft_exit(1);
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0)
		ft_exit(2);
	i = 0;
	re = 0;
	while (av[2][i])
	{
		send_byte(server_pid, av[2][i++]);
		if (stock.sigint)
		{
			re = 130;
			break;
		}
	}
	ft_send_byte(server_pid, 0);
	return (re);
}

int	main(int ac, char *av[])
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	if (sigemptyset(&sa.sa_mask) == -1)
		ft_exit(2);
	if (sigaddset(&sa.sa_mask, SIGINT) == -1)
		ft_exit(4);
	if (sigaddset(&sa.sa_mask, SIGUSR1) == -1)
		ft_exit(4);
	if (sigaddset(&sa.sa_mask, SIGUSR2) == -1)
		ft_exit(4);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_exit(4);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_exit(4);
	if (sigaction(SIGINT, &sa, NULL) == -1)
		ft_exit(4);
	if (send_string(ac, av) == 130)
		return (130);
	while (1)
		pause();
}
