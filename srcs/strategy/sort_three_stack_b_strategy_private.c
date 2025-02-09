/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_stack_b_strategy_private.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:57:22 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/09 13:08:26 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

// void	sort_three_stack_b_distance_1(t_sort_solver *solver)
// {
// 	if (*(solver->stack_b->value(solver->stack_b)) 
// 			> *(t_stack_node)(solver->stack_b->top->next->next->content))
// 	{
// 		solver->ops->pa(solver->stack_a, solver->stack_b);
// 		solver->ops->pa(solver->stack_a, solver->stack_b);
// 		solver->ops->ra(solver->stack_a);
// 		solver->ops->pa(solver->stack_a, solver->stack_b);
// 		solver->ops->ra(solver->stack_a);
// 		solver->ops->ra(solver->stack_a);
// 	}
// 	else
// 	{
// 		solver->ops->pa(solver->stack_a, solver->stack_b);
// 		solver->ops->pa(solver->stack_a, solver->stack_b);
// 		solver->ops->ra(solver->stack_a);
// 		solver->ops->ra(solver->stack_a);
// 		solver->ops->pa(solver->stack_a, solver->stack_b);
// 		solver->ops->ra(solver->stack_a);
// 	}
// }

// void	sort_three_stack_b_distance_2(t_sort_solver *solver)
// {
// 	solver->ops->pa(solver->stack_a, solver->stack_b);
// 	if (*(solver->stack_a->value(solver->stack_a)) 
// 		> *(solver->stack_b->value(solver->stack_b)))
// 	{
// 		sort_two(solver, solver->stack_b);
// 		solver->ops->ra(solver->stack_a);
// 	}
// 	else
// 	{
// 		solver->ops->sb(solver->stack_b);
// 		solver->ops->pa(solver->stack_a, solver->stack_b);
// 		solver->ops->ra(solver->stack_a);
// 		solver->ops->ra(solver->stack_a);
// 		solver->ops->pa(solver->stack_a, solver->stack_b);
// 		solver->ops->ra(solver->stack_a);
// 	}
// }

void	sort_three_stack_b(t_sort_solver *solver)
{
	int	insert_position;

	solver->ops->pa(solver->stack_a, solver->stack_b);
	solver->ops->pa(solver->stack_a, solver->stack_b);
	if (solver->stack_a->value(solver->stack_a, 0) \
		> solver->stack_a->value(solver->stack_a, 1))
	{
		solver->ops->sa(solver->stack_a);
	}
	insert_position = get_insert_position(solver->stack_a \
					, solver->stack_b->value(solver->stack_b, 0) \
					, 3);
	minimal_move(solver, solver->stack_a, insert_position);
	solver->ops->pa(solver->stack_a, solver->stack_b);
	minimal_move(solver, solver->stack_a, 3 - insert_position);
}
