/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:20:28 by yjaafar           #+#    #+#             */
/*   Updated: 2024/12/01 23:26:23 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, t_flags flags)
{
	int		i;
	char	*res;

	if (flags.width <= 1)
	{
		write(1, &c, 1);
		return (1);
	}
	res = (char *) malloc(flags.width);
	if (!res)
		return (-1);
	i = 0;
	while (i < flags.width)
		res[i++] = ' ';
	if (flags.left_justify)
		res[0] = c;
	else
		res[flags.width - 1] = c;
	write(1, res, flags.width);
	return (free(res), flags.width);
}
