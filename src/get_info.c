/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 22:34:51 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/21 16:35:09 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"
#include "f_memory.h"

t_info		*get_info(int ac, char **av)
{
	t_info	*info;

	info = f_memalloc(sizeof(*info));
	info->min = 0;
	info->max = INT_MIN;
	info->stk_a = stack_create();
	info->flag = 0;
	get_numbers(info, av + 1, ac - 1);
	info->stk_b = stack_create();
	info->count = info->stk_a->size;
	info->limit = 0;
	return (info);
}
