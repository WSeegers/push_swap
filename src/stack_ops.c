/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 23:03:51 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/03 23:56:09 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stacks stacks, int op)
{
	int		*stack;
	int		top;

	if (op == 's')
	{
		if (stack->acount > 1)
			swap(stacks, 'a');
		if (stack->bcount > 1)
			swap(stacks, 'b');
	}
	else
	{
		if (op == 'a')
			stack = stacks->A;
		else if (op == 'b')
			stack = stacks->B;
		else
			e_exit();
	}
	i = 0;
	while (stack[top] == EMPTY)
		top++;
	op = stack[top];
	stack[top] = stack[top + 1];
	stack[top + 1] = op;
}

static void push(t_stacks, int op)
{
	int		popped;

	if (op != 'a' && op != 'b')
		e_exit();
	else if (op == 'a' && stacks->acount > 0)
	{
		stack->B[stack->total - stack->bcount] = 
			stack->A[stack->total - stack->acount];
		stack->A[stack->total - stack->acount] = EMPTY;
	}
	else if (op == 'a' && stacks->bcount > 0)
	{
		stack->A[stack->total - stack->acount] = 
			stack->b[stack->total - stack->bcount];
		stack->b[stack->total - stack->bcount] = EMPTY;
	}
}

void	stack_ops(t_stacks stacks, char *op)
{
	if (*op == 's')
		swap(stacks, op[1]);
	else if (*op == 'p')
		push(stacks, op[1]);
	else if (*op == 'r' && op[1] != 'r')
		rot(stacks, op[1]);
	else if (*op == 'r' && op[1] == 'r')
		rotr(stacks, op[2])
	else
		e_exit();
}
