/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_messages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 03:44:53 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/05 22:57:53 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_exit(int exit_code)
{
	if (exit_code == 1)
		ft_printf("Message received seccessfully!\n");
	else if (exit_code == 0)
		ft_printf("Enter the pid of the server following by the message you want to send to the server!\n");
	else if (exit_code == -1)
		ft_printf("The client failed to send SIGUSR1 signal to the server!\n");
	else if (exit_code == -2)
		ft_printf("The client failed to send SIGUSR2 signal to the server!\n");
	else if (exit_code == -3)
		ft_printf("Invalide pid!\n");
	else if (exit_code == -4)
		ft_printf("Allocation failed!\n");
	else if (exit_code == -5)
		ft_printf("Write function failed!\n");
	else if (exit_code == -6)
		ft_printf("The server failed to send SIGUSR1 signal to the client!\n");
	exit (0);
}
