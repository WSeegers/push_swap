/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 03:45:19 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 04:03:41 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "f_print.h"
#include "f_math.h"

void	print_stacks(t_info *info)
{
	size_t i;
	size_t max;

	i = -1;
	max = f_max(info->A->size, info->B->size);
	while (++i < max)
	{
		if (max - i <= info->A->size)
			f_print_nbr(info->A->data[i - (max - info->A->size)]);
		f_print_str("\t\t");
		if (max - i <= info->B->size)
			f_print_nbr(info->B->data[i - (max - info->B->size)]);
		f_print_str("\n");
	}
	f_print_str("___\t\t___\n");
	f_print_str(" A \t\t B \n");
}
