/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 09:58:45 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/18 12:09:19 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "f_print.h"
#include "f_memory.h"

int	op_print(t_info *info, char op[4])
{
	f_print_str(op);
	f_print_str("\n");
	stack_ops(info, op);
	if (IS_FLAG_SET(info->flag, F_VBOSE))
		print_stacks(info, op);
	return (1);
}
