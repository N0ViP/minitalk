/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:41:18 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/07 00:17:32 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	buffer[64];
	static char	c;
	static int	bits;
	static int	bytes;

	bits++;
	c <<= 1;
	if (signum == SIGUSR1)
		c |= 1;
	if (bits == 8)
		buffer[bytes++] = c;
	if (bytes == 64 || (!c && bits == 8))
	{
		if (write(1, buffer, bytes) == -1)
			ft_exit(-5);
		if (!c && bits == 8)
			if (kill(info->si_pid, SIGUSR1) == -1)
				ft_exit(-6);
		bytes = 0;
	}
	if (bits == 8)
		bits = 0;
	if (kill(info->si_pid, SIGUSR2) == -1)
		ft_exit(-6);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_signal_handler;
	if (sigemptyset(&sa.sa_mask) == -1)
		ft_exit(-7);
	ft_display_banner();
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_exit(-8);;
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_exit(-8);
	while (1)
	{
		pause();
	}
}
