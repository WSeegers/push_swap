/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_cost.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 06:26:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/21 07:13:58 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "s_state.h"

int		h_cost(t_state *state)
{
	size_t		i;
	int		cost;
	
	cost = 0;
	i = -1;
	while (state->stk_a->size > 1 && ++i < state->stk_a->size - 1)
	{
		if (state->stk_a->data[i] > state->stk_a->data[i + 1])
			cost++;
	}
	i = -1;
	while (state->stk_b->size > 1 && ++i < state->stk_b->size - 1)
	{
		if (state->stk_b->data[i] < state->stk_b->data[i + 1])
			cost++;
	}
	return (cost);
}
