/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_strategy_private.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:30:03 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/09 13:01:37 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

void	sort_five_distance_2(t_sort_solver *solver)
{
	solver->ops->ra(solver->stack_a);
	solver->ops->ra(solver->stack_a);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	sort_four(solver);
	solver->ops->pa(solver->stack_a, solver->stack_b);
}

void	sort_five_distance_3(t_sort_solver *solver)
{
	solver->ops->ra(solver->stack_a);
	solver->ops->ra(solver->stack_a);
	solver->ops->ra(solver->stack_a);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	sort_four(solver);
	solver->ops->pa(solver->stack_a, solver->stack_b);
}

void	sort_five_distance_4(t_sort_solver *solver)
{
	solver->ops->ra(solver->stack_a);
	solver->ops->ra(solver->stack_a);
	solver->ops->ra(solver->stack_a);
	solver->ops->ra(solver->stack_a);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	sort_four(solver);
	solver->ops->pa(solver->stack_a, solver->stack_b);
}

void	sort_five(t_sort_solver *solver)
{
	int	insert_position;
	// int	distance_to_max;
	// int	distance_to_min;

	// distance_to_min = get_distance_to_min(solver->stack_a, 5);
	// distance_to_max = get_distance_to_max(solver->stack_a, 5);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	sort_three(solver);
	insert_position = get_insert_position(solver->stack_a \
					, solver->stack_b->value(solver->stack_b, 0) \
					, 4);
	minimal_move(solver, solver->stack_a, insert_position);
	solver->ops->pa(solver->stack_a, solver->stack_b);
	minimal_move(solver, solver->stack_a, 4 - insert_position);
	insert_position = get_insert_position(solver->stack_a \
					, solver->stack_b->value(solver->stack_b, 0) \
					, 5);
	minimal_move(solver, solver->stack_a, insert_position);
	solver->ops->pa(solver->stack_a, solver->stack_b);
	minimal_move(solver, solver->stack_a, 5 - insert_position);
}
