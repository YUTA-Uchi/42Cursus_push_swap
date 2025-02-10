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
