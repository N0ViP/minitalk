/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:41:33 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/07 00:08:51 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_atomic = 0;

void	ft_usr1_handler(int __attribute__((unused)) signum)
{
	ft_exit(1);
}

void	ft_usr2_handler(int __attribute__((unused)) signum)
{
	g_atomic = 1;
}

void	ft_send_signal(unsigned char c, int server_pid)
{
	unsigned char	tmp;
	int				bits;

	bits = 7;
	while (bits >= 0)
	{
		tmp = (c >> bits) & 1;
		if (tmp)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				ft_exit(-1);
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				ft_exit(-2);
		}
		bits--;
		while (!atomic)
			usleep(20);
		g_atomic = 0;
	}
}

int	main(int ac, char *av[])
{
	int		server_pid;
	int		i;

	if (ac != 3)
		ft_exit(0);
	if (signal(SIGUSR1, ft_usr1_handler) == -1)
		ft_exit(-8);
	if (signal(SIGUSR2, ft_usr2_handler) == -1)
		ft_exit(-8);
	server_pid = atoi(av[1]);
	if (server_pid <= 0)
		return (-3);
	i = 0;
	while (av[2][i])
	{
		ft_send_signal(av[2][i], server_pid);
		i++;
	}
	ft_send_signal('\0', server_pid);
	while (1)
	{
		pause();
	}
}
