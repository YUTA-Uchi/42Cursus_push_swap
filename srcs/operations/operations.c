/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:04:21 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/01/29 20:02:14 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_public.h"
#include "operations_private.h"

t_push_swap	*push_swap_create(void)
{
	t_push_swap	*new_ps;

	new_ps = malloc(sizeof(t_push_swap));
	if (!new_ps)
		return (NULL);
	new_ps->stack_a = stack_create('a');
	new_ps->stack_b = stack_create('b');
	new_ps->sa = swap_a;
	new_ps->sb = swap_b;
	new_ps->ss = swap_ab;
	new_ps->pa = push_a;
	new_ps->pb = push_b;
	new_ps->ra = rotate_a;
	new_ps->rb = rotate_b;
	new_ps->rr = rotate_ab;
	new_ps->rra = reverse_rotate_a;
	new_ps->rrb = reverse_rotate_b;
	new_ps->rrr = reverse_rotate_ab;
	return (new_ps);
}

void	push_swap_destroy(t_push_swap *ps)
{
	stack_destroy(ps->stack_a);
	stack_destroy(ps->stack_b);
	free(ps);
}
