/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_stack_b_strategy_private.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:07:46 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/09 15:49:07 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

// void	sort_four_stack_b(t_sort_solver *solver)
// {
// 	int	distance_to_min;

// 	distance_to_min = get_distance_to_min(solver->stack_b, 4);
// 	if (distance_to_min == 0)
// 	{
// 		solver->ops->pa(solver->stack_a, solver->stack_b);
// 		solver->ops->ra(solver->stack_a);
// 		sort_three_stack_b(solver);
// 	}
// 	else if (distance_to_min == 1)
// 	{
// 		solver->ops->sb(solver->stack_b);
// 		solver->ops->pa(solver->stack_a, solver->stack_b);
// 		solver->ops->ra(solver->stack_a);
// 		sort_three_stack_b(solver);
// 	}
// 	else if (distance_to_min == 2)
// 	{
// 		solver->ops->rrb(solver->stack_b);
// 		solver->ops->rrb(solver->stack_b);
// 		solver->ops->pa(solver->stack_a, solver->stack_b);
// 		solver->ops->ra(solver->stack_a);
// 		sort_three_stack_b(solver);
// 	}
// 	else
// 	{
// 		solver->ops->rrb(solver->stack_b);
// 		solver->ops->pa(solver->stack_a, solver->stack_b);
// 		solver->ops->ra(solver->stack_a);
// 		sort_three_stack_b(solver);
// 	}
// }

void	sort_three_for_four_stack_b(t_sort_solver *solver)
{
	int	insert_position;

	if (solver->stack_a->value(solver->stack_a, 0) \
		> solver->stack_a->value(solver->stack_a, 1))
	{
		solver->ops->sa(solver->stack_a);
	}
	insert_position = get_insert_position(solver->stack_a \
					, solver->stack_b->value(solver->stack_b, 0) \
					, 3);
	minimal_move(solver, solver->stack_a, insert_position);
	solver->ops->pa(solver->stack_a, solver->stack_b);
	minimal_move(solver, solver->stack_a, 3 - insert_position);
}

static void	sort_four_stack_b_distance_1(t_sort_solver *solver)
{
	if (solver->stack_a->value(solver->stack_a, 1) \
		< solver->stack_b->value(solver->stack_b, 0))
	{
		solver->ops->ss(solver->stack_a, solver->stack_b);
	}
	else
	{
		solver->ops->sa(solver->stack_a);
	}
	solver->ops->pa(solver->stack_a, solver->stack_b);
	sort_three_for_four_stack_b(solver);
	solver->ops->ra(solver->stack_a);
}

static void	sort_four_stack_b_distance_2(t_sort_solver *solver)
{
	if (solver->stack_a->value(solver->stack_a, 0) \
		< solver->stack_a->value(solver->stack_a, 1))
	{
		solver->ops->sb(solver->stack_b);
	}
	else
	{
		solver->ops->ss(solver->stack_a, solver->stack_b);
	}
	sort_three_for_four_stack_b(solver);
	solver->ops->pa(solver->stack_a, solver->stack_b);
	solver->ops->ra(solver->stack_a);
}

static void	sort_four_stack_b_distance_3(t_sort_solver *solver)
{
	sort_three_for_four_stack_b(solver);
	solver->ops->pa(solver->stack_a, solver->stack_b);
	solver->ops->ra(solver->stack_a);
}

void	sort_four_stack_b(t_sort_solver *solver)
{
	int	distance_to_max;

	distance_to_max = get_distance_to_max(solver->stack_b, 4);
	solver->ops->pa(solver->stack_a, solver->stack_b);
	solver->ops->pa(solver->stack_a, solver->stack_b);
	if (distance_to_max == 0)
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		sort_three_for_four_stack_b(solver);
		solver->ops->ra(solver->stack_a);
	}
	else if (distance_to_max == 1)
		sort_four_stack_b_distance_1(solver);
	else if (distance_to_max == 2)
		sort_four_stack_b_distance_2(solver);
	else
		sort_four_stack_b_distance_3(solver);
}
