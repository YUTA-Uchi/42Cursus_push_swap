/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_private_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:23:53 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/09 15:23:55 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_private.h"

void	add_size(int *size, int add_num)
{
	*size += add_num;
}

void	set_stack_top(t_list **self_top, t_list *top)
{
	*self_top = top;
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
		ft_printf(STDOUT_FILENO, "%d\n", *(t_stack_node)(node->content));
		node = node->next;
	}
}
