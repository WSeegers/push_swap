/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 04:55:10 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 05:09:53 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "f_print.h"

void	check_stacks(t_info *info)
{
	size_t i;

	if (!info->B->size && info->A->size == 1)
		OK;
	else if (info->B->size)
		KO;
	else
	{
		i = -1;
		while (++i + 1 < info->A->size)
			if (info->A->data[i] > info->A->data[i + 1])
			{
				KO;
				return ;
			}
		OK;
	}
}
