/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:50:13 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 03:34:19 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"
#include "f_memory.h"

t_stack		*stack_create(void)
{
	t_stack *stack;

	stack = (t_stack*)f_memalloc(sizeof(*stack));
	stack_init(stack);
	return (stack);
}

