/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 22:50:05 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/03 22:52:49 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	has_dup(t_stacks *stacks)
{
	int i;
	int j;

	i = -1;
	while (++i < stacks->acount + 1)
	{
		j = i;
		while (++j < stacks->acount)
			if (stacks->A[i] == stacks->A[j])
				e_exit();
	}
}
