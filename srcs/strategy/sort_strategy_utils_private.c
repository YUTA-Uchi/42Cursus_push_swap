/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_strategy_utils_private.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:49:07 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/09 15:44:48 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

static void	multi_rotate(t_sort_solver *solver, t_stack *stack, int size)
{
	int	i;

	i = 0;
	while (i++ < size)
	{
		if (stack->name == 'a')
			solver->ops->ra(stack);
		else
			solver->ops->rb(stack);
	}
}

static void	multi_reverse_rotate(t_sort_solver *solver, \
								t_stack *stack, int size)
{
	int	i;

	i = 0;
	while (i++ < size)
	{
		if (stack->name == 'a')
			solver->ops->rra(stack);
		else
			solver->ops->rrb(stack);
	}
}

void	minimal_restore(t_sort_solver *solver, \
						t_stack *stack, \
						int size_remain)
{
	int	half;

	half = stack->size / 2;
	if (half >= size_remain)
	{
		multi_reverse_rotate(solver, stack, size_remain);
	}
	else
	{
		multi_rotate(solver, stack, stack->size - size_remain);
	}
}

void	minimal_move(t_sort_solver *solver, \
						t_stack *stack, \
						int distance_from_top)
{
	int	half;

	half = stack->size / 2;
	if (half >= distance_from_top)
	{
		multi_rotate(solver, stack, distance_from_top);
	}
	else
	{
		multi_reverse_rotate(solver, stack, stack->size - distance_from_top);
	}
}
