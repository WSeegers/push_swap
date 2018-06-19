/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 05:11:47 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/19 08:14:43 by wseegers         ###   ########.fr       */
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

static void		get_children(t_list *search_list,t_list *v_list, t_state *state)
{
	excl_append_state(search_list, v_list, next_state(state, "sa"));
	excl_append_state(search_list, v_list, next_state(state, "sb"));
	excl_append_state(search_list, v_list, next_state(state, "ss"));
	excl_append_state(search_list, v_list, next_state(state, "pa"));
	excl_append_state(search_list, v_list, next_state(state, "pb"));
	excl_append_state(search_list, v_list, next_state(state, "ra"));
	excl_append_state(search_list, v_list, next_state(state, "rb"));
	excl_append_state(search_list, v_list, next_state(state, "rr"));
	excl_append_state(search_list, v_list, next_state(state, "rra"));
	excl_append_state(search_list, v_list, next_state(state, "rrb"));
	excl_append_state(search_list, v_list, next_state(state, "rrr"));
}

static t_state	*find_path(t_info *info)
{
	t_list	*search_list;
	t_list	*visit_list;
	t_state	*current;
	
	search_list = s_list_create(NULL);
	visit_list = s_list_create(NULL);
	current = create_state();
	current->parent = NULL;
	current->stk_a = stack_copy(info->stk_a);
	current->stk_b = stack_copy(info->stk_b);
	s_list_append(search_list, current);

	while (search_list->size)
	{
		f_printf("list_size: %lu\n", search_list->size);
		current = (t_state*)s_list_pop(search_list, 0);
		if (stack_is_sorted(current->stk_a, 0) && !current->stk_b->size)
		{
			return (current);
		}
		get_children(search_list, visit_list, current);
		s_list_append(visit_list, current);
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
			f_printf("\t");
			for (size_t i = 0; i < cur->stk_b->size; i++)
				f_printf("%ld-", cur->stk_b->data[i]);
			f_printf("\n");
			cur = cur->parent;
		}
	}
	exit(0);
}
