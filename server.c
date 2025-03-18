#include "minitalk.h"

static int	fill_message(int signum, t_clients *client)
{
	if (!client->message)
	{
		client->message = malloc(1024);
		if (!client->message)
			return (-1);
	}
	if (client->i == client->len - 1 && client->message[client->i])
	{
		client->message = strjoin(client->message);
		if (!client->message)
			return (-1);
		client->len += 1024;
	}
	client->bits++;
	client->c <<= 0X01;
	if (signum == SIGUSR1)
		client->c |= 0X01;
	if (client->bits == 8 && client->c)
	{
		client->message[client->i++] = client->c;
	}
	if (client->bits == 8 && !client->c)
		client->finish = 1;
	return (0);
}

static int	get_client(int signum, t_clients **root, int pid)
{
	t_clients	*tmp;
	t_clients	*client;

	tmp = *root;
	if (!*root)
	{
		*root = addnode_back(root, pid);
		client = *root;
	}
	else if (tmp->client_pid == pid)
		client = tmp;
	else
	{
		while (tmp->next && tmp->next->client_pid != pid)
			tmp = tmp->next;
		if (!tmp->next)
			tmp->next = addnode_back(root, pid);
		client = tmp->next;
	}
	if (fill_message(signum, client) == -1)
		return (-1);
	return (0);
}

static void	sighandler(int signum, siginfo_t *info, void __attribute__((unused)) *context)
{
	static	t_clients	*root;
	t_clients			ptr;

	if (get_client(signum, &root, info->si_pid) == -1)
		ft_exit(1);
	print_message(&root);
	if (kill(SIGUSR1, info->si_pid) == -1)
		ft_exit(2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_display_banner();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sighandler;
	if (sigemptyset(&sa.sa_mask) == -1)
		ft_exit(0);
	while (1)
	{
		pause();
	}
}
