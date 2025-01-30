
#include "sort_solver_public.h"

void	selection_sort(t_sorter *sorter)
{
	t_push_swap	*ps;
	int			min;

	ps = sorter->ps;
	while (ps->stack_a->size > 0)  // n回ループ
	{
		// find_minの中で全探索
		min = sorter->find_min(ps->stack_a);  // O(n)
		
		// 最小値を見つけるまでrotate
		while (*(int *)(ps->stack_a->top->content) != min) // 最悪O(n)
			ps->rotate(ps->stack_a);
			
		ps->push(ps->stack_b, ps->stack_a);
	}
	
	// 最後にn回のpa
	while (ps->stack_b->size > 0)  // O(n)
		ps->push(ps->stack_a, ps->stack_b);
}

static int	find_min(t_stack *stack)
{
	t_list	*node;
	int		min;

	node = stack->top;
	min = *(t_stack_content)node->content;
	while (node)
	{
		if (*(t_stack_content)node->content < min)
			min = *(t_stack_content)node->content;
		node = node->next;
	}
	return (min);
}

t_sorter	*sorter_create(t_push_swap *ps)
{
	t_sorter	*sorter;

	sorter = malloc(sizeof(t_sorter));
	if (!sorter)
		return (NULL);
	sorter->ps = ps;
	sorter->min = 0;
	sorter->max = 0;
	sorter->median = 0;
	sorter->sort = selection_sort;
	sorter->find_min = find_min;
	sorter->find_max = NULL;
	sorter->find_median = NULL;
	sorter->is_sorted = NULL;
	sorter->get_position = NULL;
	sorter->calculate_stats = NULL;
	return (sorter);
}

void	sorter_destroy(t_sorter *sorter)
{
	push_swap_destroy(sorter->ps);
	free(sorter);
}