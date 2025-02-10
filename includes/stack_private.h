/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:32:16 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/10 16:29:17 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_PRIVATE_H
# define STACK_PRIVATE_H

# include "stack_public.h"

void				stack_push(t_stack *stack, t_stack_value content);
t_stack_value		stack_pop(t_stack *stack);
int					stack_value(t_stack *stack, int index, \
								t_stack_search_from from);
void				stack_rotate(t_stack *stack);
void				stack_reverse_rotate(t_stack *stack);
// util
void				add_size(int *size, int add_num);
void				set_stack_top(t_stack_node **self_top, t_stack_node *top);
void				set_stack_bottom(t_stack_node **self_bottom, \
										t_stack_node *bottom);
void				stack_clear(t_stack *stack);

#endif