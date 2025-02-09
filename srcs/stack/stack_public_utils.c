/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_public_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:29:58 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/09 15:46:11 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_public.h"
#include "stack_private.h"

int	get_insert_position(t_stack *stack, int value, int size)
{
	t_list	*node;
	int		i;

	node = stack->top;
	i = 0;
	while (node && i < size - 1)
	{
		if (*(t_stack_node)node->content > value)
			break ;
		node = node->next;
		i++;
	}
	return (i);
}

int	get_distance_to_min(t_stack *stack, int size)
{
	t_list	*node;
	int		min;
	int		distance;
	int		i;

	node = stack->top;
	min = *(t_stack_node)node->content;
	distance = 0;
	i = 0;
	while (node && (i < size))
	{
		if (*(t_stack_node)node->content < min)
		{
			min = *(t_stack_node)node->content;
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
	max = *(t_stack_node)node->content;
	distance = 0;
	i = 0;
	while (node && (i < size))
	{
		if (*(t_stack_node)node->content > max)
		{
			max = *(t_stack_node)node->content;
			distance = i;
		}
		node = node->next;
		i++;
	}
	return (distance);
}

int	get_smallest_value(t_stack *stack, int size)
{
	int	smallest;
	int	count;
	int	value;

	count = 0;
	smallest = INT_MAX;
	while (count < size)
	{
		value = stack->value(stack, count);
		if (value < smallest)
			smallest = value;
		count++;
	}
	return (smallest);
}

int	get_second_smallest_value(t_stack *stack, int size)
{
	int	smallest;
	int	second_smallest;
	int	count;
	int	value;

	count = 0;
	smallest = INT_MAX;
	second_smallest = INT_MAX;
	while (count < size)
	{
		value = stack->value(stack, count);
		if (value < smallest)
		{
			second_smallest = smallest;
			smallest = value;
		}
		else if (value < second_smallest)
		{
			second_smallest = value;
		}
		count++;
	}
	return (second_smallest);
}
