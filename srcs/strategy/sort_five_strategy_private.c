/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_strategy_private.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:30:03 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/10 14:56:45 by yuuchiya         ###   ########.fr       */
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

void	sort_five_minimum(t_sort_solver *solver)
{
	int	smallest;
	int	second_smallest;

	smallest = get_smallest_value(solver->stack_a, 5);
	second_smallest = get_second_smallest_value(solver->stack_a, 5);
	while (solver->stack_a->size > 3)
	{
		if (solver->stack_a->value(solver->stack_a, 0, TOP) == smallest \
		|| solver->stack_a->value(solver->stack_a, 0, TOP) == second_smallest)
			solver->ops->pb(solver->stack_b, solver->stack_a);
		else
			solver->ops->ra(solver->stack_a);
	}
	if (solver->stack_b->value(solver->stack_b, 0, TOP) \
		< solver->stack_b->value(solver->stack_b, 1, TOP))
		solver->ops->sb(solver->stack_b);
	sort_three_minimum(solver);
	solver->ops->pa(solver->stack_a, solver->stack_b);
	solver->ops->pa(solver->stack_a, solver->stack_b);
}

void	sort_five(t_sort_solver *solver)
{
	if (solver->stack_a->size == 5)
	{
		sort_five_minimum(solver);
		return ;
	}
}
