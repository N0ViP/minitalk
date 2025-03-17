/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_with_padding.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:53:22 by yjaafar           #+#    #+#             */
/*   Updated: 2024/12/02 10:42:27 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fill_with_padding(char *res, int total_len, int precision, t_flags flags)
{
	int	start;
	int	end;
	int	i;

	start = 0;
	end = 0;
	i = 0;
	if (flags.left_justify)
	{
		start = precision;
		end = total_len;
		i = precision - 1;
	}
	else
	{
		start = 0;
		end = total_len - precision;
		i = total_len - 1;
	}
	res = (char *) ft_memset(res + start, end - start, flags.padding);
	return (i);
}
