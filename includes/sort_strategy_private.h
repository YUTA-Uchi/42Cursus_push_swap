/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_strategy_private.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:49:07 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/11 14:37:48 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_STRATEGY_PRIVATE_H
# define SORT_STRATEGY_PRIVATE_H

# include <stdbool.h>
# include "sort_strategy_public.h"

typedef struct s_stack	t_stack;

bool		v3_quick_sort(t_sort_solver *solver);
void		v3_quick_strategy_destroy(t_sort_strategy *strategy);
//utils
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
void		sort_two(t_sort_solver *solver, t_stack_pos pos);
void		sort_three_minimum(t_sort_solver *solver);
void		sort_three(t_sort_solver *solver, t_stack_pos pos);

#endif