/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_strategy_private.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:54:18 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/11 12:10:29 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

static void	sort_three_distance_0(t_sort_solver *solver, t_stack_pos pos)
{
	if (pos == TOP_A)
	{
		solver->ops->sa(solver->stack_a);
		solver->ops->ra(solver->stack_a);
		solver->ops->sa(solver->stack_a);
		solver->ops->rra(solver->stack_a);
		sort_two(solver, TOP_A);
	}
	else
	{
		move_to_top_a(solver, pos, 3);
		sort_two(solver, TOP_A);
	}
}

static void	sort_three_distance_1(t_sort_solver *solver, t_stack_pos pos)
{
	if (pos == TOP_A)
	{
		solver->ops->ra(solver->stack_a);
		solver->ops->sa(solver->stack_a);
		solver->ops->rra(solver->stack_a);
		sort_two(solver, TOP_A);
	}
	else
	{
		move_to_top_a(solver, pos, 2);
		solver->ops->sa(solver->stack_a);
		move_to_top_a(solver, pos, 1);
		sort_two(solver, TOP_A);
	}
}

static void	sort_three_distance_2(t_sort_solver *solver, t_stack_pos pos)
{
	if (pos == TOP_A)
		sort_two(solver, TOP_A);
	else if (pos == BOTTOM_B)
	{
		solver->ops->rrb(solver->stack_b);
		solver->ops->rrb(solver->stack_b);
		solver->ops->rrb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		sort_two(solver, TOP_A);
	}
	else
	{
		move_to_top_a(solver, pos, 3);
		sort_three_distance_0(solver, TOP_A);
	}
}

void	sort_three_minimum(t_sort_solver *solver)
{
	int	first;
	int	second;
	int	third;

	first = solver->stack_a->value(solver->stack_a, 0, TOP);
	second = solver->stack_a->value(solver->stack_a, 1, TOP);
	third = solver->stack_a->value(solver->stack_a, 2, TOP);
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

void	sort_three(t_sort_solver *solver, t_stack_pos pos)
{
	int	distance_to_max;

	if (solver->stack_a->size == 3)
	{
		sort_three_minimum(solver);
		return ;
	}
	if (pos == TOP_A)
		distance_to_max = get_distance_to_max_from_top(solver->stack_a, 3);
	else if (pos == TOP_B)
		distance_to_max = get_distance_to_max_from_top(solver->stack_b, 3);
	else if (pos == BOTTOM_A)
		distance_to_max = get_distance_to_max_from_bottom(solver->stack_a, 3);
	else
		distance_to_max = get_distance_to_max_from_bottom(solver->stack_b, 3);
	if (distance_to_max == 0)
		sort_three_distance_0(solver, pos);
	else if (distance_to_max == 1)
		sort_three_distance_1(solver, pos);
	else
		sort_three_distance_2(solver, pos);
}
