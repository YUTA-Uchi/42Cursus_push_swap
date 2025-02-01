/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:04:21 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/01 15:07:38 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_public.h"
#include "operations_private.h"

t_operations	*operations_create(void)
{
	t_operations	*new_ps;

	new_ps = malloc(sizeof(t_operations));
	if (!new_ps)
		return (NULL);
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

void	operations_destroy(t_operations *ps)
{
	free(ps);
}
