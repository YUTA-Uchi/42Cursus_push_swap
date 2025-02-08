/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_strategy_private.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:24 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/08 15:43:25 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

void	sort_stack_a(t_sort_solver *solver, int size);
void	sort_stack_b(t_sort_solver *solver, int size);



// int	get_pivot(t_stack *stack)
// {
// 	int top;
// 	int middle;
// 	int tail;

// 	if (stack->peek(stack) == NULL)
// 		return (0);
// 	top = *(t_stack_content)stack->peek(stack);
// 	if (stack->top->next == NULL)
// 		return (top);
// 	middle = *(t_stack_content)stack->top->next->content;
// 	if (stack->top->next->next == NULL)
// 		return ((top + middle) / 2);
// 	tail = *(t_stack_content)stack->top->next->next->content;
// 	if (top < middle && middle < tail)
// 		return (middle);
// 	else if (top < tail && tail < middle)
// 		return (tail);
// 	else
// 		return (top);
// }

// static int	find_min(t_stack *stack)
// {
// 	t_list	*node;
// 	int		min;

// 	node = stack->top;
// 	min = *(t_stack_content)node->content;
// 	while (node)
// 	{
// 		if (*(t_stack_content)node->content < min)
// 			min = *(t_stack_content)node->content;
// 		node = node->next;
// 	}
// 	return (min);
// }

// static int	find_max(t_stack *stack)
// {
// 	t_list	*node;
// 	int		max;

// 	node = stack->top;
// 	max = *(t_stack_content)node->content;
// 	while (node)
// 	{
// 		if (*(t_stack_content)node->content > max)
// 			max = *(t_stack_content)node->content;
// 		node = node->next;
// 	}
// 	return (max);
// }

// int	get_pivot(t_stack *stack)
// {
// 	int	min;
// 	int	max;

// 	min = find_min(stack);
// 	max = find_max(stack);
// 	return ((min + max) / 2);
// }


int	partition_to_a(t_sort_solver *solver, int size, int pivot)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	// ft_printf(2, "partition_to_a start\n");
	while (i < size)
	{
		if (*(solver->stack_b->peek(solver->stack_b)) >= pivot)
		{
			solver->ops->pa(solver->stack_a, solver->stack_b);
			pushed++;
		}
		else
			solver->ops->rb(solver->stack_b);
		i++;
	}
	// ft_printf(2, "partition_to_a end\n");
	// ft_printf(2, "restore start\n");
	// minimal_restore(solver, solver->stack_b, size - pushed);
	// ft_printf(2, "restore end\n");
	return (pushed);
}

int	partition_to_b(t_sort_solver *solver, int size, int pivot)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	// ft_printf(2, "partition_to_b start\n");
	while (i < size)
	{
		if (*(solver->stack_a->peek(solver->stack_a)) < pivot)
		{
			solver->ops->pb(solver->stack_b, solver->stack_a);
			pushed++;
		}
		else
			solver->ops->ra(solver->stack_a);
		i++;
	}
	// ft_printf(2, "partition_to_b end\n");
	// ft_printf(2, "restore start\n");
	minimal_restore(solver, solver->stack_a, size - pushed);
	// ft_printf(2, "restore end\n");
	return (pushed);
}

void	sort_stack_a(t_sort_solver *solver, int size)
{
	int	pivot;
	int	pushed;

	// ft_printf(2, "stack_a:size: %d\n", size);
	pushed = 0;
	if (is_minimal_sort(solver, size))
		return ;
	pivot = get_pivot(solver->stack_a, size);
	// ft_printf(2, "pivot: %d\n", pivot);
	pushed = partition_to_b(solver, size, pivot);
	sort_stack_b(solver, pushed);
	sort_stack_a(solver, size - pushed);
}

void	sort_stack_b(t_sort_solver *solver, int size)
{
	int	pivot;
	int	pushed;

	// ft_printf(2, "stack_b:size: %d\n", size);
	pushed = 0;
	if (is_minimal_sort_stack_b(solver, size))
		return ;
	pivot = get_pivot(solver->stack_b, size);
	// ft_printf(2, "pivot: %d\n", pivot);
	pushed = partition_to_a(solver, size, pivot);
	sort_stack_b(solver, size - pushed);
	sort_stack_a(solver, pushed);
}

void	quick_sort(t_sort_solver *solver)
{
	if (solver->stack_a->size <= 1)
		return ;
	sort_stack_a(solver, solver->stack_a->size);
}
