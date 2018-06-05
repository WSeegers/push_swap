/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find_rank.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:44:59 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 11:17:03 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

size_t stack_find_rank(t_stack *stack, long n)
{
	size_t i;

	i = -1;
	while (++i < stack->size)
	{
		if (stack->data[i] == n)
			return (i);
	}
	return (-1);
}
