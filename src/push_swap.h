/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 21:37:45 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/03 22:52:05 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_stacks
{
	int		*A;
	int		acount;
	int		*B;
	int		bcount;
	int		min;
	int		max;
}				t_stacks;

t_stacks	*init_stacks(int ac, char **av);
int			*get_numbers(t_stacks *stacks, char **nbrs, int n);
void		has_dup(t_stacks *stacks);
void		e_exit();

#endif
