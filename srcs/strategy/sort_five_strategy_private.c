/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_strategy_private.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:30:03 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/07 19:13:55 by yuuchiya         ###   ########.fr       */
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
	int	distance_to_min;

	distance_to_min = get_distance_to_min(solver->stack_a, 5);
	if (distance_to_min == 0)
	{
		solver->ops->pb(solver->stack_b, solver->stack_a);
		sort_four(solver);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
	else if (distance_to_min == 1)
	{
		solver->ops->sa(solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		sort_four(solver);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
	else if (distance_to_min == 2)
		sort_five_distance_2(solver);
	else if (distance_to_min == 3)
		sort_five_distance_3(solver);
	else
		sort_five_distance_4(solver);
}
