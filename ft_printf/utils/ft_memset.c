/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:18:02 by yjaafar           #+#    #+#             */
/*   Updated: 2024/12/01 13:11:57 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *res, int len, char c)
{
	size_t	padding;
	char	*ptr;
	int		size;

	padding = c * 0x0101010101010101;
	ptr = (char *)res;
	size = sizeof(size_t);
	while (len >= size)
	{
		*(size_t *) ptr = padding;
		ptr += size;
		len -= size;
	}
	while (len--)
		*(char *) ptr++ = c;
	return (res);
}
