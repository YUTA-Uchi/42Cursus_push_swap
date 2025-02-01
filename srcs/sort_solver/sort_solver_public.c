
#include "sort_solver_public.h"

static void	set_strategy(t_sort_solver *solver, t_sort_strategy *strategy)
{
	if (solver->strategy)
		solver->strategy->destroy(solver->strategy);
	solver->strategy = strategy;
}

static void	solve(t_sort_solver *solver)
{
	if (solver->strategy)
		solver->strategy->execute(solver);
}

t_sort_solver	*sort_solver_create(t_stack *stack_a, t_stack *stack_b)
{
	t_sort_solver	*solver;

	solver = malloc(sizeof(t_sort_solver));
	if (!solver)
		return (NULL);
	solver->ops = operations_create();
	if (!solver->ops)
	{
		free(solver);
		return (NULL);
	}
	solver->stack_a = stack_a;
	solver->stack_b = stack_b;
	solver->strategy = NULL;
	solver->set_strategy = set_strategy;
	solver->solve = solve;
	return (solver);
}

void	sort_solver_destroy(t_sort_solver *solver)
{
	operations_destroy(solver->ops);
	stack_destroy(solver->stack_a);
	stack_destroy(solver->stack_b);
	if (solver->strategy)
		solver->strategy->destroy(solver->strategy);
	free(solver);
}
