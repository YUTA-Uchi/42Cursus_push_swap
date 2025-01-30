
#include "operations_private.h"

void	push(t_stack *to, t_stack *from)
{
	if (from->size == 0)
		return ;
	to->push(to, from->pop(from));
	// printf("pa\n");
}

// void	push_b(t_stack *a, t_stack *b)
// {
// 	if (a->size == 0)
// 		return ;
// 	b->push(b, a->pop(a));
// 	// printf("pb\n");
// }
