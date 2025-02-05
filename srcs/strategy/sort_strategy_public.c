/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_strategy_public.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:46 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/05 10:57:47 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_public.h"
#include "sort_strategy_private.h"

t_sort_strategy	*selection_sort_strategy_create(void)
{
	t_selection_strategy	*strategy;

	strategy = malloc(sizeof(t_selection_strategy));
	if (!strategy)
		return (NULL);
	strategy->base.execute = selection_sort;
	strategy->base.destroy = selection_strategy_destroy;
	return ((t_sort_strategy *)strategy);
}

t_sort_strategy	*quick_sort_strategy_create(void)
{
	t_quick_strategy	*strategy;

	strategy = malloc(sizeof(t_quick_strategy));
	if (!strategy)
		return (NULL);
	strategy->base.execute = quick_sort;
	strategy->base.destroy = quick_strategy_destroy;
	return ((t_sort_strategy *)strategy);
}

void	quick_strategy_destroy(t_sort_strategy *strategy)
{
	free(strategy);
}
