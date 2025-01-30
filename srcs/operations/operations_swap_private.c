
#include "operations_private.h"

void	swap(t_stack *stack)
{
	t_stack_content	first;
	t_stack_content	second;

	if (stack->size < 2)
		return ;
	first = stack->pop(stack);
	second = stack->pop(stack);
	stack->push(stack, first);
	stack->push(stack, second);
	// printf("sa\n");
}

// void	swap_b(t_stack *b)
// {
// 	int	tmp;

// 	if (b->size < 2)
// 		return ;
// 	tmp = b->pop(b);
// 	b->push(b, b->pop(b));
// 	b->push(b, tmp);
// 	// printf("sb\n");
// }

void	swap_ab(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	// printf("ss\n");
}