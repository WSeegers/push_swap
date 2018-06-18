/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 05:34:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/18 12:15:49 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"
#include "f_memory.h"

void	rank_info(t_info *info)
{
	size_t	i;
	size_t	j;
	int		next[2];
	t_stack	*temp;

	i = -1;
	temp = stack_copy(info->A);
	while (++i < info->A->size && (j = -1))
	{
		next[1] = INT_MAX;
		while (++j < info->A->size)
		{
			if (temp->data[j] < next[1])
			{
				next[0] = j;
				next[1] = temp->data[j];
			}
		}
		info->A->data[next[0]] = i;
		temp->data[next[0]] = INT_MAX;
	}
	f_memdel((void**)&temp->data);
	f_memdel((void**)&temp);
}
