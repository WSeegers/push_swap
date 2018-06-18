/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 20:58:47 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/18 11:12:59 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "f_io.h"

int	main(int ac, char *av[])
{
	t_info *info;
	char 	*line;
	
	if (ac == 1)
		exit(0);
	info = get_info(ac, av); 

	//print_stacks(info);
	while (f_next_line(&line, STDIN))
	{
		stack_ops(info, line);
		//print_stacks(info);
		f_strdel(&line);
	}
	check_stacks(info);
	exit(0);
}
