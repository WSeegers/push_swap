/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 05:11:47 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 13:51:51 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "push_swap.h"
#include "f_io.h"
#include "f_string.h"
#include "f_memory.h"

static void	push_swap(t_info *info)
{
	while (!stack_is_sorted(info->A, 1))
	{
		rule_push_limit(info);
		if(rule_top_swap(info))
			continue ;
		else if (!stack_is_sorted(info->A, 1))
			op_print(info, "pb");
	}
	rule_back_stack(info);
	rule_final_order(info);
}

int		main(int ac, char *av[])
{
	t_info *info;

	if (ac == 1)
		exit(0);
	info = get_info(ac, av);
	rank_info(info);
	print_stacks(info);
	rule_push_limit(info);
	push_swap(info);
	exit(0);
}
