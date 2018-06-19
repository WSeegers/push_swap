/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excl_append_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 07:21:46 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/19 12:35:29 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "s_list.h"
#include "s_state.h"
#include "f_print.h"

static bool	chk_state(void *s1, void *s2)
{
	return (state_equ((t_state*)s1, (t_state*)s2));
}

void	excl_append_state(t_list *search_list, t_list *v_list, t_state *state)
{
	t_state *temp;

	if (!state)
		return ;
	if ((temp = s_list_func_find(search_list, chk_state, state)))
	{		
			/*f_printf("states equ ---> A: ");
			for (size_t i = 0; i < temp->stk_a->size; i++)
				f_printf("%ld-", temp->stk_a->data[i]);
			f_printf("[%ld]", temp->stk_a->size);
			f_printf("   B:");
			for (size_t i = 0; i < temp->stk_b->size; i++)
				f_printf("%ld-", temp->stk_b->data[i]);
			f_printf("   vs   A:");
			for (size_t i = 0; i < state->stk_a->size; i++)
				f_printf("%ld-", state->stk_a->data[i]);
			f_printf("   B:");
			for (size_t i = 0; i < state->stk_b->size; i++)
				f_printf("%ld-", state->stk_b->data[i]);
			f_printf("\n");*/
		return ;
	}
	if (s_list_func_find(v_list, chk_state, state))
		return ;
	s_list_append(search_list, state);
}
