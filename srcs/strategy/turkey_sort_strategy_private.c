
#include "sort_strategy_private.h"
#include "sort_solver_public.h"

static int is_in_range(int num, int min, int max)
{
	return (num >= min && num <= max);
}

static int has_numbers_in_range(t_sort_solver *solver, int min, int max)
{
	int	i;

	i = 0;
	while (i < solver->stack_a->size)
	{
		if (is_in_range(*(t_stack_content)solver->stack_a->top->content, min, max))
			return (1);
		solver->ops->rotate(solver->stack_a);
		i++;
	}
	return (0);
}

static int find_max_position(t_sort_solver *solver)
{
	int	max_val;
	int	max_pos;
	int	i;
	int	size;
	
	i = 0;
	size = solver->stack_b->size;
	max_val = *(t_stack_content)solver->stack_b->top->content;
	max_pos = 0;
	while (i < size)
	{
		if (*(t_stack_content)solver->stack_b->top->content > max_val)
		{
			max_val = *(t_stack_content)solver->stack_b->top->content;
			max_pos = i;
		}
		solver->ops->rotate(solver->stack_b);
		i++;
	}
	// 元の位置に戻す
	i = size - max_pos;
	while (i < size)
	{
		solver->ops->rotate(solver->stack_b);
		i++;
	}
	return (max_pos);
}

static void process_chunk(t_sort_solver *solver, int min, int max)
{
	int rotations;
	int size;

	rotations = 0;
	size = solver->stack_a->size;
	while (has_numbers_in_range(solver, min, max))
	{
		if (is_in_range(*(t_stack_content)solver->stack_a->top->content, min, max))
		{
			solver->ops->push(solver->stack_b, solver->stack_a);
			rotations = 0;  // 回転カウントをリセット
		}
		else
		{
			solver->ops->rotate(solver->stack_a);
			rotations++;
			// 一周したら、このチャンクの数値は全て移動済み
			if (rotations >= size)
				break;
		}
	}
}

static void process_back_to_a(t_sort_solver *solver)
{
	int max_pos;
	int size;

	while (solver->stack_b->size > 0)
	{
		max_pos = find_max_position(solver);
		size = solver->stack_b->size;
		
		// 最適な回転方向を選択
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				solver->ops->rotate(solver->stack_b);
		}
		else
		{
			while (max_pos++ < size)
				solver->ops->reverse_rotate(solver->stack_b);
		}
		solver->ops->push(solver->stack_a, solver->stack_b);
	}
}

void turkey_sort(t_sort_solver *solver)
{
	t_turkey_strategy	*ts;

	ts = (t_turkey_strategy *)solver->strategy;
	ts->chunk_count = (solver->stack_a->size + ts->chunk_size - 1) / ts->chunk_size;
	ts->chunk = 0;

	while (ts->chunk < ts->chunk_count)
	{
		ts->min = ts->chunk * ts->chunk_size;
		ts->max = (ts->chunk + 1) * ts->chunk_size - 1;
		if (ts->max >= solver->stack_a->size)
			ts->max = solver->stack_a->size - 1;
		process_chunk(solver, ts->min, ts->max);
		ts->chunk++;
	}
	process_back_to_a(solver);
}

void turkey_strategy_destroy(t_sort_strategy *strategy)
{
	free(strategy);
}
