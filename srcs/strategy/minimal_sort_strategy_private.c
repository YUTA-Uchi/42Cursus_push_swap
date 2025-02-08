/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimal_sort_strategy_private.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:54:57 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/08 17:48:51 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

void	sort_two(t_sort_solver *solver, t_stack *stack)
{
	if (stack->name == 'a')
	{
		if (*(t_stack_content)(solver->stack_a->top->content) \
			> *(t_stack_content)(solver->stack_a->top->next->content))
			solver->ops->sa(solver->stack_a);
		solver->ops->ra(solver->stack_a);
		solver->ops->ra(solver->stack_a);
	}
	else
	{
		if (*(t_stack_content)(solver->stack_b->top->content) \
			> *(t_stack_content)(solver->stack_b->top->next->content))
		{
			solver->ops->pa(solver->stack_a, solver->stack_b);
			solver->ops->pa(solver->stack_a, solver->stack_b);
			solver->ops->ra(solver->stack_a);
			solver->ops->ra(solver->stack_a);
			return ;
		}
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
	}
}

bool	is_minimal_sort(t_sort_solver *solver, int size)
{
	bool	minimal;

	minimal = true;
	if (size <= 1)
		return (minimal);
	else if (size == 2)
		return (sort_two(solver, solver->stack_a), minimal);
	else if (size == 3)
		return (sort_three(solver), minimal);
	else if (size == 4)
		return (sort_four(solver), minimal);
	else if (solver->stack_a->size == 5)
		return (sort_five(solver), minimal);
	else
		minimal = false;
	return (minimal);
}

bool	is_minimal_sort_stack_b(t_sort_solver *solver, int size)
{
	bool	minimal;

	minimal = true;
	if (size <= 1)
		return (minimal);
	else if (size == 2)
		return (sort_two(solver, solver->stack_b), minimal);
	else if (size == 3)
		return (sort_three_stack_b(solver), minimal);
	else if (size == 4)
		return (sort_four_stack_b(solver), minimal);
	// else if (size == 5)
	// 	return (sort_five_stack_b(solver), minimal);
	else
		minimal = false;
	return (minimal);
}
