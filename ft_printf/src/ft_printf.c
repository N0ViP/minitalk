/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:13:59 by yjaafar           #+#    #+#             */
/*   Updated: 2024/12/03 16:48:28 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_get_flags(char **format, t_flags *flags)
{
	while (ft_strchr("#+ -0", **format))
	{
		if (**format == '#')
			flags->alternate_form = 1;
		else if (**format == '+')
			flags->sign_flag = 1;
		else if (**format == ' ')
			flags->space_flag = 1;
		else if (**format == '-')
			flags->left_justify = 1;
		else if (**format == '0')
			flags->padding = '0';
		(*format)++;
	}
}

static void	ft_get_width_precision(char **format, t_flags *flags)
{
	flags->width = ft_atoi(format);
	if (**format == '.')
	{
		(*format)++;
		flags->precision = ft_atoi(format);
	}
	if ((flags->width == -2) || (flags->precision == -2))
		*format = NULL;
}

static int	ft_get_flags_and_select_type(char **format, va_list args,
	int *check_last_per)
{
	int		count;
	t_flags	flags;

	flags = (t_flags){0, 0, 0, 0, -1, 0, 'b', ' '};
	ft_get_flags(format, &flags);
	ft_get_width_precision(format, &flags);
	if (!(*format) || (!(**format) && *check_last_per != 1))
		return (-1);
	if (ft_strchr("csiduxXp%", **format))
		count = ft_select_type(**format, args, flags);
	else
	{
		count = ft_theres_no_type(flags);
		*check_last_per = 1;
		(*format)--;
	}
	return (count);
}

static int	ft_vprintf(char *format, va_list args)
{
	int	count;
	int	i;
	int	tmp;
	int	check_last_per;

	count = 0;
	check_last_per = 0;
	while (*format)
	{
		i = ft_check_percentage(format);
		write(1, format, i);
		count += i;
		if (format[i] == '\0')
			return (count);
		format += i + 1;
		tmp = ft_get_flags_and_select_type(&format, args, &check_last_per);
		if (tmp == -1)
			return (-1);
		count += tmp;
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = ft_vprintf((char *) format, args);
	return (va_end(args), count);
}
