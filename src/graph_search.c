/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 12:33:21 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/19 12:35:22 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

t_state	*graph_search(t_info *info)
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
