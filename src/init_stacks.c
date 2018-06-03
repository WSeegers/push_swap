/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 22:34:51 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/03 22:36:09 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"
#include "f_memory.h"

t_stacks *init_stacks(int ac, char **av)
{
	t_stacks *stacks;

	stacks = f_memalloc(sizeof(*stacks));
	stacks->min = INT_MAX;
	stacks->max = INT_MIN;
	stacks->A = get_numbers(stacks, av + 1, ac - 1);
	stacks->B = f_memalloc(sizeof(stacks->B) * ac - 1);
	stacks->acount = ac - 1;
	stacks->bcount = 0;
	return (stacks);
}
