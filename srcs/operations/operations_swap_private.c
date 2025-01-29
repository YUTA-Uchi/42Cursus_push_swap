
#include "operations_private.h"

void	swap_a(t_stack *a)
{
	int	tmp;

	if (a->size < 2)
		return ;
	tmp = a->pop(a);
	a->push(a, a->pop(a));
	a->push(a, tmp);
	// printf("sa\n");
}

void	swap_b(t_stack *b)
{
	int	tmp;

	if (b->size < 2)
		return ;
	tmp = b->pop(b);
	b->push(b, b->pop(b));
	b->push(b, tmp);
	// printf("sb\n");
}

void	swap_ab(t_stack *a, t_stack *b)
{
	swap_a(a);
	swap_b(b);
	// printf("ss\n");
}