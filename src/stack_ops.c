/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 23:03:51 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/18 13:05:28 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_info *info, int op)
{
	if (op == 's')
	{
		swap(info, 'a');
		swap(info, 'b');
	}
	else if (op == 'a')
		stack_swap(info->stk_a);
	else if (op == 'b')
		stack_swap(info->stk_b);
	else
		e_exit();
}

static void	push(t_info *info, int op)
{
	long nbr;

	if (op == 'a' && stack_pop(info->stk_b, &nbr))
		stack_add(info->stk_a, nbr);
	else if (op == 'b' && stack_pop(info->stk_a, &nbr))
		stack_add(info->stk_b, nbr);
	else if (op != 'a' && op != 'b')
		e_exit();
}

static void	rot(t_info *info, char op)
{
	if (op == 'r')
	{
		rot(info, 'a');
		rot(info, 'b');
	}
	else if (op == 'a')
		stack_rot(info->stk_a);
	else if (op == 'b')
		stack_rot(info->stk_b);
	else
		e_exit();
}

static void	rrot(t_info *info, char op)
{
	if (op == 'r')
	{
		rrot(info, 'a');
		rrot(info, 'b');
	}
	else if (op == 'a')
		stack_rrot(info->stk_a);
	else if (op == 'b')
		stack_rrot(info->stk_b);
	else
		e_exit();
}

void		stack_ops(t_info *info, char *op)
{
	if (*op == 's' && !op[2])
		swap(info, op[1]);
	else if (*op == 'p' && !op[2])
		push(info, op[1]);
	else if (*op == 'r' && !op[2])
		rot(info, op[1]);
	else if (*op == 'r' && op[1] == 'r' && !op[3])
		rrot(info, op[2]);
	else
		e_exit();
}
