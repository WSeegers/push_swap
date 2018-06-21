/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 20:49:07 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/21 20:57:15 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	re_split(t_info *info, int range)
{
	while (TOP_B(info) >= range)
	{
		if (TOP_B(info) < range + (range / 2))
			op_print(info, "rb");
		else
			op_print(info, "pa");
	}
	while (TOP_B(info) < range)
	{
		if (TOP_B(info) < range / 2)
			op_print(info, "pa");
		else
			op_print(info, "rb");
	}
	while (TOP_A(info) < range * 2)
		op_print(info, "pb");
}

static void split_bot(t_info *info, int range)
{
	int i;

	i = info->count + 1;
	while (--i)
	{
		if (TOP_A(info) < range * 2)
		{
			op_print(info, "pb");
			if (TOP_B(info) < range)
				op_print(info, "rb");
		}
		else 
			op_print(info, "ra");
	}

}

static void	split_top(t_info *info, int range)
{
	int i;

	i = info->count - (range * 2 - range);
	while (--i)
	{
		if (TOP_A(info) < range * 3)
		{
			op_print(info, "pb");
			if (TOP_B(info) < range * 3 - range / 2)
				op_print(info, "rb");
		}
		else
			op_print(info, "ra");
	}
}
void	rule_split(t_info *info)
{
	int range;

	range = info->count / 4;
	split_bot(info, range);
	re_split(info, range);
	split_top(info, range);
}
