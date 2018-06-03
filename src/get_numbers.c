/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 22:36:57 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/03 22:40:30 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"
#include "f_memory.h"
#include "f_string.h"
#include "f_math.h"

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

int			*get_numbers(t_stacks *stacks, char **nbrs, int n) 
{
	int *ret;
	long nbr;

	ret = f_memalloc(sizeof(*ret) * n);
	while (--n >= 0)
	{
		chk_nbr(nbrs[n]);
		if ((nbr = f_strtol(nbrs[n], NULL, 10)) > INT_MAX || nbr < INT_MIN)
			e_exit();
		ret[n] = nbr;
		stacks->min = f_min(nbr, stacks->min);
		stacks->max = f_max(nbr, stacks->max);
	}
	return (ret);
}
