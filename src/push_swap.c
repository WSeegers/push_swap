/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 05:11:47 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/23 09:58:46 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "f_io.h"
#include "f_string.h"
#include "f_memory.h"

static void	print_rec(t_info *info, t_state *state)
{
	if (state->parent)
	{
		print_rec(info, state->parent);
		op_print(info, state->op);
	}
}

static void	brute_force(t_info *info)
{
	t_state *last_state;

	last_state = graph_search(info);
	print_rec(info, last_state);
}

static void	algo(t_info *info)
{
	rule_split(info);
	while (!stack_is_sorted(info->stk_a, 1))
	{
		rule_push_limit(info);
		op_print(info, "pb");
		if (TOP_B(info) < (info->count / 4 * 3) + (info->count / 4 / 2))
			op_print(info, "rb");
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
	if (stack_is_sorted(info->stk_a, 1))
		exit(0);
	if (info->count < 8)
		brute_force(info);
	else
		algo(info);
	exit(0);
}
