/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_stack_b_strategy_private.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:57:22 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/06 13:30:22 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

void	sort_three_stack_b_distance_2(t_sort_solver *solver)
{
	// it can be optimized one case -1
	solver->ops->rrb(solver->stack_b);
	solver->ops->pa(solver->stack_a, solver->stack_b);
	solver->ops->ra(solver->stack_a);
	sort_two(solver, solver->stack_b);
}

void	sort_three_stack_b(t_sort_solver *solver)
{
	int	distance_to_min;

	distance_to_min = get_distance_to_min(solver->stack_b, 3);
	if (distance_to_min == 0)
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		sort_two(solver, solver->stack_b);
	}
	else if (distance_to_min == 1)
	{
		// it can be optimized each case -1
		solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		sort_two(solver, solver->stack_b);
	}
	else
	{
		sort_three_stack_b_distance_2(solver);
	}
}
