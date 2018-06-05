/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 03:29:15 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 03:34:39 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"
#include "f_memory.h"

void	stack_init(t_stack *stack)
{
	if (stack->data)
		f_memdel((void**)&stack->data);
	stack->data = (long*)f_memalloc(INIT_STACK_SIZE * DATA_SIZE);
	stack->size = 0;
	stack->cap = INIT_STACK_SIZE;
}
