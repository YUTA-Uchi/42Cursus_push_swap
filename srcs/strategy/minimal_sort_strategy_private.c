/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimal_sort_strategy_private.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:54:57 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/05 18:39:46 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

void	sort_two(t_sort_solver *solver, t_stack *stack)
{
	if (stack->name == 'a')
	{
		if (*(solver->stack_a->peek(solver->stack_a)) \
			> *(t_stack_content)(solver->stack_a->top->next->content))
			solver->ops->sa(solver->stack_a);
		solver->ops->ra(solver->stack_a);
		solver->ops->ra(solver->stack_a);
	}
	else
	{
		if (*(solver->stack_b->peek(solver->stack_b)) \
			> *(t_stack_content)(solver->stack_b->top->next->content))
			solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
	}
}

bool	is_minimal_sort(t_sort_solver *solver, int size)
{
	bool	minimal;

	minimal = true;
	if (size <= 1)
		return (minimal);
	else if (size == 2)
		return (sort_two(solver, solver->stack_a), minimal);
	else if (size == 3)
		return (sort_three(solver), minimal);
	else if (size == 4)
		return (sort_four(solver), minimal);
	else if (size == 5)
		return (sort_five(solver), minimal);
	else if (size == 6)
		return (sort_six(solver), minimal);
	else
		minimal = false;
	return (minimal);
}

void	sort_four_distance_2(t_sort_solver *solver)
{
	// if (solver->stack_a->size == 4)
	// {
	// 	solver->ops->rra(solver->stack_a);
	// 	solver->ops->rra(solver->stack_a);
	// 	solver->ops->pb(solver->stack_b, solver->stack_a);
	// 	sort_three(solver);
	// 	solver->ops->pa(solver->stack_a, solver->stack_b);
	// }
	// else
	// {
	// 	solver->ops->ra(solver->stack_a);
	// 	solver->ops->sa(solver->stack_a);
	// 	solver->ops->pb(solver->stack_b, solver->stack_a);
	// 	solver->ops->rra(solver->stack_a);
	// 	sort_three(solver);
	// 	solver->ops->pa(solver->stack_a, solver->stack_b);
	// }
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->ra(solver->stack_a);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	sort_three_stack_b(solver);
}

void	sort_four_distance_3(t_sort_solver *solver)
{
	// if (solver->stack_a->size == 4)
	// {
	// 	solver->ops->rra(solver->stack_a);
	// 	solver->ops->pb(solver->stack_b, solver->stack_a);
	// 	sort_three(solver);
	// 	solver->ops->pa(solver->stack_a, solver->stack_b);
	// }
	// else
	// {
	// 	solver->ops->ra(solver->stack_a);
	// 	solver->ops->ra(solver->stack_a);
	// 	solver->ops->sa(solver->stack_a);
	// 	solver->ops->pb(solver->stack_b, solver->stack_a);
	// 	solver->ops->rra(solver->stack_a);
	// 	solver->ops->rra(solver->stack_a);
	// 	sort_three(solver);
	// 	solver->ops->pa(solver->stack_a, solver->stack_b);
	// }
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->ra(solver->stack_a);
	sort_three_stack_b(solver);
}

void	sort_four(t_sort_solver *solver)
{
	int	distance_to_min;

	distance_to_min = get_distance_to_min(solver->stack_a, 4);
	if (distance_to_min == 0)
	{
		solver->ops->ra(solver->stack_a);
		sort_three(solver);
	}
	else if (distance_to_min == 1)
	{
		solver->ops->sa(solver->stack_a);
		solver->ops->ra(solver->stack_a);
		sort_three(solver);
	}
	else if (distance_to_min == 2)
	{
		sort_four_distance_2(solver);
	}
	else
	{
		sort_four_distance_3(solver);
	}
}

void	sort_four_stack_b(t_sort_solver *solver)
{
	int	distance_to_min;

	distance_to_min = get_distance_to_min(solver->stack_b, 4);
	if (distance_to_min == 0)
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		sort_three_stack_b(solver);
	}
	else if (distance_to_min == 1)
	{
		solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		sort_three_stack_b(solver);
	}
	else if (distance_to_min == 2)
	{
		solver->ops->rrb(solver->stack_b);
		solver->ops->rrb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		sort_three_stack_b(solver);
	}
	else
	{
		solver->ops->rrb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		sort_three_stack_b(solver);
	}
}

void	sort_five_distance_2(t_sort_solver *solver)
{
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->ra(solver->stack_a);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	sort_four_stack_b(solver);
}

void	sort_five_distance_3(t_sort_solver *solver)
{
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->ra(solver->stack_a);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	sort_four_stack_b(solver);
}

void	sort_five_distance_4(t_sort_solver *solver)
{
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->ra(solver->stack_a);
	sort_four_stack_b(solver);
}

void	sort_five(t_sort_solver *solver)
{
	int	distance_to_min;

	distance_to_min = get_distance_to_min(solver->stack_a, 5);
	if (distance_to_min == 0)
	{
		solver->ops->ra(solver->stack_a);
		sort_four(solver);
	}
	else if (distance_to_min == 1)
	{
		solver->ops->sa(solver->stack_a);
		solver->ops->ra(solver->stack_a);
		sort_four(solver);
	}
	else if (distance_to_min == 2)
		sort_five_distance_2(solver);
	else if (distance_to_min == 3)
		sort_four_distance_3(solver);
	else
		sort_five_distance_4(solver);
}

void	sort_five_stack_b(t_sort_solver *solver)
{
	int	distance_to_min;

	distance_to_min = get_distance_to_min(solver->stack_b, 5);
	if (distance_to_min == 0)
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		sort_four_stack_b(solver);
	}
	else if (distance_to_min == 1)
	{
		solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		sort_four_stack_b(solver);
	}
	else if (distance_to_min == 2)
	{
		solver->ops->rrb(solver->stack_b);
		solver->ops->rrb(solver->stack_b);
		solver->ops->rrb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		sort_four_stack_b(solver);
	}
	else if (distance_to_min == 3)
	{
		solver->ops->rrb(solver->stack_b);
		solver->ops->rrb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		sort_four_stack_b(solver);
	}
	else
	{
		solver->ops->rrb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		sort_four_stack_b(solver);
	}
}

void	sort_six(t_sort_solver *solver)
{
	int	distance_to_min;

	distance_to_min = get_distance_to_min(solver->stack_a, 6);
	if (distance_to_min == 0)
	{
		solver->ops->ra(solver->stack_a);
		sort_five(solver);
	}
	else if (distance_to_min == 1)
	{
		solver->ops->sa(solver->stack_a);
		solver->ops->ra(solver->stack_a);
		sort_five(solver);
	}
	else if (distance_to_min == 2)
	{
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->ra(solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		sort_five_stack_b(solver);
	}
	else if (distance_to_min == 3)
	{
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->ra(solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		sort_five_stack_b(solver);
	}
	else if (distance_to_min == 4)
	{
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->ra(solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		sort_five_stack_b(solver);
	}
	else
	{
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->ra(solver->stack_a);
		sort_five_stack_b(solver);
	}
}

void	sort_six_stack_b(t_sort_solver *solver)
{
	int	distance_to_min;

	distance_to_min = get_distance_to_min(solver->stack_b, 6);
	if (distance_to_min == 0)
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		sort_five_stack_b(solver);
	}
	else if (distance_to_min == 1)
	{
		solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		sort_five_stack_b(solver);
	}
	else if (distance_to_min == 2)
	{
		solver->ops->rb(solver->stack_b);
		solver->ops->rb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		sort_five_stack_b(solver);
	}
	else if (distance_to_min == 3)
	{
		solver->ops->rrb(solver->stack_b);
		solver->ops->rrb(solver->stack_b);
		solver->ops->rrb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		sort_five_stack_b(solver);
	}
	else if (distance_to_min == 4)
	{
		solver->ops->rrb(solver->stack_b);
		solver->ops->rrb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		sort_five_stack_b(solver);
	}
	else
	{
		solver->ops->rrb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
		sort_five_stack_b(solver);
	}
}
