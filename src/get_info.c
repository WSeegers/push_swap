/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 22:34:51 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 10:28:55 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"
#include "f_memory.h"

t_info		*get_info(int ac, char **av)
{
	t_info	*info;

	info = f_memalloc(sizeof(*info));
	info->min = INT_MAX;
	info->max = INT_MIN;
	info->A = stack_create();
	get_numbers(info->A, av + 1, ac - 1);
	info->B = stack_create();
	info->count = ac - 1;
	info->limit = 0;
	return (info);
}
