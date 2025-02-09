/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_private.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:34:38 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/09 12:55:34 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_private.h"

void	stack_push(t_stack *stack, t_stack_node content)
{
	t_list			*new_node;

	new_node = ft_lstnew(content);
	if (!new_node)
	{
		free(content);
		return ;
	}
	ft_lstadd_front(&(stack->top), new_node);
	add_size(&(stack->size), 1);
}

t_stack_node	stack_pop(t_stack *stack)
{
	t_list			*node;
	t_stack_node	content;

	if (stack->size == 0)
		return (NULL);
	node = stack->top;
	content = (t_stack_node)(node->content);
	set_stack_top(&(stack->top), node->next);
	free(node);
	add_size(&(stack->size), -1);
	return (content);
}

int	stack_value(t_stack *stack, int index)
{
	t_list	*node;

	if (stack->size == 0)
		return (0);
	node = stack->top;
	while (node && index > 0)
	{
		node = node->next;
		index--;
	}
	return (*(t_stack_node)(node->content));
}

void	stack_rotate(t_stack *stack)
{
	t_stack_node	top_content;

	if (stack->size < 2)
		return ;
	top_content = stack->pop(stack);
	ft_lstadd_back(&(stack->top), ft_lstnew(top_content));
	stack->add_size(&(stack->size), 1);
}

void	stack_reverse_rotate(t_stack *stack)
{
	t_list			*tail;
	t_list			*pretail;
	t_stack_node	tail_content;

	if (stack->size < 2)
		return ;
	pretail = stack->top;
	while (pretail->next->next)
		pretail = pretail->next;
	tail = pretail->next;
	tail_content = (t_stack_node)(tail->content);
	pretail->next = NULL;
	free(tail);
	stack->add_size(&(stack->size), -1);
	stack->push(stack, tail_content);
}
