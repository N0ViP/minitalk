/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:44:55 by yjaafar           #+#    #+#             */
/*   Updated: 2025/03/23 09:55:27 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static volatile sig_atomic_t	g_var;

static pid_t	ft_atopid(char *s)
{
	long long	res;
	int			sign;

	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	sign = (*s == 45) * -1 + (*s != 45);
	s += ((*s == 45) || (*s == 43));
	res = 0;
	while (*s >= 48 && *s <= 57)
	{
		res = (res << 3) + (res << 1) + (*s++ & 0X0F);
		if (res > 2147483647 + (sign == -1))
		{
			return (-1);
		}
	}
	return ((pid_t)res * sign);
}

static void	signal_handler(int signum, siginfo_t __attribute__((unused))
	*info, void __attribute__((unused)) *context)
{
	if (signum == SIGUSR1)
	{
		g_var = 1;
	}
	else
	{
		ft_putstr("the message was receirved successfully\n");
		exit(0);
	}
}

static void	send_byte(char c, int server_pid)
{
	int	bits;
	int	sig;

	bits = 7;
	while (bits >= 0)
	{
		if (((c >> bits) & 0X01) == 1)
			sig = SIGUSR1;
		else
			sig = SIGUSR2;
		if (kill(server_pid, sig) == -1)
		{
			ft_putstr("kill failed\n");
			exit(1);
		}
		while (!g_var)
			usleep(50);
		g_var = 0;
		bits--;
	}
}

static void	send_message(char *s, int server_pid)
{
	int	i;

	i = 0;
	while (s[i])
	{
		send_byte(s[i], server_pid);
		i++;
	}
	send_byte(0, server_pid);
}

int	main(int ac, char *av[])
{
	struct sigaction	act;
	pid_t				server_pid;			

	if (ac != 3)
		return (ft_putstr("./client <server_pid> \"message\"\n"), 1);
	server_pid = ft_atopid(av[1]);
	if (server_pid <= 0 || kill(server_pid, 0) == -1)
		return (ft_putstr("Invalid server PID\n"), 1);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = signal_handler;
	if (sigemptyset(&act.sa_mask) == -1)
		return (ft_putstr("sigemptyset failed\n"), 1);
	if (sigaction(SIGUSR1, &act, NULL) == -1
		|| sigaction(SIGUSR2, &act, NULL) == -1)
		return (ft_putstr("sigaction failed\n"), 1);
	send_message(av[2], server_pid);
	while (1)
		pause();
}
