/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_equ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 07:14:29 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/19 07:20:49 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "s_state.h"
#include "s_stack.h"

bool state_equ(t_state *s1, t_state *s2)
{
	if (stack_equ(s1->stk_a, s2->stk_a) &&
		stack_equ(s1->stk_a, s2->stk_a))
		return (true);
	return (false);
}
