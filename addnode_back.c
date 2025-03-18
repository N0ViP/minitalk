#include "minitalk.h"

static void	init_node(t_clients *client, int pid)
{
		client->client_pid = pid;
		client->finish = 0;
		client->bits = 0;
		client->i = 0;
		client->len = 1024;
		client->message = 0;
		client->c = 0;
		client->next = 0;
}

t_clients	*addnode_back(t_clients **root, int pid)
{
		t_clients	*ptr;

		ptr = *root;
		if (!*root)
		{
				*root = (t_clients *) malloc(sizeof(t_clients));
				if (!*root)
						return (NULL);
				return (init_node(*root, pid), *root);
		}
		while (ptr->next)
				ptr = ptr->next;
		ptr->next = (t_clients *) malloc(sizeof(t_clients));
		if (!ptr)
				return (NULL);
		return (init_node(ptr->next, pid), ptr->next);
}
