/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_strategy_private.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:26:51 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/10 14:03:55 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

static int	find_min(t_stack *stack)
{
	t_stack_node	*node;
	int				min;

	node = stack->top;
	min = *(get_node_content(node));
	while (node)
	{
		if (*(get_node_content(node)) < min)
			min = *(get_node_content(node));
		node = get_next_node(node);
	}
	return (min);
}

void	selection_sort(t_sort_solver *solver)
{
	int	min;

	if (solver->stack_a->size <= 1)
		return ;
	while (solver->stack_a->size > 0)
	{
		min = find_min(solver->stack_a);
		while (*(get_node_content(solver->stack_a->top)) != min)
			solver->ops->ra(solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
	}
	while (solver->stack_b->size > 0)
		solver->ops->pa(solver->stack_a, solver->stack_b);
}

void	selection_strategy_destroy(t_sort_strategy *strategy)
{
	free(strategy);
}
