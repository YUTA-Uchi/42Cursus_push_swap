
#include "operations_private.h"

void	push_a(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return ;
	a->push(a, b->pop(b));
	// printf("pa\n");
}

void	push_b(t_stack *a, t_stack *b)
{
	if (a->size == 0)
		return ;
	b->push(b, a->pop(a));
	// printf("pb\n");
}
