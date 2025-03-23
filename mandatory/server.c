# include "minitalk.h"

static t_client	*g_client;

static void	message_handler(int signum)
{
	g_client->bit++;
	g_client->byte <<= 1;
	if (signum == SIGUSR1)
		g_client->byte |= 0X01;
	if (g_client->bit == 8 && g_client->byte)
		g_client->message[g_client->i++] = g_client->byte;
	if (g_client->i == 4096 || (g_client->bit == 8 && !g_client->byte))
	{
		write(1, g_client->message, g_client->i);
		g_client->i = 0;
		if (g_client->bit == 8 && !g_client->byte)
		{
			kill(g_client->client_pid, SIGUSR2);
			delete_client(g_client);
		}
	}
	if (g_client && g_client->bit == 8)
		g_client->bit = 0;
}

static void	add_node_back(t_client *lst, t_client *node)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	lst->next = node;
}

static void	newnode(int signum, pid_t client_pid)
{
	t_client	*tmp;

	tmp = (t_client *) malloc(sizeof(t_client));
	if (!tmp)
	{
		free_clients(g_client);
		ft_putstr("malloc failed\n");
		exit(1);
	}
	tmp->client_pid = client_pid;
	tmp->bit = 0;
	tmp->byte = 0;
	tmp->i = 0;
	tmp->_bool = 1;
	tmp->next = 0;
	if (!g_client)
		g_client = tmp;
	else
		add_node_back(g_client, tmp);
	tmp->bit++;
	tmp->byte <<= 1;
	if (signum == SIGUSR1)
	{
		tmp->byte |= 0X01;
	}
}

static void signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (!g_client || g_client->client_pid != info->si_pid)
	{
		newnode(signum, info->si_pid);
	}
	else
	{
		if (g_client->_bool == 1)
			ft_putclient(g_client);
		message_handler(signum);
	}
	if (g_client && g_client->client_pid == info->si_pid)
	{
		kill(g_client->client_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	display_banner();
	if (sigemptyset(&act.sa_mask) == -1)
		return (write(1, "sigemptyset failed\n", 19), 1);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &act, NULL) == -1
		|| sigaction(SIGUSR2, &act, NULL) == -1)
		return (write(1, "sigaction failed\n", 17), 1);
	while (1)
	{
		if (g_client)
			if (kill(g_client->client_pid, 0) == -1)
				delete_client(g_client);
		// pause();
	}
}
