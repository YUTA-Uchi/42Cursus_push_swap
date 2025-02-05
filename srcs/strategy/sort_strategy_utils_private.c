/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_strategy_utils_private.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:49:07 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/05 11:09:38 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

int	get_median(int *values, int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
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
	if (size % 2)
		return (values[size / 2]);
	else
		return ((values[(size / 2) - 1] + values[size / 2]) / 2);
}

void	minimal_restore(t_sort_solver *solver, t_stack *stack, int size_remain)
{
	int	i;
	int	half;

	i = 0;
	half = stack->size / 2;
	if (half > size_remain)
	{
		while (i++ < size_remain)
		{
			if (stack->name == 'a')
				solver->ops->rra(stack);
			else
				solver->ops->rrb(stack);
		}
	}
	else
	{
		while (i++ < stack->size - size_remain)
		{
			if (stack->name == 'a')
				solver->ops->ra(stack);
			else
				solver->ops->rb(stack);
		}
	}
}

int	get_pivot(t_stack *stack, int size)
{
	int		*values;
	t_list	*current;
	int		count;
	int		median;

	values = (int *)malloc(sizeof(int) * size);
	count = 0;
	if (stack->peek(stack) == NULL)
		return (0);
	current = stack->top;
	while (current != NULL && count < size)
	{
		values[count++] = *(t_stack_content)current->content;
		current = current->next;
	}
	median = get_median(values, size);
	free(values);
	return (median);
}
