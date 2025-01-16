/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_messages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 03:44:53 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/13 09:17:59 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print_error(void)
{
	exit (-10);
}

void	ft_exit_message_1(int exit_code)
{
	if (exit_code == 1)
	{
		if (ft_printf("Message received successfully!\n") == -1)
			ft_print_error();
	}
	else if (exit_code == 0)
	{
		if (ft_printf("Enter the pid of the server and the message!\n") == -1)
			ft_print_error();
	}
	else if (exit_code == -1)
	{
		if (ft_printf("Fails to send SIGUSR1 signal!\n") == -1)
			ft_print_error();
	}
	else if (exit_code == -2)
	{
		if (ft_printf("Fails to send SIGUSR2!\n") == -1)
			ft_print_error();
	}
	else if (exit_code == -3)
	{
		if (ft_printf("Invalide pid!\n") == -1)
			ft_print_error();
	}
}

void	ft_exit_message_2(int exit_code)
{
	if (exit_code == -6)
	{
		if (ft_printf("Sigemptyset function failed!\n") == -1)
			ft_print_error();
	}
	else if (exit_code == -7)
	{
		if (ft_printf("Sigaction function failed!\n") == -1)
			ft_print_error();
	}
	else if (exit_code == -4)
	{
		if (ft_printf("Allocation failed!\n") == -1)
			ft_print_error();
	}
	else if (exit_code == -5)
	{
		if (ft_printf("Write function failed!\n") == -1)
			ft_print_error();
	}
}

void	ft_exit(int exit_code)
{
	if (exit_code <= 1 && exit_code >= -5)
		ft_exit_message_1(exit_code);
	else
		ft_exit_message_2(exit_code);
	exit (exit_code);
}
