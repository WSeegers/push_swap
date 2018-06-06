/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 06:13:51 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 23:18:59 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

static int	ascending(t_stack *stack)
{
	size_t i;

	if (stack->size <= 1)
		return (1);
	else
	{
		i = -1;
		while (++i + 1 < stack->size)
			if (stack->data[i] != stack->data[i + 1] - 1)
				return (0);
		return (1);
	}
}

static int	descending(t_stack *stack)
{
	size_t i;

	if (stack->size <= 1)
		return (1);
	else
	{
		i = -1;
		while (++i + 1 < stack->size)
			if (stack->data[i] != stack->data[i + 1] + 1)
				return (0);
		return (1);
	}
}

int			stack_is_sorted(t_stack *stack, int direction)
{
	if (direction >= 0)
		return (ascending(stack));
	else
		return (descending(stack));
}
