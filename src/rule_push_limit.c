/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push_limit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:30:16 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/18 12:48:55 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	get_limit(t_info *info)
{
	size_t	max;
	long	limit;
	size_t	i;

	limit = info->count - 1;
	i = -1;
	max = stack_find_rank(info->A, info->count - 1);
	while (++i < info->A->size)
	{
		if (info->A->data[(max - i) % info->A->size] == (limit - 1))
			limit--;
	}
	return (limit);
}

int			rule_push_limit(t_info *info)
{
	int		ret;

	ret = 0;
	info->limit = get_limit(info);
	while (info->A->data[0] >= info->limit && !stack_is_sorted(info->A, 1))
	{
		op_print(info, "ra");
		ret = 1;
	}
	return (ret);
}
