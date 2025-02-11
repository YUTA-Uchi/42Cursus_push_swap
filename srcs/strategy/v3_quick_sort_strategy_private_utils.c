/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_quick_sort_strategy_private_utils.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:49:26 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/11 11:51:53 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_solver_public.h"
#include "sort_strategy_private.h"

void	get_two_tri_partition_pivots(int *values, t_recursion_data *rec_data)
{
	int		i;
	int		j;
	int		key;

	i = 1;
	while (i < rec_data->size)
	{
		key = values[i];
		j = i - 1;
		while (j >= 0 && values[j] > key)
		{
			values[j + 1] = values[j];
			j--;
		}
		values[j + 1] = key;
		i++;
	}
	rec_data->pivot[SPLIT_MIN] = values[rec_data->size / 3];
	rec_data->pivot[SPLIT_MID] = values[(2 * rec_data->size) / 3];
}

void	get_pivots(t_stack *stack, t_recursion_data *rec_data)
{
	int	*values;
	int	i;

	values = (int *)malloc(sizeof(int) * rec_data->size);
	if (!values)
		return ;
	i = 0;
	while (i < rec_data->size)
	{
		if (rec_data->pos == TOP_A || rec_data->pos == TOP_B)
			values[i] = stack->value(stack, i, TOP);
		else
			values[i] = stack->value(stack, i, BOTTOM);
		i++;
	}
	get_two_tri_partition_pivots(values, rec_data);
	free(values);
}

void	move_to_min(t_sort_solver *solver, \
					t_recursion_data *rec_data)
{
	rec_data->next_size[2]++;
	if (rec_data->pos == TOP_A)
	{
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->rb(solver->stack_b);
	}
	else if (rec_data->pos == BOTTOM_A)
	{
		solver->ops->rra(solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
		solver->ops->rb(solver->stack_b);
	}
	else if (rec_data->pos == TOP_B)
		solver->ops->rb(solver->stack_b);
	else if (rec_data->pos == BOTTOM_B)
		solver->ops->rrb(solver->stack_b);
}

void	move_to_mid(t_sort_solver *solver, \
					t_recursion_data *rec_data)
{
	rec_data->next_size[1]++;
	if (rec_data->pos == TOP_A)
	{
		solver->ops->pb(solver->stack_b, solver->stack_a);
	}
	else if (rec_data->pos == BOTTOM_A)
	{
		solver->ops->rra(solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
	}
	else if (rec_data->pos == TOP_B)
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
	}
	else if (rec_data->pos == BOTTOM_B)
	{
		solver->ops->rrb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
		solver->ops->ra(solver->stack_a);
	}
}

void	move_to_max(t_sort_solver *solver, \
					t_recursion_data *rec_data)
{
	rec_data->next_size[0]++;
	if (rec_data->pos == TOP_A)
	{
		solver->ops->ra(solver->stack_a);
	}
	else if (rec_data->pos == BOTTOM_A)
	{
		solver->ops->rra(solver->stack_a);
	}
	else if (rec_data->pos == TOP_B)
	{
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}
	else if (rec_data->pos == BOTTOM_B)
	{
		solver->ops->rrb(solver->stack_b);
		solver->ops->pa(solver->stack_a, solver->stack_b);
	}	
}
