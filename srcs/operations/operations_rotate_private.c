
#include "operations_private.h"

void	rotate_a(t_stack *a)
{
	a->rotate(a);
	ft_printf(STDOUT_FILENO, "ra\n");
}

void	rotate_b(t_stack *b)
{
	b->rotate(b);
	ft_printf(STDOUT_FILENO, "rb\n");
}

void	rotate_ab(t_stack *a, t_stack *b)
{
	a->rotate(a);
	b->rotate(b);
	ft_printf(STDOUT_FILENO, "rr\n");
}
