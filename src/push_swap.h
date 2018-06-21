/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 21:37:45 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/21 20:15:57 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include "s_stack.h"
# include "f_print.h"

# define EMPTY LONG_MIN
# define OK f_print_str("OK\n")
# define KO f_print_str("KO\n")

# define SET_FLAG(flag, n) (flag = (flag | (1 << n)))
# define IS_FLAG_SET(flag, n) (flag & (1 << n))

# define F_VBOSE 0
# define F_COLOUR 1

# define TOP_A(info) (info->stk_a->data[0])
# define SEC_A(info) (info->stk_a->data[1])
# define TOP_B(info) (info->stk_b->data[0])
# define SEC_B(info) (info->stk_b->data[1])

typedef struct	s_info
{
	t_stack	*stk_a;
	t_stack *stk_b;
	int		flag;
	int		count;
	int		min;
	int		max;
	long	limit;
}				t_info;

t_info			*get_info(int ac, char **av);
void			get_numbers(t_info *info, char **nbrs, int n);
void			stack_ops(t_info *info, char *op);
void			print_stacks(t_info *info, char *instruction);
void			check_stacks(t_info *info);
void			rank_info(t_info *info);
int				op_print(t_info *info, char op[4]);
size_t			stack_find_rank(t_stack *stack, long n);
void			e_exit();

int				rule_push_limit(t_info *info);
int				rule_top_swap(t_info *info);
int				rule_back_stack(t_info *info);
void			rule_final_order(t_info *info);

#endif
