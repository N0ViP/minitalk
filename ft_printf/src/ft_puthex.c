/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:09:38 by yjaafar           #+#    #+#             */
/*   Updated: 2024/12/02 14:43:40 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_get_alternate_form(char *res, int i, t_flags flags)
{
	if (flags.base == 'x')
		res[i--] = 'x';
	else
		res[i--] = 'X';
	res[i] = '0';
}

static char	*ft_itoa_evo(unsigned int nb, int total_len,
	int precision, t_flags flags)
{
	char	*res;
	char	*base;
	int		alternate;
	int		i;

	res = (char *) malloc(total_len);
	if (!res)
		return (NULL);
	if (flags.base == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	alternate = 2 * (flags.alternate_form && nb != 0);
	if (flags.width > precision + alternate)
		i = ft_fill_with_padding(res, total_len, precision + alternate, flags);
	else
		i = precision - 1 + alternate;
	while (precision--)
	{
		res[i--] = base[nb % 16];
		nb /= 16;
	}
	if (alternate)
		ft_get_alternate_form(res, i, flags);
	return (res);
}

int	ft_puthex(unsigned int nb, t_flags flags)
{
	int		total_len;
	int		precision;
	int		alternate;
	char	*res;

	alternate = 2 * (flags.alternate_form && nb != 0);
	precision = ft_max(ft_unsigned_len(nb, 16), flags.precision);
	if (nb == 0 && flags.precision == -1)
		precision = 1;
	total_len = ft_max((precision + alternate), flags.width);
	if (flags.precision != -1 || flags.left_justify)
		flags.padding = ' ';
	res = ft_itoa_evo(nb, total_len, precision, flags);
	if (!res)
		return (-1);
	write(1, res, total_len);
	return (free(res), total_len);
}
