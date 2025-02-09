/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:32:16 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/09 12:54:42 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_PRIVATE_H
# define STACK_PRIVATE_H

# include "stack_public.h"

void				stack_push(t_stack *stack, t_stack_node content);
t_stack_node		stack_pop(t_stack *stack);
int					stack_value(t_stack *stack, int index);
void				stack_rotate(t_stack *stack);
void				stack_reverse_rotate(t_stack *stack);
// util
void				add_size(int *size, int add_num);
void				set_stack_top(t_list **self_top, t_list *top);
void				stack_clear(t_stack *stack);
void				stack_print(t_stack *stack);
#endif