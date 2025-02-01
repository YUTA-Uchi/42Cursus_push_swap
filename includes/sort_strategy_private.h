
#ifndef SORT_STRATEGY_PRIVATE_H
# define SORT_STRATEGY_PRIVATE_H

# include "sort_strategy_public.h"

void	selection_sort(t_sort_solver *solver);
void	selection_strategy_destroy(t_sort_strategy *strategy);

void	turkey_sort(t_sort_solver *solver);
void	turkey_strategy_destroy(t_sort_strategy *strategy);

void	quick_sort(t_sort_solver *solver);
void	quick_strategy_destroy(t_sort_strategy *strategy);

#endif