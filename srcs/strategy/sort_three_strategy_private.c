/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_strategy_private.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:54:18 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/05 17:22:55 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

void	sort_three_distance_0(t_sort_solver *solver)
{
	// if (*(t_stack_content)(solver->stack_a->top->next->content) 
	// 	> *(t_stack_content)(solver->stack_a->top->next->next->content))
	// {
	// 	if (solver->stack_a->size == 3)
	// 	{
	// 		solver->ops->rra(solver->stack_a);
	// 		solver->ops->sa(solver->stack_a);
	// 		return ;
	// 	}
	// 	solver->ops->pb(solver->stack_b, solver->stack_a);
	// 	sort_two(solver, solver->stack_a);
	// 	solver->ops->pa(solver->stack_a, solver->stack_b);
	// }
	// else
	// {
	// 	return ;
	// }
	solver->ops->ra(solver->stack_a);
	sort_two(solver, solver->stack_a);
}

void	sort_three_distance_1(t_sort_solver *solver)
{
	solver->ops->sa(solver->stack_a);
	solver->ops->ra(solver->stack_a);
	sort_two(solver, solver->stack_a);
	// if (*(t_stack_content)(solver->stack_a->top->next->content) 
	// 	> *(t_stack_content)(solver->stack_a->top->next->next->content))
	// {
	// 	solver->ops->pb(solver->stack_b, solver->stack_a);
	// 	sort_two(solver, solver->stack_a);
	// 	solver->ops->pa(solver->stack_a, solver->stack_b);
	// }
	// else
	// {
	// 	return ;
	// }
}

void	sort_three_distance_2(t_sort_solver *solver)
{
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->pb(solver->stack_b, solver->stack_a);
	solver->ops->ra(solver->stack_a);
	sort_two(solver, solver->stack_b);
	// if (solver->stack_a->size == 3)
	// {
	// 	if (*(t_stack_content)(solver->stack_a->top->content) 
	// 		> *(t_stack_content)(solver->stack_a->top->next->content))
	// 		solver->ops->sa(solver->stack_a);
	// 	solver->ops->rra(solver->stack_a);
	// }
	// else
	// {
	// 	solver->ops->ra(solver->stack_a);
	// 	solver->ops->sa(solver->stack_a);
	// 	solver->ops->pb(solver->stack_b, solver->stack_a);
	// 	solver->ops->rra(solver->stack_a);
	// 	sort_two(solver, solver->stack_a);
	// 	solver->ops->pa(solver->stack_a, solver->stack_b);
	// }	
}


void	sort_three(t_sort_solver *solver)
{
	int	distance_to_min;

	distance_to_min = get_distance_to_min(solver->stack_a, 3);
	if (distance_to_min == 0)
		sort_three_distance_0(solver);
	else if (distance_to_min == 1)
		sort_three_distance_1(solver);
	else
	{
		sort_three_distance_2(solver);
	}
}
