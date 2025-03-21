/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:57:33 by yjaafar           #+#    #+#             */
/*   Updated: 2025/03/20 10:58:55 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_client
{
	int				client_pid;
	int				bit;
	int				i;
	char			byte;
	char			message[4096];
    struct s_client *next;
}	t_client;

#endif
