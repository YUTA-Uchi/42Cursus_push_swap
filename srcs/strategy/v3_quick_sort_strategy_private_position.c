/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_quick_sort_strategy_private_position.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:52:57 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/11 12:19:04 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_solver_public.h"
#include "sort_strategy_private.h"

t_stack_pos	get_max_pos(t_stack_pos pos)
{
	if (pos == TOP_A)
		return (BOTTOM_A);
	else if (pos == BOTTOM_A)
		return (TOP_A);
	else if (pos == TOP_B)
		return (TOP_A);
	else
		return (TOP_A);
}

t_stack_pos	get_mid_pos(t_stack_pos pos)
{
	if (pos == TOP_A)
		return (TOP_B);
	else if (pos == BOTTOM_A)
		return (TOP_B);
	else if (pos == TOP_B)
		return (BOTTOM_A);
	else
		return (BOTTOM_A);
}

t_stack_pos	get_min_pos(t_stack_pos pos)
{
	if (pos == TOP_A)
		return (BOTTOM_B);
	else if (pos == BOTTOM_A)
		return (BOTTOM_B);
	else if (pos == TOP_B)
		return (BOTTOM_B);
	else
		return (TOP_B);
}

t_stack_pos	optimize_position(t_sort_solver *solver, int size, t_stack_pos pos)
{
	if (pos == BOTTOM_A && solver->stack_a->size == size)
		return (TOP_A);
	else if (pos == BOTTOM_B && solver->stack_b->size == size)
		return (TOP_B);
	return (pos);
}

void	move_to_top_a(t_sort_solver *solver, t_stack_pos pos, int size)
{
	int	i;

	i = 0;
	if (pos == BOTTOM_A)
	{
		while (i++ < size)
			solver->ops->rra(solver->stack_a);
	}
	else if (pos == TOP_B)
	{
		while (i++ < size)
			solver->ops->pa(solver->stack_a, solver->stack_b);
	}
	else if (pos == BOTTOM_B)
	{
		while (i++ < size)
		{
			solver->ops->rrb(solver->stack_b);
			solver->ops->pa(solver->stack_a, solver->stack_b);
		}
	}
}
