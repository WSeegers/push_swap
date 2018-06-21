/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 04:55:10 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/18 13:05:47 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "f_print.h"

void	check_stacks(t_info *info)
{
	size_t i;

	if (!info->stk_b->size && info->stk_a->size == 1)
		OK;
	else if (info->stk_b->size)
		KO;
	else
	{
		i = -1;
		while (++i + 1 < info->stk_a->size)
			if (info->stk_a->data[i] > info->stk_a->data[i + 1])
			{
				KO;
				return ;
			}
		OK;
	}
}
