/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 05:11:47 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/19 16:52:58 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "push_swap.h"
#include "f_io.h"
#include "f_string.h"
#include "f_memory.h"
#include "s_list.h"
#include "s_state.h"
#include "f_print.h"

# define TOP_A(info) (info->stk_a->data[0])
# define SEC_A(info) (info->stk_a->data[1])
# define TOP_B(info) (info->stk_b->data[0])
# define SEC_B(info) (info->stk_b->data[1])

void	push_swap(t_info *info)
{
	int range;
	int i;

	range = info->limit / 4;
	i = -1;
	while (++i < info->limit)
	{
		if (TOP_A(info) < range)
		{
			op_print(info, "ra");
		}
		else if (TOP_A(info) < range * 2 + (info->limit % 4 == 3))
		{
			op_print(info, "pb");
			op_print(info, "rb");
		}
		else if (TOP_A(info) < range * 3 + (info->limit % 4 == 3) + (info->limit % 4 >= 2))
			op_print(info, "pb");
		else
			op_print(info, "ra");
		print_stacks_line(info->stk_a, info->stk_b);
	}
	while (info->stk_a->size)
	{
		op_print(info, "pb");
		if (TOP_B(info) < range * 2)
			op_print(info, "rb");
		print_stacks_line(info->stk_a, info->stk_b);
	}

	while (info->stk_b->size)
		op_print(info, "pa");
	print_stacks_line(info->stk_a, info->stk_b);

	int j = 0;
	range = info->limit / 4 / 4;
	i = -1;
	while (++i < info->limit / 4)
	{
		if (TOP_A(info) < range)
		{
			j++;
			op_print(info, "ra");
		}
		else if (TOP_A(info) < range * 2 + (info->limit % 4 == 3))
		{
			op_print(info, "pb");
			op_print(info, "rb");
		}
		else if (TOP_A(info) < range * 3 + (info->limit % 4 == 3) + (info->limit % 4 >= 2))
			op_print(info, "pb");
		else
		{
			j++;
			op_print(info, "ra");
		}
		print_stacks_line(info->stk_a, info->stk_b);
	}
	while (j)
	{
		op_print(info, "rra");
		op_print(info, "pb");
		if (TOP_B(info) < range * 2)
			op_print(info, "rb");
		print_stacks_line(info->stk_a, info->stk_b);
		j--;
	}
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
