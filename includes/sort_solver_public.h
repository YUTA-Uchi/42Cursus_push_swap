
#ifndef SORT_SOLVER_PUBLIC_H
# define SORT_SOLVER_PUBLIC_H

# include <stdbool.h>
# include "operations_public.h"

typedef struct s_sorter {
	t_push_swap 	*ps;
	int				min;
	int				max;
	int				median;
	void			(*sort)(struct s_sorter *self);
	// ヘルパー関数群
	int				(*find_min)(t_stack *stack);
	int				(*find_max)(t_stack *stack);
	int				(*find_median)(t_stack *stack);
	bool			(*is_sorted)(t_stack *stack);
	int				(*get_position)(t_stack *stack, int value);
	void			(*calculate_stats)(struct s_sorter *self);
} t_sorter;

t_sorter	*sorter_create(t_push_swap *ps);
void		sorter_destroy(t_sorter *sorter);

#endif