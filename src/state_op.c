/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 21:08:14 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/21 21:08:17 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "s_state.h"

static void	swap(t_state *state, int op)
{
	if (op == 's')
	{
		swap(state, 'a');
		swap(state, 'b');
	}
	else if (op == 'a')
		stack_swap(state->stk_a);
	else if (op == 'b')
		stack_swap(state->stk_b);
	else
		e_exit();
}

static void	push(t_state *state, int op)
{
	long nbr;

	if (op == 'a' && stack_pop(state->stk_b, &nbr))
		stack_add(state->stk_a, nbr);
	else if (op == 'b' && stack_pop(state->stk_a, &nbr))
		stack_add(state->stk_b, nbr);
	else if (op != 'a' && op != 'b')
		e_exit();
}

static void	rot(t_state *state, char op)
{
	if (op == 'r')
	{
		rot(state, 'a');
		rot(state, 'b');
	}
	else if (op == 'a')
		stack_rot(state->stk_a);
	else if (op == 'b')
		stack_rot(state->stk_b);
	else
		e_exit();
}

static void	rrot(t_state *state, char op)
{
	if (op == 'r')
	{
		rrot(state, 'a');
		rrot(state, 'b');
	}
	else if (op == 'a')
		stack_rrot(state->stk_a);
	else if (op == 'b')
		stack_rrot(state->stk_b);
	else
		e_exit();
}

void		state_op(t_state *state, char *op)
{
	if (*op == 's' && !op[2])
		swap(state, op[1]);
	else if (*op == 'p' && !op[2])
		push(state, op[1]);
	else if (*op == 'r' && !op[2])
		rot(state, op[1]);
	else if (*op == 'r' && op[1] == 'r' && !op[3])
		rrot(state, op[2]);
	else
		e_exit();
}
