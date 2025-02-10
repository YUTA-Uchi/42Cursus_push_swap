/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list_public.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:32:14 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/10 13:40:56 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_LINKED_LIST_PUBLIC_H
# define DOUBLY_LINKED_LIST_PUBLIC_H

# include <stdlib.h>

typedef struct s_stack_node	t_stack_node;
typedef int*				t_stack_value;

t_stack_node	*create_node(void *content);
void			destroy_node(t_stack_node *node, void (*del)(void *));
void			add_node_front(t_stack_node **top, t_stack_node **bottom, \
								t_stack_node *new_node);
void			add_node_back(t_stack_node **top, t_stack_node **bottom, \
								t_stack_node *new_node);
void			clear_nodes(t_stack_node **top, t_stack_node **bottom, \
							void (*del)(void *));
// utills
t_stack_value	get_node_content(t_stack_node *node);
void			set_node_content(t_stack_node *node, t_stack_value content);
t_stack_node	*get_next_node(t_stack_node *node);
t_stack_node	*get_prev_node(t_stack_node *node);

#endif