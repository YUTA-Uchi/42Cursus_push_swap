/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_strategy_public.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:17:10 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/09 15:17:34 by yuuchiya         ###   ########.fr       */
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

typedef struct s_selection_strategy
{
	t_sort_strategy	base;
}	t_selection_strategy;

t_sort_strategy	*selection_sort_strategy_create(void);

typedef struct s_quick_strategy
{
	t_sort_strategy	base;
}	t_quick_strategy;

t_sort_strategy	*quick_sort_strategy_create(void);
#endif