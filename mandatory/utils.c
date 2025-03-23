/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 07:12:39 by yjaafar           #+#    #+#             */
/*   Updated: 2025/03/23 07:12:40 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putpid(pid_t n)
{
	char	arr[10];
	int		i;

	i = 0;
	if (n == 0)
		write(1, "0", 1);
	while (n)
	{
		arr[i++] = n % 10 + 48;
		n /= 10;
	}
	while (i--)
	{
		write(1, &arr[i], 1);
	}
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	write(1, s, i);
}

void	ft_putclient(t_client *g_client)
{
	ft_putstr("client [");
	ft_putpid(g_client->client_pid);
	ft_putstr("] : ");
	g_client->_bool = 0;
}

void	free_clients(t_client *g_client)
{
	t_client	*tmp;

	while (g_client)
	{
		tmp = g_client->next;
		free(g_client);
		g_client = tmp;
	}
}

void	delete_client(t_client **g_client)
{
	t_client	*tmp;

	if (!*g_client)
		return ;
	tmp = (*g_client)->next;
	write(1, "\n", 1);
	free(*g_client);
	*g_client = tmp;
	if (*g_client)
	{
		kill((*g_client)->client_pid, SIGUSR1);
	}
	else
	{
		add_node_back(1, 0, 0);
	}
}
