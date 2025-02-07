/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_strategy_private.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:05:18 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/07 17:10:04 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

static void	sort_four_distance_2(t_sort_solver *solver)
{
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->sa(solver->stack_a);
	solver->ops->ra(solver->stack_a);
	solver->ops->pa(solver->stack_a, solver->stack_b);
	sort_three(solver);
}

static void	sort_four_distance_3(t_sort_solver *solver)
{
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->ra(solver->stack_a);
	sort_three_stack_b(solver);
}

void	sort_four(t_sort_solver *solver)
{
	int	distance_to_min;

	distance_to_min = get_distance_to_min(solver->stack_a, 4);
	if (distance_to_min == 0)
	{
		solver->ops->ra(solver->stack_a);
		sort_three(solver);
	}
	else if (distance_to_min == 1)
	{
		solver->ops->sa(solver->stack_a);
		solver->ops->ra(solver->stack_a);
		sort_three(solver);
	}
	else if (distance_to_min == 2)
	{
		sort_four_distance_2(solver);
	}
	else
	{
		sort_four_distance_3(solver);
	}
}
