#include "minitalk.h"

static volatile sig_atomic_t	g_var;

static int	ft_ascii_to_int(char *s)
{
	long long	res;
	int			sign;

	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	sign = (*s == 45) * -1 + (*s != 45);
	s += (*s == 45) || (*s == 43);
	res = 0;
	while (*s >= 48 && *s <= 57)
	{
		res = (res << 3) + (res << 1) + (*s++ & 0X0F);
		if (res > 2147483647 + (sign == -1))
		{
			return (-1);
		}
	}
	return ((int)res * sign);
}

static void	signal_handler(int	signum, siginfo_t *info, void __attribute__((unused)) *context)
{
	if (signum == SIGUSR1)
	{
		g_var = 1;
	}
	else
	{
		write(1, "the message was receirved successfully\n", 40);
		exit(0);
	}
}

static	void	send_byte(char *s, int server_pid)
{
	int	bits;
	int	sig;

	while (*s)
	{
		bits = 7;
		while (bits >= 0)
		{
			if (((*s >> bits) & 0X01) == 1)
				sig = SIGUSR1;
			else
				sig = SIGUSR2;
			if (kill(server_pid, sig) == -1)
			{
				write(1, "kill failed\n", 13);
				exit(1);
			}
			while (!g_var)
				usleep(10);
			g_var = 0;
			bits--;
		}
		s++;
	}
}

int	main(int ac, char *av[])
{
	struct sigaction	act;
	int					server_pid;			

	if (ac != 3)
		return (write(1, "Usage: ./client <server_pid> \"message\"\n", 40), 1);
	server_pid = ft_ascii_to_int(av[1]);
	if (server_pid <= 0 || kill(server_pid, 0) == -1)
		return (write(1, "Invalid server PID\n", 20), 1);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = signal_handler;
	if (sigemptyset(&act.sa_mask) == -1)
		return (write(1, "sigemptyset failed\n", 20), 1);
	if (sigaction(SIGUSR1, &act, NULL) == -1
		|| sigaction(SIGUSR2, &act, NULL) == -1)
		return (write(1, "sigaction failed\n", 18), 1);
	send_byte(av[2], server_pid);
	while (1)
		pause();
}
