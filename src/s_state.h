/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_state.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 21:54:59 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/18 22:43:38 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STATE_H
# define S_STATE_H

# include "s_stack.h"

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

#endif
