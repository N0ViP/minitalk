/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 09:20:27 by yjaafar           #+#    #+#             */
/*   Updated: 2025/03/23 09:56:16 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	add_node_back(int n, t_client **client, t_client *node)
{
	static t_client	*ptr;

	if (n == 0 && ptr)
	{
		ptr->next = node;
		ptr = ptr->next;
	}
	else if (n == 0 && !ptr)
	{
		*client = node;
		ptr = node;
	}
	else if (n == 1 && !node)
	{
		ptr = 0;
	}
}
