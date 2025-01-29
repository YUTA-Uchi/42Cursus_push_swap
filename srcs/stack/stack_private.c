/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_private.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:34:38 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/01/29 19:58:49 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_private.h"

void	stack_push(const t_stack *stack, int content)
{
	t_list	*new_node;

	new_node = ft_lstnew(&content);
	if (!new_node)
		return ;
	ft_lstadd_front(&(stack->top), new_node);
	add_size(&(stack->size), 1);
}

int	stack_pop(const t_stack *stack)
{
	t_list	*node;
	int		content;

	if (stack->size == 0)
		return (0);
	node = stack->top;
	content = *(int *)(node->content);
	set_stack_top(&(stack->top), node->next);
	ft_lstdelone(node, free);
	add_size(&(stack->size), -1);
	return (content);
}

int	stack_peek(const t_stack *stack)
{
	if (stack->size == 0)
		return (0);
	return (*(int *)(stack->top->content));
}

void	stack_clear(const t_stack *stack)
{
	t_list	*node;
	t_list	*next;

	node = stack->top;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	set_stack_top(&(stack->top), NULL);
	add_size(&(stack->size), -stack->size);
}

int	stack_is_empty(const t_stack *stack)
{
	return (stack->size == 0);
}
