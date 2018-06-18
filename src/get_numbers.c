/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 22:36:57 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/18 22:36:59 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include "push_swap.h"
#include "f_memory.h"
#include "f_string.h"

static void	chk_dup(t_stack *stack)
{
	size_t i;
	size_t j;

	i = -1;
	while (++i < stack->size + 1)
	{
		j = i;
		while (++j < stack->size)
			if (stack->data[i] == stack->data[j])
				e_exit();
	}
}

static char	*chk_nbr(char *nbr)
{
	while (*nbr)
	{
		while (*nbr == ' ')
			nbr++;
		if (*nbr == '-' || *nbr == '+')
			nbr++;
		if (!f_isdigit(*nbr))
			e_exit();
		nbr++;
	}
	return (nbr);
}

static bool	get_flag(t_info *info, char *arg)
{
	if (arg[0] != '-')
		return (false);
	while (*++arg)
	{
		if (*arg == 'v')
			SET_FLAG(info->flag, F_VBOSE);
		else if (*arg == 'c')
		{
			SET_FLAG(info->flag, F_COLOUR);
			SET_FLAG(info->flag, F_VBOSE);
		}
	}
	return (true);
}

void		get_numbers(t_info *info, char **nbrs, int n)
{
	long nbr;
	char *temp;

	while (--n >= 0)
	{
		if (get_flag(info, nbrs[n]))
			continue;
		chk_nbr(nbrs[n]);
		if ((nbr = f_strtol(nbrs[n], NULL, 10)) > INT_MAX || nbr < INT_MIN)
			e_exit();
		stack_add(info->stk_a, nbr);
		temp = f_strchr(nbrs[n], ' ');
		while (temp)
		{
			chk_nbr(temp);
			if ((nbr = f_strtol(temp, NULL, 10)) > INT_MAX || nbr < INT_MIN)
				e_exit();
			stack_add_back(info->stk_a, nbr);
			temp = f_strchr(temp + 1, ' ');
		}
	}
	chk_dup(info->stk_a);
}
