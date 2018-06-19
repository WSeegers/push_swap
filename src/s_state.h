/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_state.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 21:54:59 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/19 07:44:33 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STATE_H
# define S_STATE_H

# include "s_stack.h"
# include "s_list.h"

typedef struct	s_state
{
	t_stack			*stk_a;
	t_stack			*stk_b;
	char 			op[4];
	struct s_state	*parent;
}				t_state;

t_state			*create_state(void);
t_state			*next_state(t_state *parent, char op[4]);
void			state_op(t_state *state, char *op);
bool 			state_equ(t_state *s1, t_state *s2);
void			excl_append_state(t_list *search_list, t_list *v_list,
																t_state *state);

#endif
