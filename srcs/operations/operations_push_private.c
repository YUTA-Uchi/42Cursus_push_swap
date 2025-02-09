/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push_private.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:24:20 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/09 15:24:21 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_private.h"

void	push_a(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return ;
	a->push(a, b->pop(b));
	ft_printf(STDOUT_FILENO, "pa\n");
}

void	push_b(t_stack *b, t_stack *a)
{
	if (a->size == 0)
		return ;
	b->push(b, a->pop(a));
	ft_printf(STDOUT_FILENO, "pb\n");
}
