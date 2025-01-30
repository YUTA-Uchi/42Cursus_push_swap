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

void	stack_push(t_stack *stack, t_stack_content content)
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

t_stack_content	stack_pop(t_stack *stack)
{
	t_list			*node;
	t_stack_content	content;

	if (stack->size == 0)
		return (0);
	node = stack->top;
	content = (t_stack_content)(node->content);
	set_stack_top(&(stack->top), node->next);
	free(node);
	add_size(&(stack->size), -1);
	return (content);
}

t_stack_content	stack_peek(t_stack *stack)
{
	if (stack->size == 0)
		return (0);
	return ((t_stack_content)(stack->top->content));
}

void	stack_clear(t_stack *stack)
{
	ft_lstclear(&(stack->top), free);
	add_size(&(stack->size), -stack->size);
}

void	stack_print(t_stack *stack)
{
	t_list	*node;

	ft_printf(STDOUT_FILENO, "stack %c:\n", stack->name);
	node = stack->top;
	while (node)
	{
		ft_printf(STDOUT_FILENO, "%d\n", *(t_stack_content)(node->content));
		node = node->next;
	}
}

