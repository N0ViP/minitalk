# include "minitalk.h"

static t_client	*client;

void	delete_client()
{
	t_client	*tmp;

	tmp = client->next;
	if (client->i)
	{
		write(1, client->message, client->i);
	}
	free(client);
	client = tmp;
}

static void	newnode(int signum, pid_t client_pid)
{
	t_client	*tmp;

	tmp = (t_client *) malloc(sizeof(t_client));
	tmp->bit = 0;
	tmp->bit = 0;
	tmp->i = 0;
	tmp->messgae = {0};
	tmp->next = 0;
	if (!client)
		client = tmp;
	else
		add_node_back(client, tmp);
	tmp->bit++;
	if (signum == SIGUSR1);
	{
		tmp->byte |= 0X01;
	}
	
}

static void signal_handler(int signum, siginfo_t *info, void *context)
{
	if (!client || client->client_pid != info->si_pid)
	{
		newnode(signum, info->si_pid);
	}
	else
	{
		handle_message(signum);
	}
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	display_banner();
	if (sigemptyset(&act.sa_mask) == -1)
		return (write(1, "sigemptyset failed\n", 19), 1);
	act.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &act, NULL) == -1
		|| sigaction(SIGUSR2, &act, NULL) == -1)
		return (write(1, "sigaction failed\n", 17), 1);
	while (1)
	{
		if (kill(client->client_pid, 0) == -1)
			delete_client();
		pause();
	}
}
