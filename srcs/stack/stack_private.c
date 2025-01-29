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

void	stack_push(t_stack *stack, int content)
{
	t_list	*new_node;

	new_node = ft_lstnew(&content);
	if (!new_node)
		return ;
	ft_printf(STDOUT_FILENO, "stackpush %p\n", stack->top);
	ft_lstadd_front(&(stack->top), new_node);
	add_size(&(stack->size), 1);
}

int	stack_pop(t_stack *stack)
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

int	stack_peek(t_stack *stack)
{
	if (stack->size == 0)
		return (0);
	return (*(int *)(stack->top->content));
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
		ft_printf(STDOUT_FILENO, "%d:%p\n", *(int *)(node->content), node);	
		node = node->next;
	}
}

