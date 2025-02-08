/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_strategy_utils_private.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:49:07 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/08 21:06:25 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

int	get_median(int *values, int size)
{
	int		i;
	int		j;
	int		key;
	long	sum;

	i = 1;
	while (i < size)
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
	if (size % 2)
		return (values[size / 2]);
	else
	{
		sum = (long)values[(size / 2) - 1] + (long)values[size / 2];
		return (sum / 2);
	}
}

int	get_insert_position(t_stack *stack, int value, int size)
{
	t_list	*node;
	int		i;

	node = stack->top;
	i = 0;
	while (node && i < size - 1)
	{
		if (*(t_stack_content)node->content > value)
			break ;
		node = node->next;
		i++;
	}
	return (i);
}

void	multi_rotate(t_sort_solver *solver, t_stack *stack, int size)
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

void	multi_reverse_rotate(t_sort_solver *solver, t_stack *stack, int size)
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

	// ft_printf(1, "minimal_move start\n");
	half = stack->size / 2;
	if (half >= distance_from_top)
	{
		multi_rotate(solver, stack, distance_from_top);
	}
	else
	{
		multi_reverse_rotate(solver, stack, stack->size - distance_from_top);
	}
	// ft_printf(1, "minimal_move end\n");
}

int	get_pivot(t_stack *stack, int size)
{
	int		*values;
	t_list	*current;
	int		count;
	int		median;

	values = (int *)malloc(sizeof(int) * size);
	count = 0;
	if (stack->peek(stack) == NULL)
		return (0);
	current = stack->top;
	while (current != NULL && count < size)
	{
		values[count++] = *(t_stack_content)current->content;
		current = current->next;
	}
	median = get_median(values, size);
	free(values);
	return (median);
}

int	get_distance_to_min(t_stack *stack, int size)
{
	t_list	*node;
	int		min;
	int		distance;
	int		i;

	node = stack->top;
	min = *(t_stack_content)node->content;
	distance = 0;
	i = 0;
	while (node && (i < size))
	{
		if (*(t_stack_content)node->content < min)
		{
			min = *(t_stack_content)node->content;
			distance = i;
		}
		node = node->next;
		i++;
	}
	return (distance);
}

int	get_distance_to_max(t_stack *stack, int size)
{
	t_list	*node;
	int		max;
	int		distance;
	int		i;

	node = stack->top;
	max = *(t_stack_content)node->content;
	distance = 0;
	i = 0;
	while (node && (i < size))
	{
		if (*(t_stack_content)node->content > max)
		{
			max = *(t_stack_content)node->content;
			distance = i;
		}
		node = node->next;
		i++;
	}
	return (distance);
}
