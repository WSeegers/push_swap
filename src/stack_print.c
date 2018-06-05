/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 03:25:36 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 03:26:23 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"
#include "f_print.h"

void	stack_print(t_stack *stack)
{
	size_t	count;

	count = -1;
	f_print_str("___\n\n");
	while (++count < stack->size)
	{
		f_print_nbr(stack->data[count]);
		f_print_str("\n");
	}
	f_print_str("___\n");
}
