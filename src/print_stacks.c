/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 03:45:19 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/18 12:08:18 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "f_print.h"
#include "f_math.h"
#include "colours.h"
#include "f_string.h"

static void	set_colour(char *instruct, size_t i, size_t max, char stack)
{
	(void)max;
	if (i == 0)
	{
		if (stack == 'A' && (!f_strcmp(instruct, "sa") ||
			!f_strcmp(instruct, "pa") || !f_strcmp(instruct, "rra") ||
			!f_strcmp(instruct, "rrr")))
			f_print_err(COL_GREEN);
		else if (stack == 'B' && (!f_strcmp(instruct, "sb") ||
			!f_strcmp(instruct, "pb") || !f_strcmp(instruct, "rrb") ||
			!f_strcmp(instruct, "rrr")))
			f_print_err(COL_GREEN);
	}
	else if (i == 1 && stack == 'A' && !f_strcmp(instruct, "sa"))
		f_print_err(COL_GREEN);
	else if (i == 1 && stack == 'B' && !f_strcmp(instruct, "sb"))
		f_print_err(COL_GREEN);
	else if (i == max - 1)
	{
		if (stack == 'A' && !f_strcmp(instruct, "ra"))
			f_print_err(COL_GREEN);
		else if (stack == 'B' && !f_strcmp(instruct, "rb"))
			f_print_err(COL_GREEN);
	}
}

void		print_stacks(t_info *info, char *instruct)
{
	size_t i;
	size_t max;

	i = -1;
	max = f_max(info->A->size, info->B->size);
	while (++i < max)
	{
		if (IS_FLAG_SET(info->flag, F_COLOUR))
			set_colour(instruct, i - (max - info->A->size), info->A->size, 'A');
		if (max - i <= info->A->size)
			f_print_nbr_fd(2, info->A->data[i - (max - info->A->size)]);
		f_print_err("\t\t");
		f_print_err(COL_CLEAR);
		if (IS_FLAG_SET(info->flag, F_COLOUR))
			set_colour(instruct, i - (max - info->B->size), info->B->size, 'B');
		if (max - i <= info->B->size)
			f_print_nbr_fd(2, info->B->data[i - (max - info->B->size)]);
		f_print_err("\n");
		f_print_err(COL_CLEAR);
	}
	f_print_err("_____\t\t_____\n");
	f_print_err("  A  \t\t  B  \n\n");
}
