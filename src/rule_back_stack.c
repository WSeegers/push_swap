/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_back_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:44:25 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/18 11:51:38 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max(long *data, long max)
{
	int ret;

	ret = -1;
	while (data[ret] != max)
		ret++;
	return (ret);
}

int		rule_back_stack(t_info *info)
{
	long max;

	max = info->B->size - 1;
	while (info->B->size)
	{
		while (info->B->data[0] == max)
		{
			op_print(info, "pa");
			max--;
		}
		if (info->B->size)
		{
			if (find_max(info->B->data, max) < max / 2)
				op_print(info, "rb");
			else
				op_print(info, "rrb");
		}
	}
	return (0);
}
