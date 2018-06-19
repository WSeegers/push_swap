/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 12:36:24 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/19 13:02:23 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_print.h"
#include "s_stack.h"

void	print_stacks_line(t_stack *stk_a, t_stack *stk_b)
{
	if (stk_a)
	{
		for (size_t i = 0; i < stk_a->size; i++)
			f_printf("%ld-", stk_a->data[i]);
		f_printf("\t");
	}
	if (stk_b)
	{
		for (size_t i = 0; i < stk_b->size; i++)
			f_printf("%ld-", stk_b->data[i]);
		f_printf("\n");
	}
}
