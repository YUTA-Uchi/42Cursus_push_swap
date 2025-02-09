/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate_private.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:24:28 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/09 15:24:33 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_private.h"

void	reverse_rotate_a(t_stack *a)
{
	a->reverse_rotate(a);
	ft_printf(STDOUT_FILENO, "rra\n");
}

void	reverse_rotate_b(t_stack *b)
{
	b->reverse_rotate(b);
	ft_printf(STDOUT_FILENO, "rrb\n");
}

void	reverse_rotate_ab(t_stack *a, t_stack *b)
{
	a->reverse_rotate(a);
	b->reverse_rotate(b);
	ft_printf(STDOUT_FILENO, "rrr\n");
}
