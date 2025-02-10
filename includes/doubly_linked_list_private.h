/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list_private.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:32:00 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/10 18:44:31 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_LINKED_LIST_PRIVATE_H
# define DOUBLY_LINKED_LIST_PRIVATE_H

# include "doubly_linked_list_public.h"

struct s_stack_node
{
	t_stack_node	*next;
	t_stack_node	*prev;
	void			*content;
};

#endif
