/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list_public.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:41:22 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/10 13:26:02 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list_private.h"
#include "doubly_linked_list_public.h"

t_stack_node	*create_node(void *content)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	destroy_node(t_stack_node *node, void (*del)(void *))
{
	if (node == NULL)
		return ;
	del(node->content);
	free(node);
}

void	clear_nodes(t_stack_node **top, t_stack_node **bottom, \
					void (*del)(void *))
{
	t_stack_node	*current;
	t_stack_node	*next_node;

	if (top == NULL || *top == NULL)
		return ;
	current = *top;
	while (current != NULL)
	{
		next_node = current->next;
		destroy_node(current, del);
		current = next_node;
	}
	*top = NULL;
	*bottom = NULL;
}

void	add_node_front(t_stack_node **top, t_stack_node **bottom, \
						t_stack_node *new_node)
{
	if (top == NULL || new_node == NULL)
		return ;
	if (*top == NULL || *bottom == NULL)
	{
		*top = new_node;
		*bottom = new_node;
		return ;
	}
	new_node->next = *top;
	(*top)->prev = new_node;
	*top = new_node;
}

void	add_node_back(t_stack_node **top, t_stack_node **bottom, \
						t_stack_node *new_node)
{
	if (top == NULL || new_node == NULL)
		return ;
	if (*top == NULL || *bottom == NULL)
	{
		*top = new_node;
		*bottom = new_node;
		return ;
	}
	new_node->prev = *bottom;
	(*bottom)->next = new_node;
	*bottom = new_node;
}
