#include "minitalk.h"

static  void	ft_display_banner(void)
{
	write(1,
	"\n\n"
	"\t\t█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗\n"
	"\t\t╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝\n"
	"\n"
	"\t\t\t░▒▓██████████████▓▒░  ░▒▓█▓▒░ ░▒▓███████▓▒░  ░▒▓█▓▒░ ░▒▓████████▓▒░  ░▒▓██████▓▒░  ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░ \n"
	"\t\t\t░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░ \n"
	"\t\t\t░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░ \n"
	"\t\t\t░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓████████▓▒░ ░▒▓█▓▒░        ░▒▓███████▓▒░  \n"
	"\t\t\t░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░ \n"
	"\t\t\t░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░ \n"
	"\t\t\t░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓████████▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ \n"
	"\n",
	2877);
	write(1, "\t\t\t\t\t\t\t\t\t<<PID = ", 17);
	printf("%d", getpid());
	fflush(stdout);
	write(1, ">>\n\n"
	"\t\t█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗\n"
	"\t\t╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝\n"
	"\n\n",
	768);
}

static void	message_handler(int signum, t_client *client)
{
	client->bit++;
	client->byte <<= 1;
	if (signum == SIGUSR1)
		client->byte |= 0X01;
	if (client->bit == 8 && client->byte)
		client->message[client->i++] = client->byte;
	if (client->i == 4096 || (client->bit == 8 && !client->byte))
	{
		write(1, client->message, client->i);
		if (client->bit == 8 && !client->byte)
		{
			write(1, "\n", 1);
			if (kill(client->client_pid, SIGUSR2) == -1)
			{
				write(1, "kill failed\n", 12);
				exit(1);
			}
			client->client_pid = 0;
		}
		client->i = 0;
	}
	if (client->bit == 8)
		client->bit = 0;
}

static void	signal_handler(int signum, siginfo_t *info, void __attribute__((unused)) *context)
{
	static t_client	client;

	if (!client.client_pid)
		client.client_pid = info->si_pid;
	if (client.client_pid != info->si_pid)
	{
		client.client_pid = info->si_pid;
		client.bit = 0;
		client.i = 0;
	}
	message_handler(signum, &client);
	if (client.client_pid)
	{
		if (kill(client.client_pid, SIGUSR1) == -1)
		{
			write(1, "kill failed\n", 12);
			exit(1);
		}
	}
}
int	main(void)
{
	struct sigaction act;

	act.sa_flags = SA_SIGINFO;
	ft_display_banner();
	if (sigemptyset(&act.sa_mask) == -1)
		return (write(1, "sigemptyset failed\n", 19), 1);
	act.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &act, NULL) == -1 || sigaction(SIGUSR2, &act, NULL) == -1)
		return (write(1, "sigaction failed\n", 17), 1);
	while (1)
	{
		pause();
	}
}
