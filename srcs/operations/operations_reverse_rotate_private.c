
#include "operations_private.h"

void	reverse_rotate_a(t_stack *a)
{
	a->reverse_rotate(a);
	ft_printf(STDOUT_FILENO, "rra\n");
}

void	reverse_rotate_b(t_stack *b)
{
	b->reverse_rotate(b);
	ft_printf(STDOUT_FILENO, "rrb\n");
}

void	reverse_rotate_ab(t_stack *a, t_stack *b)
{
	a->reverse_rotate(a);
	b->reverse_rotate(b);
	ft_printf(STDOUT_FILENO, "rrr\n");
}
