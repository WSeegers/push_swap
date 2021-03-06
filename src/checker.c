/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 20:58:47 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/18 12:43:47 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "f_io.h"

int	main(int ac, char *av[])
{
	t_info	*info;
	char	*line;

	if (ac == 1)
		exit(0);
	info = get_info(ac, av);
	while (f_next_line(&line, STDIN))
	{
		stack_ops(info, line);
		f_strdel(&line);
	}
	check_stacks(info);
	exit(0);
}
