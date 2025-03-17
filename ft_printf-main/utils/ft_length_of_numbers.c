/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_of_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:44:40 by yjaafar           #+#    #+#             */
/*   Updated: 2024/12/02 14:06:52 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_len(unsigned int nb, int base_size)
{
	int	i;

	i = 0;
	while (nb)
	{
		i++;
		nb /= base_size;
	}
	return (i);
}

int	ft_unsigned_ll_len(unsigned long long nb)
{
	int	i;

	i = 0;
	while (nb)
	{
		i++;
		nb /= 16;
	}
	return (i);
}

int	ft_numlen(int nb)
{
	int	i;

	i = 0;
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}
