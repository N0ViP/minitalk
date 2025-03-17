/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:51:09 by yjaafar           #+#    #+#             */
/*   Updated: 2024/12/03 10:00:43 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_percentage(char *format)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			return (i);
		i++;
	}
	return (i);
}

int	ft_select_type(char c, va_list args, t_flags flags)
{
	int	count;

	if (c == 'c')
		count = ft_putchar(va_arg(args, int), flags);
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *), flags);
	else if (c == 'i' || c == 'd')
		count = ft_putint(va_arg(args, int), flags);
	else if (c == 'x' || c == 'X')
	{
		flags.base = c;
		count = ft_puthex(va_arg(args, unsigned int), flags);
	}
	else if (c == 'u')
		count = ft_putuint(va_arg(args, unsigned int), flags);
	else if (c == 'p')
		count = ft_putptr((unsigned long long) va_arg(args, void *), flags);
	else
	{
		count = 1;
		write(1, "%", 1);
	}
	return (count);
}

int	ft_theres_no_type(t_flags flags)
{
	int	flags_len;
	int	width_precision_len;

	write(1, "%", 1);
	flags_len = ft_print_flags(flags);
	width_precision_len = ft_print_width_precision(flags);
	if (width_precision_len == -1)
		return (-1);
	return (flags_len + width_precision_len);
}

int	ft_print_flags(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.alternate_form)
	{
		count++;
		write(1, "#", 1);
	}
	if (flags.sign_flag || flags.space_flag)
	{
		count++;
		if (flags.sign_flag)
			write(1, "+", 1);
		else
			write (1, " ", 1);
	}
	if (flags.left_justify || flags.padding == '0')
	{
		count++;
		if (flags.left_justify)
			write(1, "-", 1);
		else
			write(1, "0", 1);
	}
	return (count);
}

int	ft_print_width_precision(t_flags flags)
{
	int		width_len;
	int		precision_len;
	t_flags	initial;

	width_len = 0;
	precision_len = 0;
	initial = (t_flags){0, 0, 0, 0, -1, 0, 'b', ' '};
	if (flags.width != 0)
		width_len = ft_putint(flags.width, initial);
	if (width_len == -1)
		return (-1);
	if (flags.precision != -1)
	{
		write(1, ".", 1);
		precision_len = ft_putint(flags.precision, initial);
		if (precision_len == -1)
			return (-1);
		precision_len += 1;
	}
	return (width_len + precision_len);
}
