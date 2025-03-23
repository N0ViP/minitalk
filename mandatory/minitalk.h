/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:57:33 by yjaafar           #+#    #+#             */
/*   Updated: 2025/03/23 07:14:39 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_client
{
	pid_t			client_pid;
	int				_bool;
	int				bit;
	int				i;
	char			byte;
	char			message[4096];
	struct s_client	*next;
}	t_client;

void	ft_putstr(char *s);
void	ft_putpid(pid_t n);
void	display_banner(void);
void	ft_putclient(t_client *g_client);
void	free_clients(t_client *g_client);
void	delete_client(t_client **g_client);
void	add_node_back(int n, t_client **client, t_client *node);

#endif
