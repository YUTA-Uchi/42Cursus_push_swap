/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_strategy_private.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:24 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/01 17:49:43 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

void	sort_stack_a(t_sort_solver *solver, int size);
void	sort_stack_b(t_sort_solver *solver, int size);

int	get_pivot(t_stack *stack)
{
	if (stack->peek(stack) == NULL)
		return (0);
	if (*(stack->peek(stack)) > *(t_stack_content)stack->top->next->content)
		return (*(stack->peek(stack)));
	return (*(t_stack_content)stack->top->next->content);
}

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
	int	half;

	pushed = 0;
	i = 0;
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
	i = 0;
	half = solver->stack_b->size / 2;
	if (half > (size - pushed))
	{
		while (i < (size - pushed))
		{
			solver->ops->rrb(solver->stack_b);
			i++;
		}
	}
	else
	{
		while (i < solver->stack_b->size - (size - pushed))
		{
			solver->ops->rb(solver->stack_b);
			i++;
		}
	}
	return (pushed);
}

int	partition_to_b(t_sort_solver *solver, int size, int pivot)
{
	int	pushed;
	int	i;
	int	half;

	pushed = 0;
	i = 0;
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
	i = 0;
	half = solver->stack_a->size / 2;
	if (half > (size - pushed))
	{
		while (i < (size - pushed))
		{
			solver->ops->rra(solver->stack_a);
			i++;
		}
	}
	else
	{
		while (i < solver->stack_a->size - (size - pushed))
		{
			solver->ops->ra(solver->stack_a);
			i++;
		}
	}
	return (pushed);
}

void	sort_stack_a(t_sort_solver *solver, int size)
{
	int	pivot;
	int	pushed;

	pushed = 0;
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if (*(solver->stack_a->peek(solver->stack_a)) > *(t_stack_content)(solver->stack_a->top->next->content))
			solver->ops->sa(solver->stack_a);
		return ;
	}
	pivot = get_pivot(solver->stack_a);
	pushed = partition_to_b(solver, size, pivot);
	sort_stack_a(solver, size - pushed);
	sort_stack_b(solver, pushed);
}

void	sort_stack_b(t_sort_solver *solver, int size)
{
	int	pivot;
	int	pushed;

	pushed = 0;
	if (size <= 1)
	{
		if (size == 1)
			solver->ops->pa(solver->stack_a, solver->stack_b);
		return ;
	}
	else if (size == 2)
	{
		if (*(solver->stack_b->peek(solver->stack_b)) < *(t_stack_content)(solver->stack_b->top->next->content))
			solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		return ;
	}
	pivot = get_pivot(solver->stack_b);
	pushed = partition_to_a(solver, size, pivot);
	sort_stack_a(solver, pushed);
	sort_stack_b(solver, size - pushed);
}

void	quick_sort(t_sort_solver *solver)
{
	if (solver->stack_a->size <= 1)
		return ;
	sort_stack_a(solver, solver->stack_a->size);
}

void	quick_strategy_destroy(t_sort_strategy *strategy)
{
	free(strategy);
}
