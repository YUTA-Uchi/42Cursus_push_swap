/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_strategy_private.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:24 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/10 14:56:20 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

void	sort_stack_a(t_sort_solver *solver, int size);
void	sort_stack_b(t_sort_solver *solver, int size);

int	partition_to_a(t_sort_solver *solver, int size, int pivot)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	while (i < size)
	{
		if (solver->stack_b->value(solver->stack_b, 0, TOP) >= pivot)
		{
			solver->ops->pa(solver->stack_a, solver->stack_b);
			pushed++;
		}
		else
			solver->ops->rb(solver->stack_b);
		i++;
	}
	return (pushed);
}

int	partition_to_b(t_sort_solver *solver, int size, int pivot)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	while (i < size)
	{
		if (solver->stack_a->value(solver->stack_a, 0, TOP) < pivot)
		{
			solver->ops->pb(solver->stack_b, solver->stack_a);
			pushed++;
		}
		else
			solver->ops->ra(solver->stack_a);
		i++;
	}
	minimal_restore(solver, solver->stack_a, size - pushed);
	return (pushed);
}

void	sort_stack_a(t_sort_solver *solver, int size)
{
	int	pivot;
	int	pushed;

	pushed = 0;
	if (is_minimal_sort(solver, size))
		return ;
	pivot = get_pivot(solver->stack_a, size);
	pushed = partition_to_b(solver, size, pivot);
	sort_stack_b(solver, pushed);
	sort_stack_a(solver, size - pushed);
}

void	sort_stack_b(t_sort_solver *solver, int size)
{
	int	pivot;
	int	pushed;

	pushed = 0;
	if (is_minimal_sort_stack_b(solver, size))
		return ;
	pivot = get_pivot(solver->stack_b, size);
	pushed = partition_to_a(solver, size, pivot);
	sort_stack_b(solver, size - pushed);
	sort_stack_a(solver, pushed);
}

void	quick_sort(t_sort_solver *solver)
{
	if (solver->stack_a->size <= 1)
		return ;
	if (is_minimal_sort(solver, solver->stack_a->size))
		return ;
	sort_stack_a(solver, solver->stack_a->size);
}
