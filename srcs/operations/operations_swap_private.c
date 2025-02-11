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
	a->swap(a);
	ft_printf(STDOUT_FILENO, "sa\n");
}

void	swap_b(t_stack *b)
{
	b->swap(b);
	ft_printf(STDOUT_FILENO, "sb\n");
}

void	swap_ab(t_stack *a, t_stack *b)
{
	a->swap(a);
	b->swap(b);
	ft_printf(STDOUT_FILENO, "ss\n");
}
