/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:03:11 by yjaafar           #+#    #+#             */
/*   Updated: 2025/03/22 01:03:13 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

static t_client	*g_client;

static void	banner_part3(void)
{
	int		n;
	int		i;
	char	arr[10];

	i = 0;
	write(1, "\t\t\t\t\t\t\t\t\t<<PID = ", 17);
	n = getpid();
	while (n)
	{
		arr[i++] = n % 10 + 48;
		n /= 10;
	}
	while (i--)
		write(1, &arr[i], 1);
	write(1, ">>\n\n", 4);
	write(1, "\t\t█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗"
		"█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗"
		"█████╗█████╗█████╗█████╗█████╗\n"
		"\t\t╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝"
		"╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝"
		"╚════╝╚════╝╚════╝╚════╝╚════╝\n"
		"\n\n",
		764);
}

static void	banner_part2(void)
{
	write(1,
		"\t\t\t░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ "
		"░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░      "
		"░▒▓█▓▒░░▒▓█▓▒░ \n"
		"\t\t\t░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ "
		"░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░      "
		"░▒▓█▓▒░░▒▓█▓▒░ \n"
		"\t\t\t░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ "
		"░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓████████▓▒"
		"░▒▓█▓▒░░▒▓█▓▒░ \n"
		"\n",
		904);
}
	
static void	display_banner(void)
{
	write(1,
		"\n\n"
		"\t\t█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗"
		"█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗"
		"█████╗█████╗█████╗█████╗█████╗\n"
		"\t\t╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝"
		"╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝"
		"╚════╝╚════╝╚════╝╚════╝╚════╝\n"
		"\n"
		"\t\t\t░▒▓██████████████▓▒░  ░▒▓█▓▒░ ░▒▓███████▓▒░  "
		"░▒▓█▓▒░ ░▒▓████████▓▒░  ░▒▓██████▓▒░  ░▒▓█▓▒░      "
		"░▒▓█▓▒░░▒▓█▓▒░ \n"
		"\t\t\t░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ "
		"░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░      "
		"░▒▓█▓▒░░▒▓█▓▒░ \n"
		"\t\t\t░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ "
		"░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░      "
		"░▒▓█▓▒░░▒▓█▓▒░ \n"
		"\t\t\t░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ "
		"░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓████████▓▒░ ░▒▓█▓▒░      "
		"░▒▓███████▓▒░  \n",
		1957);
	banner_part2();
	banner_part3();
}

static void	delete_client()
{
	t_client	*tmp;

	if (!g_client)
		return ;
	tmp = g_client->next;
	if (g_client->i)
	{
		write(1, g_client->message, g_client->i);
		write(1, "\n", 1);
	}
	free(g_client);
	g_client = tmp;
}

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
			write(1, "\n", 1);
			kill(g_client->client_pid, SIGUSR2);
			if (errno == EPERM || errno == EINVAL)
			{
				write(1, "kill failed\n", 12);
				delete_client();
				exit(1);
			}
			delete_client();
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
	tmp->client_pid = client_pid;
	tmp->bit = 0;
	tmp->byte = 0;
	tmp->i = 0;
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
		message_handler(signum);
	}
	if (g_client && g_client->client_pid == info->si_pid)
	{
		kill(g_client->client_pid, SIGUSR1);
		if (errno == EPERM || errno == EINVAL)
		{
			write(1, "kill failed\n", 12);
			delete_client();
			exit(1);
		}
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
		if (g_client)
			if (kill(g_client->client_pid, 0) == -1)
				delete_client();
		pause();
	}
}

