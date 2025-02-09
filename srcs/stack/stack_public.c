/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_public.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:13:17 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/09 14:01:26 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_public.h"
#include "stack_private.h"

t_stack	*stack_create(char name)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->top = NULL;
	new_stack->size = 0;
	new_stack->name = name;
	new_stack->push = stack_push;
	new_stack->pop = stack_pop;
	new_stack->value = stack_value;
	new_stack->rotate = stack_rotate;
	new_stack->reverse_rotate = stack_reverse_rotate;
	new_stack->clear = stack_clear;
	new_stack->print = stack_print;
	new_stack->add_size = add_size;
	new_stack->set_stack_top = set_stack_top;
	return (new_stack);
}

void	stack_destroy(t_stack *stack)
{
	stack->clear(stack);
	free(stack);
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
