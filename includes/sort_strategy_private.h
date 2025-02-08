/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_strategy_private.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:49:07 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/08 15:29:27 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_STRATEGY_PRIVATE_H
# define SORT_STRATEGY_PRIVATE_H

# include "sort_strategy_public.h"
# include <stdbool.h>

typedef struct s_stack	t_stack;

void	selection_sort(t_sort_solver *solver);
void	selection_strategy_destroy(t_sort_strategy *strategy);

void	quick_sort(t_sort_solver *solver);
void	quick_strategy_destroy(t_sort_strategy *strategy);
//utils
int		get_median(int *values, int size);
void	minimal_restore(t_sort_solver *solver, t_stack *stack, int size_remain);
void	minimal_move(t_sort_solver *solver, \
					t_stack *stack, int distance_from_top);
int		get_insert_position(t_stack *stack, int value, int size);
int		get_pivot(t_stack *stack, int size);
int		get_distance_to_min(t_stack *stack, int size);
int		get_distance_to_max(t_stack *stack, int size);
//mini sort
bool	is_minimal_sort(t_sort_solver *solver, int size);
bool	is_minimal_sort_stack_b(t_sort_solver *solver, int size);
void	sort_two(t_sort_solver *solver, t_stack *stack);
void	sort_three(t_sort_solver *solver);
void	sort_three_stack_b(t_sort_solver *solver);
void	sort_four(t_sort_solver *solver);
void	sort_four_stack_b(t_sort_solver *solver);
void	sort_five(t_sort_solver *solver);
void	sort_five_stack_b(t_sort_solver *solver);

#endif