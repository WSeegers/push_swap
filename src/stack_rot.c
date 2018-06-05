/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 03:35:23 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 03:43:34 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"
#include "f_memory.h"

void	stack_rot(t_stack *stack)
{
	long	temp;
	
	if (stack->size < 2)
		return ;
	temp = stack->data[0];
	f_memmove(stack->data, stack->data + 1, stack->size * DATA_SIZE);
	stack->data[stack->size - 1] = temp;
}

void	stack_rrot(t_stack *stack)
{
	long	temp;
	
	if (stack->size < 2)
		return ;
	temp = stack->data[stack->size - 1];
	f_memmove(stack->data + 1, stack->data, stack->size * DATA_SIZE);
	stack->data[0] = temp;
}
