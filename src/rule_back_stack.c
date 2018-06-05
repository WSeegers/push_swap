/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_back_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:44:25 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 22:37:44 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rule_back_stack(t_info *info)
{
	long count;

	count = info->count - 1;
	while (info->B->size)
	{
		if (info->B->data[0] != count)
			op_print(info, "rb");
		while (info->B->data[0] == count)
		{
			op_print(info, "pa");
			count--;
		}
	}
	return (0);
}
