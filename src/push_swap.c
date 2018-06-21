/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 05:11:47 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/21 18:08:39 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "push_swap.h"
#include "f_io.h"
#include "f_string.h"
#include "f_memory.h"

# define TOP_A(info) (info->stk_a->data[0])
# define SEC_A(info) (info->stk_a->data[1])
# define TOP_B(info) (info->stk_b->data[0])
# define SEC_B(info) (info->stk_b->data[1])



static void	push_swap(t_info *info)
{
	int range;
	int i;

	i = info->count + 1 + info->count % 4;
	range = info->count / 4;
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
	i = info->count - (range * 2 - range);
	while (--i)
	{
		if (TOP_A(info) < range * 3)
			op_print(info, "pb");
		else
			op_print(info, "ra");

	}
	while (!stack_is_sorted(info->stk_a, 1))
	{
		rule_push_limit(info);
		op_print(info, "pb");
	}
	rule_back_stack(info);
}

int			main(int ac, char *av[])
{
	t_info *info;

	if (ac == 1)
		exit(0);
	info = get_info(ac, av);
	rank_info(info);
	push_swap(info);
	exit(0);
}
