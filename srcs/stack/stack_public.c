/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_public.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:13:17 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/01/29 20:06:00 by yuuchiya         ###   ########.fr       */
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
	new_stack->peek = stack_peek;
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
