/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list_public_utils.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:11:41 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/10 18:42:01 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list_private.h"
#include "doubly_linked_list_public.h"

t_stack_value	get_node_content(t_stack_node *node)
{
	if (node == NULL)
		return (NULL);
	return (node->content);
}

t_stack_node	*get_next_node(t_stack_node *node)
{
	if (node == NULL)
		return (NULL);
	return (node->next);
}

t_stack_node	*get_prev_node(t_stack_node *node)
{
	if (node == NULL)
		return (NULL);
	return (node->prev);
}

void	set_next_node(t_stack_node *node, t_stack_node *next)
{
	if (node == NULL)
		return ;
	node->next = next;
}

void	set_prev_node(t_stack_node *node, t_stack_node *prev)
{
	if (node == NULL)
		return ;
	node->prev = prev;
}
