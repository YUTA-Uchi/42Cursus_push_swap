/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_private_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:23:53 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/10 16:30:32 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_private.h"

void	add_size(int *size, int add_num)
{
	*size += add_num;
}

void	set_stack_top(t_stack_node **self_top, t_stack_node *top)
{
	*self_top = top;
}

void	set_stack_bottom(t_stack_node **self_bottom, t_stack_node *bottom)
{
	*self_bottom = bottom;
}

void	stack_clear(t_stack *stack)
{
	clear_nodes(&(stack->top), &(stack->bottom), free);
	add_size(&(stack->size), -stack->size);
}

int	stack_value(t_stack *stack, int index, t_stack_search_from from)
{
	t_stack_node	*node;

	if (stack->size == 0)
		return (0);
	if (from == TOP)
		node = stack->top;
	else
		node = stack->bottom;
	while (node && index > 0)
	{
		if (from == TOP)
			node = get_next_node(node);
		else
			node = get_prev_node(node);
		index--;
	}
	return (*get_node_content(node));
}
