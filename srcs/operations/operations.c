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

t_operations	*operations_create(void)
{
	t_operations	*new_ps;

	new_ps = malloc(sizeof(t_operations));
	if (!new_ps)
		return (NULL);
	new_ps->swap = swap;
	new_ps->ss = swap_ab;
	new_ps->push = push;
	new_ps->rotate = rotate;
	new_ps->rr = rotate_ab;
	new_ps->reverse_rotate = reverse_rotate;
	new_ps->rrr = reverse_rotate_ab;
	return (new_ps);
}

void	operations_destroy(t_operations *ps)
{
	free(ps);
}
