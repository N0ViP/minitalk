/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:00:14 by yjaafar           #+#    #+#             */
/*   Updated: 2024/12/02 23:42:14 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_sign_flag(char *res, int i, int sign, t_flags flags)
{
	if (flags.padding == '0')
		i = 0;
	else
		i -= 2 + sign;
	if (flags.sign_flag)
		res[i++] = '+';
	else if (flags.space_flag)
		res[i++] = ' ';
	res[i++] = '0';
	res[i] = 'x';
}

static char	*ft_itoa_evo(unsigned long long nb,
	int total_len, int precision, t_flags flags)
{
	int		i;
	int		sign;
	char	*res;

	res = (char *) malloc(total_len);
	if (!res)
		return (NULL);
	sign = (flags.sign_flag || flags.space_flag);
	if (flags.width > precision + 2 + sign)
		i = ft_fill_with_padding(res, total_len, precision, flags)
			+ ((2 + sign) * (flags.left_justify));
	else
		i = precision + 1 + sign;
	while (precision--)
	{
		res[i--] = "0123456789abcdef"[nb % 16];
		nb /= 16;
	}
	ft_check_sign_flag(res, i + 1, sign, flags);
	return (res);
}

int	ft_putptr(unsigned long long nb, t_flags flags)
{
	int		total_len;
	int		precision;
	int		sign;
	char	*res;

	if (nb == 0)
	{
		flags.precision = -1;
		return (ft_putstr("(nil)", flags));
	}
	sign = (flags.sign_flag || flags.space_flag);
	precision = ft_max(ft_unsigned_ll_len(nb), flags.precision);
	total_len = ft_max(precision + 2 + sign, flags.width);
	if (flags.precision != -1 || flags.left_justify)
		flags.padding = ' ';
	res = ft_itoa_evo(nb, total_len, precision, flags);
	if (!res)
		return (-1);
	write(1, res, total_len);
	return (free(res), total_len);
}
