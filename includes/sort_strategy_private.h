/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_strategy_private.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:49:07 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/10 18:59:15 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_STRATEGY_PRIVATE_H
# define SORT_STRATEGY_PRIVATE_H

# include "sort_strategy_public.h"
# include <stdbool.h>

typedef struct s_stack	t_stack;

// void	selection_sort(t_sort_solver *solver);
// void	selection_strategy_destroy(t_sort_strategy *strategy);

// void	quick_sort(t_sort_solver *solver);
// void	quick_strategy_destroy(t_sort_strategy *strategy);

void		v3_quick_sort(t_sort_solver *solver);
void		v3_quick_strategy_destroy(t_sort_strategy *strategy);
//utils
// void	minimal_restore(t_sort_solver *solver, t_stack *stack, int size_remain);
// void	minimal_move(t_sort_solver *solver, 
// 					t_stack *stack, int distance_from_top);
// int		get_pivot(t_stack *stack, int size);
void		get_two_tri_partition_pivots(int *values, \
										t_recursion_data *rec_data);
void		get_pivots(t_stack *stack, t_recursion_data *rec_data);
void		move_to_min(t_sort_solver *solver, \
						t_recursion_data *rec_data);
void		move_to_mid(t_sort_solver *solver, \
						t_recursion_data *rec_data);
void		move_to_max(t_sort_solver *solver, \
						t_recursion_data *rec_data);
// position
t_stack_pos	get_max_pos(t_stack_pos pos);
t_stack_pos	get_mid_pos(t_stack_pos pos);
t_stack_pos	get_min_pos(t_stack_pos pos);
void		move_to_top_a(t_sort_solver *solver, t_stack_pos pos, int size);
t_stack_pos	optimize_position(t_sort_solver *solver, int size, t_stack_pos pos);
//mini sort
bool		is_minimal_sort(t_sort_solver *solver, int size, t_stack_pos pos);
bool		is_minimal_sort_stack_b(t_sort_solver *solver, int size);
void		sort_two(t_sort_solver *solver, t_stack_pos pos);
void		sort_three_minimum(t_sort_solver *solver);
void		sort_three(t_sort_solver *solver, t_stack_pos pos);
void		sort_three_stack_b(t_sort_solver *solver);
void		sort_four(t_sort_solver *solver);
void		sort_four_stack_b(t_sort_solver *solver);
void		sort_five_minimum(t_sort_solver *solver);
void		sort_five(t_sort_solver *solver);
void		sort_five_stack_b(t_sort_solver *solver);

#endif