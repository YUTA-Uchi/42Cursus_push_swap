
#include "sort_strategy_public.h"
#include "sort_strategy_private.h"

t_sort_strategy	*selection_sort_strategy_create(void)
{
	t_selection_strategy	*strategy;

	strategy = malloc(sizeof(t_selection_strategy));
	if (!strategy)
		return (NULL);
	strategy->base.execute = selection_sort;
	strategy->base.destroy = selection_strategy_destroy;
	return ((t_sort_strategy *)strategy);
}

// t_sort_strategy	*turkey_sort_strategy_create(int chunk_size)
// {
// 	t_turkey_strategy	*strategy;

// 	strategy = malloc(sizeof(t_turkey_strategy));
// 	if (!strategy)
// 		return (NULL);
// 	strategy->base.execute = turkey_sort;
// 	strategy->base.destroy = turkey_strategy_destroy;
// 	strategy->chunk_size = chunk_size;
// 	return ((t_sort_strategy *)strategy);
// }
