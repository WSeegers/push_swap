/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 05:11:47 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/18 23:06:54 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "push_swap.h"
#include "f_io.h"
#include "f_string.h"
#include "f_memory.h"
#include "s_list.h"
#include "s_state.h"
#include "f_print.h"

static void		get_children(t_list *search_list, t_state *state)
{
	s_list_append(search_list, next_state(state, "sa"));
	s_list_append(search_list, next_state(state, "sb"));
	s_list_append(search_list, next_state(state, "ss"));
	s_list_append(search_list, next_state(state, "pa"));
	s_list_append(search_list, next_state(state, "pb"));
	s_list_append(search_list, next_state(state, "ra"));
	s_list_append(search_list, next_state(state, "rb"));
	s_list_append(search_list, next_state(state, "rr"));
	s_list_append(search_list, next_state(state, "rra"));
	s_list_append(search_list, next_state(state, "rrb"));
	s_list_append(search_list, next_state(state, "rrr"));
}

static t_state	*find_path(t_info *info)
{
	t_list	*search_list;
	t_state	*current;
	
	search_list = s_list_create(NULL);
	current = create_state();
	current->parent = NULL;
	current->stk_a = stack_copy(info->stk_a);
	current->stk_b = stack_copy(info->stk_b);
	s_list_append(search_list, current);

	while (search_list->size)
	{
		current = (t_state*)s_list_pop(search_list, 0);
		if (stack_is_sorted(current->stk_a, 0) && !current->stk_b->size)
		{
			f_printf("found!\n");
			return (current);
		}
		get_children(search_list, current);
	}
	return (NULL);
}

int			main(int ac, char *av[])
{
	t_info *info;
	t_state *cur;

	if (ac == 1)
		exit(0);
	info = get_info(ac, av);
	rank_info(info);
	if ((cur = find_path(info)))
	{
		while (cur)
		{
			f_printf("op: %s\t", cur->op);
			for (size_t i = 0; i < cur->stk_a->size; i++)
				f_printf("%ld-", cur->stk_a->data[i]);
			f_printf("\n");
			cur = cur->parent;
		}
	}
	exit(0);
}
