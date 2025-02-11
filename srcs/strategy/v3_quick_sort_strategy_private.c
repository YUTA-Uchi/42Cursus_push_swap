/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_quick_sort_strategy_private.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:19:50 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/11 12:07:06 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_solver_public.h"
#include "sort_strategy_private.h"

void	partition_to_3(t_sort_solver *solver, t_stack *stack, \
					t_recursion_data *rec_data, t_stack_search_from from)
{
	if (stack->value(stack, 0, from) < rec_data->pivot[SPLIT_MIN])
		move_to_min(solver, rec_data);
	else if (stack->value(stack, 0, from) < rec_data->pivot[SPLIT_MID])
		move_to_mid(solver, rec_data);
	else
		move_to_max(solver, rec_data);
}

void	split_to_3part(t_sort_solver *solver, t_recursion_data *rec_data)
{
	int		i;
	t_stack	*stack;

	if (rec_data->pos == TOP_A || rec_data->pos == BOTTOM_A)
		stack = solver->stack_a;
	else
		stack = solver->stack_b;
	i = 0;
	get_pivots(stack, rec_data);
	while (i < rec_data->size)
	{
		if (rec_data->pos == TOP_A || rec_data->pos == TOP_B)
			partition_to_3(solver, stack, rec_data, TOP);
		else
			partition_to_3(solver, stack, rec_data, BOTTOM);
		i++;
	}
}

void	recurse_v3_quick_sort(t_sort_solver *solver, int size, t_stack_pos pos)
{
	t_recursion_data	*recursion_data;

	pos = optimize_position(solver, size, pos);
	if (is_minimal_sort(solver, size, pos))
		return ;
	recursion_data = recursion_data_create(size, pos);
	split_to_3part(solver, recursion_data);
	recurse_v3_quick_sort(solver, recursion_data->next_size[PART_MAX] \
						, get_max_pos(pos));
	recurse_v3_quick_sort(solver, recursion_data->next_size[PART_MID] \
						, get_mid_pos(pos));
	recurse_v3_quick_sort(solver, recursion_data->next_size[PART_MIN] \
						, get_min_pos(pos));
	recursion_data_destroy(recursion_data);
}

void	v3_quick_sort(t_sort_solver *solver)
{
	if (is_sorted(solver->stack_a))
		return ;
	if (is_minimal_sort(solver, solver->stack_a->size, TOP_A))
		return ;
	recurse_v3_quick_sort(solver, solver->stack_a->size, TOP_A);
}

void	v3_quick_strategy_destroy(t_sort_strategy *strategy)
{
	free(strategy);
}
