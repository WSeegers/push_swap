/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 03:27:16 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 03:27:42 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"
#include "f_memory.h"

int		stack_pop(t_stack *stack, long *nbr)
{
	if (!(stack->size))
		return (0);
	*nbr = stack->data[0];
	f_memmove(stack->data, stack->data + 1, stack->size * DATA_SIZE);
	stack->size--;
	return (1);
}
