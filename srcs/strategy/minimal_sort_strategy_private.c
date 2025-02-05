/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimal_sort_strategy_private.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:54:57 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/05 11:01:58 by yuuchiya         ###   ########.fr       */
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
	}
	else
	{
		if (*(solver->stack_b->peek(solver->stack_b)) \
			< *(t_stack_content)(solver->stack_b->top->next->content))
			solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
}


void	sort_three(t_sort_solver *solver)
{
	int	a;
	int	b;
	int	c;

	if (!solver->stack_a || !(solver->stack_a->top) || \
		!solver->stack_a->top->next || !solver->stack_a->top->next->next)
		return ;
	a = *(t_stack_content)(solver->stack_a->top->content);
	b = *(t_stack_content)(solver->stack_a->top->next->content);
	c = *(t_stack_content)(solver->stack_a->top->next->next->content);
	if (a > b && b < c && a < c)
		solver->ops->sa(solver->stack_a);
	else if (a > b && b > c)
	{
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->sa(solver->stack_a);
		solver->ops->ra(solver->stack_a);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->sa(solver->stack_a);
		solver->ops->rra(solver->stack_a);
	}
	else if (a > b && b < c && a > c)
	{
		solver->ops->sa(solver->stack_a);
		solver->ops->ra(solver->stack_a);
		solver->ops->sa(solver->stack_a);
		solver->ops->rra(solver->stack_a);
	}
	else if (a < b && b > c && a < c)
	{
		solver->ops->ra(solver->stack_a);
		solver->ops->sa(solver->stack_a);
		solver->ops->rra(solver->stack_a);
	}
	else if (a < b && b > c && a > c)
	{
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->sa(solver->stack_a);
		solver->ops->ra(solver->stack_a);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->rra(solver->stack_a);
	}
}

void	sort_three_stack_b(t_sort_solver *solver)
{
	int	a;
	int	b;
	int	c;

	if (!solver->stack_b || !(solver->stack_b->top) || \
		!solver->stack_b->top->next || !solver->stack_b->top->next->next)
		return ;
	a = *(t_stack_content)(solver->stack_b->top->content);
	b = *(t_stack_content)(solver->stack_b->top->next->content);
	c = *(t_stack_content)(solver->stack_b->top->next->next->content);
	if (a > b && a > c && c > b)
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
	else if (b > a && a > c)
	{
		solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
	else if (b > a && b > c && c > a)
	{
		solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
	else if (c > a && a > b)
	{
		solver->ops->rb(solver->stack_b);
		solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->rrb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
	else if (c > b && b > a)
	{
		solver->ops->rb(solver->stack_b);
		solver->ops->sb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->rrb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
	else
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
}
