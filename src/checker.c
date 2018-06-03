/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 20:58:47 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/03 22:53:25 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include "push_swap.h"
#include "f_print.h"
#include "f_memory.h"
#include "f_string.h"
#include "f_math.h"


int	main(int ac, char *av[])
{
	t_stacks *stacks;

	if (ac == 1)
		exit(0);
	stacks = init_stacks(ac, av); 
	has_dup(stacks);


	f_print_nbr(stacks->A[ac - 2]);
	f_print_str("\n");
	f_print_nbr(stacks->max);
	f_print_str("\n");
	f_print_nbr(stacks->min);
	f_print_str("\n");
	exit(0);
}
