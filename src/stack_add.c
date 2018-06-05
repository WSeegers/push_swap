/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 03:28:18 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 13:48:29 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"
#include "f_memory.h"

void	stack_add(t_stack *stack, int nbr)
{
	long *new_mem;

	if (stack->size == stack->cap)
	{
		new_mem = (long*)f_memalloc((stack->cap *= 2) * DATA_SIZE);
		f_memcpy(new_mem, stack->data, stack->cap / 2 * DATA_SIZE);
		stack->data = new_mem;
	}
	f_memmove(stack->data + 1, stack->data, stack->size * DATA_SIZE);
	stack->data[0] = nbr;
	stack->size++;
}

void	stack_add_back(t_stack *stack, int nbr)
{
	long *new_mem;

	if (stack->size == stack->cap)
	{
		new_mem = (long*)f_memalloc((stack->cap *= 2) * DATA_SIZE);
		f_memcpy(new_mem, stack->data, stack->cap / 2 * DATA_SIZE);
		stack->data = new_mem;
	}
	stack->data[stack->size] = nbr;
	stack->size++;
}
