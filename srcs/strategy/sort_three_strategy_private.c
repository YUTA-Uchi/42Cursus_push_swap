/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_strategy_private.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:54:18 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/09 14:31:35 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

void	sort_three_distance_0(t_sort_solver *solver)
{
	solver->ops->ra(solver->stack_a);
	sort_two(solver, solver->stack_a);
}

void	sort_three_distance_1(t_sort_solver *solver)
{
	solver->ops->sa(solver->stack_a);
	solver->ops->ra(solver->stack_a);
	sort_two(solver, solver->stack_a);
}

void	sort_three_distance_2(t_sort_solver *solver)
{
	int	insert_position;

	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->sa(solver->stack_a);
	insert_position = get_insert_position(solver->stack_a \
							, solver->stack_b->value(solver->stack_b, 0) \
							, 3);
	minimal_move(solver, solver->stack_a, insert_position);
	solver->ops->pa(solver->stack_a, solver->stack_b);
	minimal_move(solver, solver->stack_a, 3 - insert_position);
}

void	sort_three_minimum(t_sort_solver *solver)
{
	int	first;
	int	second;
	int	third;

	first = solver->stack_a->value(solver->stack_a, 0);
	second = solver->stack_a->value(solver->stack_a, 1);
	third = solver->stack_a->value(solver->stack_a, 2);
	if (first > second && second < third && third > first)
		solver->ops->sa(solver->stack_a);
	else if (first > second && second > third && third < first)
	{
		solver->ops->sa(solver->stack_a);
		solver->ops->rra(solver->stack_a);
	}
	else if (first > second && second < third && third < first)
		solver->ops->ra(solver->stack_a);
	else if (first < second && second > third && third > first)
	{
		solver->ops->sa(solver->stack_a);
		solver->ops->ra(solver->stack_a);
	}
	else if (first < second && second > third && third < first)
		solver->ops->rra(solver->stack_a);
}

void	sort_three(t_sort_solver *solver)
{
	int	distance_to_min;

	if (solver->stack_a->size == 3)
	{
		sort_three_minimum(solver);
		return ;
	}
	distance_to_min = get_distance_to_min(solver->stack_a, 3);
	if (distance_to_min == 0)
		sort_three_distance_0(solver);
	else if (distance_to_min == 1)
		sort_three_distance_1(solver);
	else
		sort_three_distance_2(solver);
}


