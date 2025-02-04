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

int	get_pivot(t_stack *stack, int size)
{
	int			values[size];
	int			count;
	t_list		*current;
	int			i, j, key;

	count = 0;
	if (stack->peek(stack) == NULL)
		return (0);

	current = stack->top;
	while (current != NULL && count < size)
	{
		values[count] = *(t_stack_content)current->content;
		count++;
		current = current->next;
	}

	i = 1;
	while (i < count)
	{
		key = values[i];
		j = i - 1;
		while (j >= 0 && values[j] > key)
		{
			values[j + 1] = values[j];
			j--;
		}
		values[j + 1] = key;
		i++;
	}

	if (count % 2)
		return (values[count / 2]);
	else
		return ((values[(count / 2) - 1] + values[count / 2]) / 2);
}

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

void	minimal_restore(t_sort_solver *solver, t_stack *stack, int size_remain)
{
	int	i;
	int	half;

	i = 0;
	half = stack->size / 2;
	if (half > size_remain)
	{
		while (i++ < size_remain)
		{
			if (stack->name == 'a')
				solver->ops->rra(stack);
			else
				solver->ops->rrb(stack);
		}
	}
	else
	{
		while (i++ < stack->size - size_remain)
		{
			if (stack->name == 'a')
				solver->ops->ra(stack);
			else
				solver->ops->rb(stack);
		}
	}
}

int	partition_to_a(t_sort_solver *solver, int size, int pivot)
{
	int	pushed;
	int	i;

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
	minimal_restore(solver, solver->stack_b, size - pushed);
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
		if (*(solver->stack_a->peek(solver->stack_a)) < pivot)
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

void	sort_three(t_sort_solver *solver)
{
	int a, b, c;

	if (!solver->stack_a || !(solver->stack_a->top) || \
		!solver->stack_a->top->next || !solver->stack_a->top->next->next)
		return; // 要素が3個未満の場合は別途処理

	a = *(t_stack_content)(solver->stack_a->top->content);
	b = *(t_stack_content)(solver->stack_a->top->next->content);
	c = *(t_stack_content)(solver->stack_a->top->next->next->content);

	/*
	 * 1. 例: a > b && b < c && a < c  -> 最初の2個が入れ替わるだけ
	 * 2. 例: a > b && b > c		  -> swap & reverse_rotate
	 * 3. 例: a > b && b < c && a > c  -> rotate
	 * 4. 例: a < b && b > c && a < c  -> swap & rotate
	 * 5. 例: a < b && b > c && a > c  -> reverse_rotate
	 */

	if (a > b && b < c && a < c)
		solver->ops->sa(solver->stack_a);
	else if (a > b && b > c)
	{
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->sa(solver->stack_a);
		solver->ops->ra(solver->stack_a);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->sa(solver->stack_a);
		solver->ops->rra(solver->stack_a);
	}
	else if (a > b && b < c && a > c)
	{
		solver->ops->sa(solver->stack_a);
		solver->ops->ra(solver->stack_a);
		solver->ops->sa(solver->stack_a);
		solver->ops->rra(solver->stack_a);
	}
	else if (a < b && b > c && a < c)
	{
		solver->ops->ra(solver->stack_a);
		solver->ops->sa(solver->stack_a);
		solver->ops->rra(solver->stack_a);
	}
	else if (a < b && b > c && a > c)
	{
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->sa(solver->stack_a);
		solver->ops->ra(solver->stack_a);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->rra(solver->stack_a);
	}
}

void	sort_three_stack_b(t_sort_solver *solver)
{
	int a, b, c;

	if (!solver->stack_b || !(solver->stack_b->top) || \
		!solver->stack_b->top->next || !solver->stack_b->top->next->next)
		return; // 要素が3個未満の場合は別途処理

	a = *(t_stack_content)(solver->stack_b->top->content);
	b = *(t_stack_content)(solver->stack_b->top->next->content);
	c = *(t_stack_content)(solver->stack_b->top->next->next->content);

	if (a > b && a > c && c > b)
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
	else if (b > a && a > c)
	{
		solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
	else if (b > a && b > c && c > a)
	{
		solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
	else if (c > a && a > b)
	{
		solver->ops->rb(solver->stack_b);
		solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->rrb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
	else if (c > b && b > a)
	{
		solver->ops->rb(solver->stack_b);
		solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->rrb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
	else
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
}

void	sort_stack_a(t_sort_solver *solver, int size)
{
	int	pivot;
	int	pushed;

	ft_printf(2, "stack_a:size: %d\n", size);
	pushed = 0;
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if (*(solver->stack_a->peek(solver->stack_a)) > *(t_stack_content)(solver->stack_a->top->next->content))
			solver->ops->sa(solver->stack_a);
		return ;
	}
	else if (size == 3)
	{
		sort_three(solver);
		return ;
	}
	pivot = get_pivot(solver->stack_a, size);
	// pivot = get_pivot(solver->stack_a);
	pushed = partition_to_b(solver, size, pivot);
	sort_stack_a(solver, size - pushed);
	sort_stack_b(solver, pushed);
}

void	sort_stack_b(t_sort_solver *solver, int size)
{
	int	pivot;
	int	pushed;

	ft_printf(2, "stack_b:size: %d\n", size);
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
	else if (size == 3)
	{
		sort_three_stack_b(solver);
		return ;
	}
	pivot = get_pivot(solver->stack_b, size);
	// pivot = get_pivot(solver->stack_b);
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
