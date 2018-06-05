/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 22:36:57 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/05 03:34:37 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
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

static void	chk_nbr(char *nbr)
{
	while (*nbr)
	{
		if (*nbr == '-' || *nbr == '+')
			nbr++;
		if (!f_isdigit(*nbr))
			e_exit();
		nbr++;
	}
}

void	get_numbers(t_stack *stack, char **nbrs, int n)
{
	long nbr;

	while (--n >= 0)
	{
		chk_nbr(nbrs[n]);
		if ((nbr = f_strtol(nbrs[n], NULL, 10)) > INT_MAX || nbr < INT_MIN)
			e_exit();
		stack_add(stack, nbr);
	}
	chk_dup(stack);
}
