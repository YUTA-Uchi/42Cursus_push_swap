/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_quick_sort_strategy_private.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:19:50 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/09 18:56:45 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

void	get_two_tri_partition_pivots(int *values, int size, int *pivots)
{
	int		i;
	int		j;
	int		key;

	i = 1;
	while (i < size)
	{
		key = values[i];
		j = i - 1;
		while (j >= 0 && values[j] > key)
		{
			values[j + 1] = values[j];
			j--;
		}
		values[j + 1] = key;
		i++;
	}
	pivots[0] = values[size / 3];
	pivots[1] = values[(2 * size) / 3];
}

void	move_to_min(t_sort_solver *solver, \
					t_stack_pos current_pos, int *next_size)
{
	next_size[2]++;
	if (current_pos == TOP_A)
	{
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->rb(solver->stack_b);
	}
	else if (current_pos == BOTTOM_A)
	{
		solver->ops->rra(solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->rb(solver->stack_b);
	}
	else if (current_pos == TOP_B)
		solver->ops->rb(solver->stack_b);
	else if (current_pos == BOTTOM_B)
		solver->ops->rrb(solver->stack_b);
}

void	move_to_mid(t_sort_solver *solver, \
					t_stack_pos current_pos, int *next_size)
{
	next_size[1]++;
	if (current_pos == TOP_A)
	{
		solver->ops->pb(solver->stack_b, solver->stack_a);
	}
	else if (current_pos == BOTTOM_A)
	{
		solver->ops->rra(solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
	}
	else if (current_pos == TOP_B)
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
	}
	else if (current_pos == BOTTOM_B)
	{
		solver->ops->rrb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
	}
}

void	move_to_max(t_sort_solver *solver, \
					t_stack_pos current_pos, int *next_size)
{
	next_size[0]++;
	if (current_pos == TOP_A)
	{
		solver->ops->ra(solver->stack_a);
	}
	else if (current_pos == BOTTOM_A)
	{
		solver->ops->rra(solver->stack_a);
	}
	else if (current_pos == TOP_B)
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
	else if (current_pos == BOTTOM_B)
	{
		solver->ops->rrb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}	
}

void	split_to_3part(t_sort_solver *solver, int size, t_stack_pos pos, int *next_size)
{
	int	pivot[2];
	int	i;

	i = 0;
	get_pivot(solver->stack_a, size, pos, pivot);
	while (i < size)
	{
		if (solver->stack_a->value(solver->stack_a, 0) < pivot[0])
			move_to_min(solver, pos, next_size);
		else if (solver->stack_a->value(solver->stack_a, 0) < pivot[1])
			move_to_mid(solver, pos, next_size);
		else
			move_to_max(solver, pos, next_size);
		i++;
	}
}

void	init_next_size(int *next_size)
{
	next_size[0] = 0;
	next_size[1] = 0;
	next_size[2] = 0;
}

void	recurse_v3_quick_sort(t_sort_solver *solver, int size, t_stack_pos pos)
{
	int	next_size[3];

	if (size <= 1)
		return ;
	if (size == 2)
	{
		if (solver->stack_a->value(solver->stack_a, 0) \
			> solver->stack_a->value(solver->stack_a, 1))
			solver->ops->sa(solver->stack_a);
		return ;
	}
	else if (size == 3)
	{
		sort_three(solver);
		return ;
	}
	init_next_size(next_size);
	split_to_3part(solver, size, pos, next_size);
	recurse_v3_quick_sort(solver, next_size[0], get_max_pos(pos));
	recurse_v3_quick_sort(solver, next_size[1], get_mid_pos(pos));
	recurse_v3_quick_sort(solver, next_size[2], get_min_pos(pos));
}

void	v3_quick_sort(t_sort_solver *solver)
{
	if (solver->stack_a->size <= 1)
		return ;
	if (is_sorted(solver->stack_a))
		return ;
	if (is_minimal_sort(solver, solver->stack_a->size))
		return ;
	recurse_v3_quick_sort(solver, solver->stack_a->size, TOP_A);
}

void	v3_quick_strategy_destroy(t_sort_strategy *strategy)
{
	free(strategy);
}
