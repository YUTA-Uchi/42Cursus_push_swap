/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_stack_b_strategy.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:07:46 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/07 17:27:54 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

// void	sort_four_stack_b(t_sort_solver *solver)
// {
// 	int	distance_to_min;

// 	distance_to_min = get_distance_to_min(solver->stack_b, 4);
// 	if (distance_to_min == 0)
// 	{
// 		solver->ops->pa(solver->stack_a, solver->stack_b);
// 		solver->ops->ra(solver->stack_a);
// 		sort_three_stack_b(solver);
// 	}
// 	else if (distance_to_min == 1)
// 	{
// 		solver->ops->sb(solver->stack_b);
// 		solver->ops->pa(solver->stack_a, solver->stack_b);
// 		solver->ops->ra(solver->stack_a);
// 		sort_three_stack_b(solver);
// 	}
// 	else if (distance_to_min == 2)
// 	{
// 		solver->ops->rrb(solver->stack_b);
// 		solver->ops->rrb(solver->stack_b);
// 		solver->ops->pa(solver->stack_a, solver->stack_b);
// 		solver->ops->ra(solver->stack_a);
// 		sort_three_stack_b(solver);
// 	}
// 	else
// 	{
// 		solver->ops->rrb(solver->stack_b);
// 		solver->ops->pa(solver->stack_a, solver->stack_b);
// 		solver->ops->ra(solver->stack_a);
// 		sort_three_stack_b(solver);
// 	}
// }

static void	sort_four_stack_b_distance_1(t_sort_solver *solver, int *b)
{
	solver->ops->pa(solver->stack_a, solver->stack_b);
	solver->ops->pa(solver->stack_a, solver->stack_b);
	solver->ops->ra(solver->stack_a);
	if (b[0] < b[2] && b[0] > b[3])
		solver->ops->rr(solver->stack_a, solver->stack_b);
	else
		solver->ops->ra(solver->stack_a);
	if (b[0] < b[2] && b[0] < b[3])
	{
		solver->ops->ra(solver->stack_a);
		sort_two(solver, solver->stack_b);
	}
	else if (b[0] > b[2] && b[0] > b[3])
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		if (b[2] < b[3])
		{
			solver->ops->ra(solver->stack_a);
			solver->ops->pa(solver->stack_a, solver->stack_b);
			solver->ops->ra(solver->stack_a);
			solver->ops->ra(solver->stack_a);
		}
		else
		{
			solver->ops->pa(solver->stack_a, solver->stack_b);
			solver->ops->ra(solver->stack_a);
			solver->ops->ra(solver->stack_a);
			solver->ops->ra(solver->stack_a);
		}
	}
	else
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		solver->ops->ra(solver->stack_a);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
	}
}

static void	sort_four_stack_b_distance_2(t_sort_solver *solver, int *b)
{
	if (b[0] < b[2] && b[0] < b[3])
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		solver->ops->ra(solver->stack_a);
		sort_two(solver, solver->stack_b);
	}
	else if (b[0] > b[2] && b[0] > b[3])
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		if (b[1] < b[3])
		{
			solver->ops->ra(solver->stack_a);
			solver->ops->pa(solver->stack_a, solver->stack_b);
			solver->ops->ra(solver->stack_a);
			solver->ops->ra(solver->stack_a);
		}
		else
		{
			solver->ops->pa(solver->stack_a, solver->stack_b);
			solver->ops->ra(solver->stack_a);
			solver->ops->ra(solver->stack_a);
			solver->ops->ra(solver->stack_a);
		}
	}
	else
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		if (b[1] < b[3])
		{
			solver->ops->pa(solver->stack_a, solver->stack_b);
			solver->ops->ra(solver->stack_a);
			solver->ops->ra(solver->stack_a);
			solver->ops->ra(solver->stack_a);
			solver->ops->pa(solver->stack_a, solver->stack_b);
			solver->ops->ra(solver->stack_a);
		}
		else
		{
			solver->ops->ss(solver->stack_a, solver->stack_b);
			solver->ops->pa(solver->stack_a, solver->stack_b);
			solver->ops->pa(solver->stack_a, solver->stack_b);
			solver->ops->ra(solver->stack_a);
			solver->ops->ra(solver->stack_a);
			solver->ops->ra(solver->stack_a);
			solver->ops->ra(solver->stack_a);
		}
	}
}

static void	sort_four_stack_b_distance_3(t_sort_solver *solver, int *b)
{
	if (b[0] < b[1] && b[0] < b[2])
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ss(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		solver->ops->ra(solver->stack_a);
		if (b[1] < b[2])
		{
			solver->ops->ra(solver->stack_a);
			solver->ops->pa(solver->stack_a, solver->stack_b);
			solver->ops->ra(solver->stack_a);
		}
		else
		{
			solver->ops->pa(solver->stack_a, solver->stack_b);
			solver->ops->ra(solver->stack_a);
			solver->ops->ra(solver->stack_a);
		}
	}
	else if (b[0] > b[1] && b[0] > b[2])
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		if (b[1] < b[2])
			solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		solver->ops->ra(solver->stack_a);
		solver->ops->ra(solver->stack_a);
		solver->ops->ra(solver->stack_a);
	}
	else
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		if (b[1] < b[2])
		{
			solver->ops->sb(solver->stack_b);
			solver->ops->pa(solver->stack_a, solver->stack_b);
			solver->ops->ra(solver->stack_a);
			solver->ops->ra(solver->stack_a);
			solver->ops->ra(solver->stack_a);
			solver->ops->pa(solver->stack_a, solver->stack_b);
			solver->ops->ra(solver->stack_a);
		}
		else
		{
			solver->ops->ss(solver->stack_a, solver->stack_b);
			solver->ops->pa(solver->stack_a, solver->stack_b);
			solver->ops->ra(solver->stack_a);
			solver->ops->pa(solver->stack_a, solver->stack_b);
			solver->ops->ra(solver->stack_a);
			solver->ops->ra(solver->stack_a);
			solver->ops->ra(solver->stack_a);
		}
	}
}


void	sort_four_stack_b(t_sort_solver *solver)
{
	int		i;
	int		distance_to_min;
	int		b[4];
	t_list	*top;

	i = 0;
	top = solver->stack_b->top;
	while (i < 4)
	{
		b[i++] = *(t_stack_content)(top->content);
		top = top->next;
	}
	distance_to_min = get_distance_to_min(solver->stack_b, 4);
	if (distance_to_min == 0)
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		sort_three_stack_b(solver);
	}
	else if (distance_to_min == 1)
		sort_four_stack_b_distance_1(solver, b);
	else if (distance_to_min == 2)
		sort_four_stack_b_distance_2(solver, b);
	else
		sort_four_stack_b_distance_3(solver, b);
}
