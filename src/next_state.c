/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 21:04:35 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/23 09:56:18 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_state.h"
#include "f_string.h"
#include "s_stack.h"

t_state	*next_state(t_state *parent, char op[4])
{
	t_state *new_state;

	new_state = create_state();
	new_state->parent = parent;
	new_state->stk_a = stack_copy(parent->stk_a);
	new_state->stk_b = stack_copy(parent->stk_b);
	f_strcpy(new_state->op, op);
	state_op(new_state, op);
	if (state_equ(new_state, parent))
		return (NULL);
	return (new_state);
}
