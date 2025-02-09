/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_strategy_private_utils.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:43:58 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/09 15:44:34 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

static int	get_median(int *values, int size)
{
	int		i;
	int		j;
	int		key;
	long	sum;

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
	{
		sum = (long)values[(size / 2) - 1] + (long)values[size / 2];
		return (sum / 2);
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
	if (stack->top == NULL)
		return (0);
	current = stack->top;
	while (current != NULL && count < size)
	{
		values[count++] = *(t_stack_node)current->content;
		current = current->next;
	}
	median = get_median(values, size);
	free(values);
	return (median);
}
