/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimal_sort_strategy_private.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:54:57 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/10 18:39:23 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

void	sort_one(t_sort_solver *solver, t_stack_pos pos)
{
	if (pos == BOTTOM_A && solver->stack_a->size != 1)
		solver->ops->rra(solver->stack_a);
	else if (pos == BOTTOM_B || pos == TOP_B)
	{
		if (pos == BOTTOM_B && solver->stack_b->size != 1)
			solver->ops->rrb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
}

void	sort_two(t_sort_solver *solver, t_stack_pos pos)
{
	if (pos == TOP_A)
	{
		if (solver->stack_a->value(solver->stack_a, 0, TOP) \
			> solver->stack_a->value(solver->stack_a, 1, TOP))
			solver->ops->sa(solver->stack_a);
		return ;
	}
	else if (pos == BOTTOM_A)
	{
		solver->ops->rra(solver->stack_a);
		solver->ops->rra(solver->stack_a);
	}
	else if (pos == TOP_B)
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
	else
	{
		solver->ops->rrb(solver->stack_b);
		solver->ops->rrb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
	sort_two(solver, TOP_A);
}

bool	is_minimal_sort(t_sort_solver *solver, int size, t_stack_pos pos)
{
	bool	minimal;

	minimal = true;
	if (size <= 1)
		return (sort_one(solver, pos), minimal);
	else if (size == 2)
		return (sort_two(solver, pos), minimal);
	// else if (size == 3)
	// 	return (sort_three(solver), minimal);
	// else if (size == 4)
	// 	return (sort_four(solver), minimal);
	// else if (size == 5)
	// 	return (sort_five(solver), minimal);
	else
		minimal = false;
	return (minimal);
}

// bool	is_minimal_sort_stack_b(t_sort_solver *solver, int size)
// {
// 	bool	minimal;

// 	minimal = true;
// 	if (size <= 1)
// 		return (minimal);
// 	else if (size == 2)
// 		return (sort_two(solver, solver->stack_b), minimal);
// 	else if (size == 3)
// 		return (sort_three_stack_b(solver), minimal);
// 	else if (size == 4)
// 		return (sort_four_stack_b(solver), minimal);
// 	else
// 		minimal = false;
// 	return (minimal);
// }
