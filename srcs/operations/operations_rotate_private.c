/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate_private.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:24:38 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/09 15:24:39 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_private.h"

void	rotate_a(t_stack *a)
{
	a->rotate(a);
	ft_printf(STDOUT_FILENO, "ra\n");
}

void	rotate_b(t_stack *b)
{
	b->rotate(b);
	ft_printf(STDOUT_FILENO, "rb\n");
}

void	rotate_ab(t_stack *a, t_stack *b)
{
	a->rotate(a);
	b->rotate(b);
	ft_printf(STDOUT_FILENO, "rr\n");
}
