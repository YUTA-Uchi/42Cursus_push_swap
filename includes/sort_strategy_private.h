
#ifndef SORT_STRATEGY_PRIVATE_H
# define SORT_STRATEGY_PRIVATE_H

# include "sort_strategy_public.h"

typedef struct s_stack	t_stack;

void	selection_sort(t_sort_solver *solver);
void	selection_strategy_destroy(t_sort_strategy *strategy);

void	turkey_sort(t_sort_solver *solver);
void	turkey_strategy_destroy(t_sort_strategy *strategy);

void	quick_sort(t_sort_solver *solver);
void	quick_strategy_destroy(t_sort_strategy *strategy);
//utils
int		get_median(int *values, int size);
void	minimal_restore(t_sort_solver *solver, t_stack *stack, int size_remain);
int		get_pivot(t_stack *stack, int size);
int		get_distance_to_min(t_stack *stack, int size);
int		get_distance_to_max(t_stack *stack, int size);
//mini sort
void	sort_two(t_sort_solver *solver, t_stack *stack);
void	sort_three(t_sort_solver *solver);
void	sort_three_stack_b(t_sort_solver *solver);

#endif