/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_public.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:13:17 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/10 16:26:30 by yuuchiya         ###   ########.fr       */
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
	new_stack->bottom = NULL;
	new_stack->size = 0;
	new_stack->name = name;
	new_stack->push = stack_push;
	new_stack->pop = stack_pop;
	new_stack->value = stack_value;
	new_stack->rotate = stack_rotate;
	new_stack->reverse_rotate = stack_reverse_rotate;
	new_stack->clear = stack_clear;
	new_stack->add_size = add_size;
	return (new_stack);
}

void	stack_destroy(t_stack *stack)
{
	stack->clear(stack);
	free(stack);
}

bool	is_sorted(t_stack *stack)
{
	t_stack_node	*node;

	node = stack->top;
	while (node && get_next_node(node))
	{
		if (*(get_node_content(node)) \
			> *(get_node_content(get_next_node(node))))
			return (false);
		node = get_next_node(node);
	}
	return (true);
}
