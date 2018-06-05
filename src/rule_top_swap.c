/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_top_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:06:21 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 11:41:34 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rule_top_swap(t_info *info)
{
	if (info->A->data[0] ==	info->A->data[1] + 1)
	{
		if (info->A->size > 2 && info->A->data[1] == info->A->data[2] + 1)
		{
			op_print(info, "pb");
			op_print(info, "sa");
			op_print(info, "ra");
			op_print(info, "ra");
			return (op_print(info, "pa"));
		}
		else if (info->B->data[1] == info->B->data[0] + 1)
		{
			if (info->B->size > 2 && info->B->data[2] == info->B->data[1] + 1)
			{
				op_print(info, "pa");
				op_print(info, "sb");
				op_print(info, "rb");
				op_print(info, "rb");
				return (op_print(info, "pb"));
			}
			else
				return (op_print(info, "ss"));
		}
		else
			return (op_print(info, "sa"));
	}
	else if (info->B->data[1] == info->B->data[0] + 1)
			return (op_print(info, "sb"));
	return (0);
}
