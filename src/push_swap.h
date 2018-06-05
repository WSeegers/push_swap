/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 21:37:45 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 05:08:42 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "s_stack.h"
# include "f_print.h"

# define EMPTY LONG_MIN
# define OK f_print_str("OK\n")
# define KO f_print_str("KO\n")

typedef struct	s_info
{
	t_stack	*A;
	t_stack *B;
	int		count;
	int		min;
	int		max;
}				t_info;

t_info		*get_info(int ac, char **av);
void		get_numbers(t_stack *stack, char **nbrs, int n);
void		stack_ops(t_info *info, char *op);
void		print_stacks(t_info *info);
void		check_stacks(t_info *info);
void		e_exit();

#endif
