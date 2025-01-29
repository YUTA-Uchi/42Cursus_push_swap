/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:32:16 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/01/29 19:54:24 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_PRIVATE_H
# define STACK_PRIVATE_H

# include "stack_public.h"

void	stack_push(t_stack *stack, int content);
int		stack_pop(t_stack *stack);
int		stack_peek(t_stack *stack);
void	stack_clear(t_stack *stack);
void	stack_print(t_stack *stack);
// util
void	add_size(int *size, int add_num);
void	set_stack_top(t_list **self_top, t_list *top);
#endif