
#ifndef SORT_STRATEGY_PUBLIC_H
# define SORT_STRATEGY_PUBLIC_H

# include <stdlib.h>

typedef struct s_sort_solver t_sort_solver;
typedef struct s_sort_strategy t_sort_strategy;

struct s_sort_strategy
{
	void	(*execute)(t_sort_solver*);
	void	(*destroy)(t_sort_strategy*);
	// 戦略固有のデータ
	void	*data;
};

typedef struct s_selection_strategy
{
	t_sort_strategy	base;
} t_selection_strategy;

t_sort_strategy	*selection_strategy_create(void);

typedef struct s_turkey_strategy
{
	t_sort_strategy	base;
	int				chunk_size;
} t_turkey_strategy;

t_sort_strategy	*turkey_strategy_create(int chunk_size);
// void			turkey_strategy_destroy(t_sort_strategy *strategy);
#endif