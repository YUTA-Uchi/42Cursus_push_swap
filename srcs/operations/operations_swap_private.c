/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_private.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:24:46 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/10 12:17:33 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_private.h"

void	swap_a(t_stack *a)
{
	t_stack_value	first;
	t_stack_value	second;

	if (a->size < 2)
		return ;
	first = a->pop(a);
	second = a->pop(a);
	a->push(a, first);
	a->push(a, second);
	ft_printf(STDOUT_FILENO, "sa\n");
}

void	swap_b(t_stack *b)
{
	t_stack_value	first;
	t_stack_value	second;

	if (b->size < 2)
		return ;
	first = b->pop(b);
	second = b->pop(b);
	b->push(b, first);
	b->push(b, second);
	ft_printf(STDOUT_FILENO, "sb\n");
}

void	swap_ab(t_stack *a, t_stack *b)
{
	t_stack_value	first;
	t_stack_value	second;

	if (a->size < 2 || b->size < 2)
		return ;
	first = a->pop(a);
	second = a->pop(a);
	a->push(a, first);
	a->push(a, second);
	first = b->pop(b);
	second = b->pop(b);
	b->push(b, first);
	b->push(b, second);
	ft_printf(STDOUT_FILENO, "ss\n");
}
