
#include "operations_private.h"

void	push_a(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return ;
	a->push(a, b->pop(b));
	ft_printf(STDOUT_FILENO, "pa\n");
}

void	push_b(t_stack *b, t_stack *a)
{
	if (a->size == 0)
		return ;
	b->push(b, a->pop(a));
	ft_printf(STDOUT_FILENO, "pb\n");
}
