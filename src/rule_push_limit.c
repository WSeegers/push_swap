/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push_limit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:30:16 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 12:44:09 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

static long get_limit(t_info *info)
{
	size_t zero;
	long limit;
	size_t i;

	limit = 0;
	i = -1;
	zero = stack_find_rank(info->A, 0);
	while (++i < info->A->size)
	{
		if(info->A->data[(zero + i) % info->A->size] == (limit + 1))
			limit++;
	}
	return (limit);
}

int		rule_push_limit(t_info *info)
{
	int		ret;

	ret = 0;
	info->limit = get_limit(info);
	while (info->A->data[0] <= info->limit && !stack_is_sorted(info->A, 1))
	{
		op_print(info, "ra");
		ret = 1;
	}
	return (ret);
}
