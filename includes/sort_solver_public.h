/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_solver_public.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:15:36 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/11 17:17:25 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_SOLVER_PUBLIC_H
# define SORT_SOLVER_PUBLIC_H

# include <stdbool.h>
# include "operations_public.h"
# include "sort_strategy_public.h"

typedef struct s_sort_solver	t_sort_solver;

struct s_sort_solver {
	t_operations	*ops;
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_sort_strategy	*strategy;
	void			(*set_strategy)(t_sort_solver *, t_sort_strategy *);
	bool			(*solve)(t_sort_solver *);
};

t_sort_solver	*sort_solver_create(t_stack *stack_a, t_stack *stack_b);
void			sort_solver_destroy(t_sort_solver *solver);

#endif