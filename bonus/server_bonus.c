/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 07:12:27 by yjaafar           #+#    #+#             */
/*   Updated: 2025/03/23 09:56:02 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
			delete_client(&g_client);
		}
	}
	if (g_client && g_client->bit == 8)
		g_client->bit = 0;
}

////???

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
	add_node_back(0, &g_client, tmp);
	tmp->bit++;
	tmp->byte <<= 1;
	if (signum == SIGUSR1)
	{
		tmp->byte |= 0X01;
	}
}

static void	signal_handler(int signum, siginfo_t *info,
	void __attribute__((unused)) *context)
{
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

	act.sa_flags = SA_SIGINFO | SA_RESTART;
	display_banner();
	if (sigemptyset(&act.sa_mask) == -1)
		return (ft_putstr("sigemptyset failed\n"), 1);
	if (sigaddset(&act.sa_mask, SIGUSR1) == -1
		|| sigaddset(&act.sa_mask, SIGUSR2) == -1)
		return (ft_putstr("sigaddset failed\n"), 1);
	act.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &act, NULL) == -1
		|| sigaction(SIGUSR2, &act, NULL) == -1)
		return (ft_putstr("sigaction failed\n"), 1);
	while (1)
	{
		if (g_client)
			if (kill(g_client->client_pid, 0) == -1)
				delete_client(&g_client);
	}
}
