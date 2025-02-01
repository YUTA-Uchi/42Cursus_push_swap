
#include "operations_private.h"

void	swap_a(t_stack *a)
{
	t_stack_content	first;
	t_stack_content	second;

	if (a->size < 2)
		return ;
	first = a->pop(a);
	second = a->pop(a);
	a->push(a, first);
	a->push(a, second);
	ft_printf(STDOUT_FILENO, "sa\n");
}

void	swap_b(t_stack *b)
{
	t_stack_content	first;
	t_stack_content	second;

	if (b->size < 2)
		return ;
	first = b->pop(b);
	second = b->pop(b);
	b->push(b, first);
	b->push(b, second);
	ft_printf(STDOUT_FILENO, "sb\n");
}

void	swap_ab(t_stack *a, t_stack *b)
{
	t_stack_content	first;
	t_stack_content	second;

	if (a->size < 2 || b->size < 2)
		return ;
	first = a->pop(a);
	second = a->pop(a);
	a->push(a, first);
	a->push(a, second);
	first = b->pop(b);
	second = b->pop(b);
	b->push(b, first);
	b->push(b, second);
	ft_printf(STDOUT_FILENO, "ss\n");
}
