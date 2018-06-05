/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_back_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:44:25 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 22:57:20 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rule_back_stack(t_info *info)
{
	long max;

	max = info->B->size - 1;
	while (info->B->size)
	{
		if (info->B->data[0] != max)
			op_print(info, "rb");
		while (info->B->data[0] == max)
		{
			op_print(info, "pa");
			max--;
		}
	}
	return (0);
}
