/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:41:18 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/05 23:08:14 by yjaafar          ###   ########.fr       */
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
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_signal_handler;
	sigemptyset(&sa.sa_mask);
	ft_display_banner();
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
