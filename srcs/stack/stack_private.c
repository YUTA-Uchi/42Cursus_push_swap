/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_private.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:34:38 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/10 18:31:57 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_private.h"

void	stack_push(t_stack *stack, t_stack_value content)
{
	t_stack_node			*new_node;

	new_node = create_node(content);
	if (!new_node)
	{
		free(content);
		return ;
	}
	add_node_front(&(stack->top), &(stack->bottom), new_node);
	add_size(&(stack->size), 1);
}

t_stack_value	stack_pop(t_stack *stack)
{
	t_stack_node	*node;
	t_stack_value	content;

	if (stack->size == 0)
		return (NULL);
	node = stack->top;
	content = get_node_content(node);
	set_stack_top(&(stack->top), get_next_node(node));
	set_prev_node(stack->top, NULL);
	if (stack->size == 1)
		set_stack_bottom(&(stack->bottom), NULL);
	free(node);
	add_size(&(stack->size), -1);
	return (content);
}

void	stack_swap(t_stack *stack)
{
	t_stack_value	first_content;
	t_stack_value	second_content;

	if (stack->size < 2)
		return ;
	first_content = stack->pop(stack);
	second_content = stack->pop(stack);
	stack->push(stack, first_content);
	stack->push(stack, second_content);
}

void	stack_rotate(t_stack *stack)
{
	t_stack_value	top_content;

	if (stack->size < 2)
		return ;
	top_content = stack->pop(stack);
	add_node_back(&(stack->top), &(stack->bottom), create_node(top_content));
	stack->add_size(&(stack->size), 1);
}

void	stack_reverse_rotate(t_stack *stack)
{
	t_stack_node	*tail_node;
	t_stack_value	tail_content;

	if (stack->size < 2)
		return ;
	tail_node = stack->bottom;
	tail_content = get_node_content(tail_node);
	set_stack_bottom(&(stack->bottom), get_prev_node(tail_node));
	set_next_node(stack->bottom, NULL);
	free(tail_node);
	stack->add_size(&(stack->size), -1);
	stack->push(stack, tail_content);
}
