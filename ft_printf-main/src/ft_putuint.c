/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:44:53 by yjaafar           #+#    #+#             */
/*   Updated: 2024/12/02 14:27:23 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_evo(unsigned int nb, int precision,
	int total_len, t_flags flags)
{
	int		i;
	char	*res;

	res = malloc(total_len);
	if (!res)
		return (NULL);
	if (flags.width > precision)
		i = ft_fill_with_padding(res, total_len, precision, flags);
	else
		i = precision - 1;
	while (precision--)
	{
		res[i--] = (nb % 10) + 48;
		nb /= 10;
	}
	return (res);
}

int	ft_putuint(unsigned int nb, t_flags flags)
{
	int		total_len;
	int		precision;
	char	*res;

	precision = ft_max(ft_unsigned_len(nb, 10), flags.precision);
	if (nb == 0 && flags.precision == -1)
		precision = 1;
	total_len = ft_max(precision, flags.width);
	if (flags.precision != -1 || flags.left_justify)
		flags.padding = ' ';
	res = ft_itoa_evo(nb, precision, total_len, flags);
	if (!res)
		return (-1);
	write(1, res, total_len);
	return (free(res), total_len);
}
