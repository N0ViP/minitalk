/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 09:24:38 by yjaafar           #+#    #+#             */
/*   Updated: 2024/12/03 00:48:59 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_sign(char *res, int nb, int i, t_flags flags)
{
	if (flags.padding == '0')
		i = 0;
	if (nb < 0)
		res[i] = '-';
	else
	{
		if (flags.sign_flag)
			res[i] = '+';
		else if (flags.space_flag)
			res[i] = ' ';
	}
}

static char	*ft_itoa_evo(int nb, int total_len, int precision, t_flags flags)
{
	char	*res;
	int		i;
	int		sign;
	int		tmp_nb;

	sign = (nb < 0 || flags.sign_flag || flags.space_flag);
	res = (char *) malloc(total_len);
	if (!res)
		return (NULL);
	tmp_nb = nb;
	if (flags.width > precision + sign)
		i = ft_fill_with_padding(res, total_len, precision, flags)
			+ (sign * flags.left_justify);
	else
		i = precision - 1 + sign;
	while (precision--)
	{
		res[i--] = ft_abs(tmp_nb % 10) + 48;
		tmp_nb /= 10;
	}
	ft_check_sign(res, nb, i, flags);
	return (res);
}

int	ft_putint(int nb, t_flags flags)
{
	int		total_len;
	int		sign;
	int		precision;
	char	*res;

	sign = (nb < 0 || flags.sign_flag || flags.space_flag);
	precision = ft_max(ft_numlen(nb), flags.precision);
	if (nb == 0 && flags.precision == -1)
		precision = 1;
	total_len = ft_max((precision + sign), flags.width);
	if (flags.precision != -1 || flags.left_justify)
		flags.padding = ' ';
	res = ft_itoa_evo(nb, total_len, precision, flags);
	if (!res)
		return (-1);
	write(1, res, total_len);
	return (free(res), total_len);
}
