/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_strategy_public.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:17:10 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/11 13:42:32 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_STRATEGY_PUBLIC_H
# define SORT_STRATEGY_PUBLIC_H

# include <stdlib.h>

typedef struct s_sort_solver	t_sort_solver;
typedef struct s_sort_strategy	t_sort_strategy;

struct s_sort_strategy
{
	void	(*execute)(t_sort_solver*);
	void	(*destroy)(t_sort_strategy*);
	void	*data;
};

typedef struct s_manual_sort_strategy
{
	t_sort_strategy	base;
}	t_manual_sort_strategy;

t_sort_strategy		*manual_sort_strategy_create(void);

typedef struct s_v3_quick_strategy
{
	t_sort_strategy	base;
}	t_v3_quick_strategy;

t_sort_strategy		*v3_quick_sort_strategy_create(void);

typedef enum e_partition
{
	PART_MAX,
	PART_MID,
	PART_MIN
}	t_partition;

typedef enum e_pivot
{
	SPLIT_MIN,
	SPLIT_MID
}	t_pivot;

typedef enum e_stack_position
{
	TOP_A,
	TOP_B,
	BOTTOM_A,
	BOTTOM_B
}	t_stack_pos;

typedef struct s_recursion_data
{
	int			size;
	t_stack_pos	pos;
	int			pivot[2];
	int			next_size[3];
}	t_recursion_data;

t_recursion_data	*recursion_data_create(int size, t_stack_pos pos);
void				recursion_data_destroy(t_recursion_data *data);

#endif