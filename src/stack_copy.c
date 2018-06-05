/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 05:40:54 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 07:06:02 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

t_stack *stack_copy(t_stack *stack)
{
	t_stack	*cpy;
	int		i;

	cpy = stack_create();
	i = stack->size;
	while (--i >= 0)
		stack_add(cpy, stack->data[i]);
	return (cpy);
}
