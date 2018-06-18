/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 22:00:10 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/18 22:59:44 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_state.h"
#include "f_string.h"

t_state			*next_state(t_state *parent, char op[4])
{
	t_state *new_state;
	
	new_state = create_state();
	new_state->parent = parent;
	new_state->stk_a = stack_copy(parent->stk_a);
	new_state->stk_b = stack_copy(parent->stk_b);
	f_strcpy(new_state->op, op);
	state_op(new_state, op);
	return (new_state);
}
