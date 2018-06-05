/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 04:12:02 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 04:16:23 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

void			stack_swap(t_stack *stack)
{
	long	temp;

	if (stack->size < 2)
		return ;
	temp = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = temp;
}
