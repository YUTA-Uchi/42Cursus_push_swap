/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_public_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:29:58 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/11 12:14:52 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_public.h"
#include "stack_private.h"

int	get_distance_to_max_from_top(t_stack *stack, int size)
{
	t_stack_node	*node;
	int				max;
	int				distance;
	int				i;

	node = stack->top;
	max = *(get_node_content(node));
	distance = 0;
	i = 0;
	while (node && (i < size))
	{
		if (*(get_node_content(node)) > max)
		{
			max = *(get_node_content(node));
			distance = i;
		}
		node = get_next_node(node);
		i++;
	}
	return (distance);
}

int	get_distance_to_max_from_bottom(t_stack *stack, int size)
{
	t_stack_node	*node;
	int				max;
	int				distance;
	int				i;

	node = stack->bottom;
	max = *(get_node_content(node));
	distance = 0;
	i = 0;
	while (node && (i < size))
	{
		if (*(get_node_content(node)) > max)
		{
			max = *(get_node_content(node));
			distance = i;
		}
		node = get_prev_node(node);
		i++;
	}
	return (distance);
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
