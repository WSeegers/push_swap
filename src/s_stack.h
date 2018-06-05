/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:45:29 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 05:08:32 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STACK_H
# define S_STACK_H

# include <stddef.h>

# define INIT_STACK_SIZE 8
# define DATA_SIZE (sizeof(long))

typedef struct	s_stack
{
	long	*data;
	size_t	size;
	size_t	cap;
}				t_stack;

t_stack			*stack_create(void);
void			stack_init(t_stack *stack);
void			stack_add(t_stack *stack, int nbr);
int				stack_pop(t_stack *stack, long *nbr);
void			stack_rot(t_stack *stack);
void			stack_rrot(t_stack *stack);
void			stack_swap(t_stack *stack);
void			stack_print(t_stack *stack);

#endif