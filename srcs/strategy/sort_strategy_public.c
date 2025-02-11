/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_strategy_public.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:46 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/11 14:30:20 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_public.h"
#include "sort_strategy_private.h"

t_recursion_data	*recursion_data_create(int size, t_stack_pos pos)
{
	t_recursion_data	*data;

	data = malloc(sizeof(t_recursion_data));
	if (!data)
		return (NULL);
	data->size = size;
	data->pos = pos;
	data->pivot[0] = 0;
	data->pivot[1] = 0;
	data->next_size[0] = 0;
	data->next_size[1] = 0;
	data->next_size[2] = 0;
	return (data);
}

void	recursion_data_destroy(t_recursion_data *data)
{
	free(data);
}

t_sort_strategy	*v3_quick_sort_strategy_create(void)
{
	t_v3_quick_strategy	*strategy;

	strategy = malloc(sizeof(t_v3_quick_strategy));
	if (!strategy)
		return (NULL);
	strategy->base.execute = v3_quick_sort;
	strategy->base.destroy = v3_quick_strategy_destroy;
	strategy->base.data = NULL;
	return ((t_sort_strategy *)strategy);
}


