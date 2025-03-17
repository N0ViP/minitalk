/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:00:37 by yjaafar           #+#    #+#             */
/*   Updated: 2024/12/03 10:42:31 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_res(char *res, char *str, int str_len, t_flags flags)
{
	int	i;
	int	precision;

	i = 0;
	flags.padding = ' ';
	if (flags.precision != -1)
		precision = ft_min(flags.precision, str_len);
	else
		precision = str_len;
	i = ft_fill_with_padding(res, flags.width, precision, flags);
	while (str_len--)
		res[i--] = str[str_len];
	write(1, res, flags.width);
}

int	ft_putstr(char *str, t_flags flags)
{
	int		str_len;
	char	*res;

	if (!str)
	{
		if (flags.precision < 6 && flags.precision != -1)
			str = "";
		else
			str = "(null)";
	}
	str_len = ft_strlen(str);
	if (flags.precision < str_len && flags.precision != -1)
		str_len = flags.precision;
	if (flags.width <= str_len)
	{
		write(1, str, str_len);
		return (str_len);
	}
	res = (char *) malloc(flags.width);
	if (!res)
		return (-1);
	ft_print_res(res, str, str_len, flags);
	return (free(res), flags.width);
}
