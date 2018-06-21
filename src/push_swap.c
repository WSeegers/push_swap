/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 05:11:47 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/21 20:57:41 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "push_swap.h"
#include "f_io.h"
#include "f_string.h"
#include "f_memory.h"

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
	algo(info);
	exit(0);
}
