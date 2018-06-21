/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 05:11:47 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/21 06:45:13 by wseegers         ###   ########.fr       */
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


int			main(int ac, char *av[])
{
	t_info *info;

	if (ac == 1)
		exit(0);
	info = get_info(ac, av);
	rank_info(info);
	info->max = info->stk_a->size - 1;
	
	t_state *cur = graph_search(info);
	while (cur)
	{
		f_printf("op: %s  \t", cur->op);
		print_stacks_line(cur->stk_a, cur->stk_b);
		cur = cur->parent;
	}

	exit(0);
}
