
#include "sort_strategy_private.h"
#include "sort_solver_public.h"

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

void	selection_sort(t_sort_solver *solver)
{
	int	min;

	if (solver->stack_a->size <= 1)
		return ;
	while (solver->stack_a->size > 0)
	{
		min = find_min(solver->stack_a);
		while (*(int *)(solver->stack_a->top->content) != min)
			solver->ops->ra(solver->stack_a);
		solver->ops->pb(solver->stack_b, solver->stack_a);
	}
	while (solver->stack_b->size > 0)
		solver->ops->pa(solver->stack_a, solver->stack_b);
}

void	selection_strategy_destroy(t_sort_strategy *strategy)
{
	free(strategy);
}
