/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_equ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 21:09:37 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/23 05:05:39 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "s_stack.h"
#include "f_memory.h"

bool	stack_equ(t_stack *s1, t_stack *s2)
{
	if (s1->size != s2->size)
		return (false);
	if(f_memcmp(s1->data, s2->data, s1->size * sizeof(long)))
		return (false);
	return (true);
}
