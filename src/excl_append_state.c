/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excl_append_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 07:21:46 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/19 08:16:06 by wseegers         ###   ########.fr       */
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
	if (!state)
		return ;
//	if (s_list_func_find(search_list, chk_state, state))
//		return ;
	//if (s_list_func_find(v_list, chk_state, state))
	//	return ;
	(void)v_list;
	(void)search_list;
	(void)chk_state;
	s_list_append(search_list, state);
}
