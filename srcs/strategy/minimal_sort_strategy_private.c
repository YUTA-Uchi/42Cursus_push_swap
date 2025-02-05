/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimal_sort_strategy_private.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:54:57 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/05 12:52:12 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

void	sort_two(t_sort_solver *solver, t_stack *stack)
{
	if (stack->name == 'a')
	{
		if (*(solver->stack_a->peek(solver->stack_a)) \
			> *(t_stack_content)(solver->stack_a->top->next->content))
			solver->ops->sa(solver->stack_a);
	}
	else
	{
		if (*(solver->stack_b->peek(solver->stack_b)) \
			< *(t_stack_content)(solver->stack_b->top->next->content))
			solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
}


void	sort_three(t_sort_solver *solver)
{
	int	distance_to_min;

	distance_to_min = get_distance_to_min(solver->stack_a, 3);
	if (distance_to_min == 0)
	{
		solver->ops->pb(solver->stack_b, solver->stack_a);
		sort_two(solver, solver->stack_a);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
	else if (distance_to_min == 1)
	{
		solver->ops->sa(solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		sort_two(solver, solver->stack_a);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
	else
	{
		solver->ops->ra(solver->stack_a);
		solver->ops->sa(solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->rra(solver->stack_a);
		sort_two(solver, solver->stack_a);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
}

void	sort_three_stack_b(t_sort_solver *solver)
{
	int	distance_to_max;

	distance_to_max = get_distance_to_max(solver->stack_b, 3);
	if (distance_to_max == 0)
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		sort_two(solver, solver->stack_b);
	}
	else if (distance_to_max == 1)
	{
		solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		sort_two(solver, solver->stack_b);
	}
	else
	{
		solver->ops->rb(solver->stack_b);
		solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->rrb(solver->stack_b);
		sort_two(solver, solver->stack_b);
	}
}
