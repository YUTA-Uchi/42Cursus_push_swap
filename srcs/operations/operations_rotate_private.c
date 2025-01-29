
#include "operations_private.h"

void	rotate_a(t_stack *a)
{
	int	tmp;

	if (a->size < 2)
		return ;
	tmp = a->pop(a);
	ft_lstadd_back(&(a->top), ft_lstnew(&tmp));
	a->add_size(&(a->size), 1);
	// printf("ra\n");
}

void	rotate_b(t_stack *b)
{
	int	tmp;

	if (b->size < 2)
		return ;
	tmp = b->pop(b);
	ft_lstadd_back(&(b->top), ft_lstnew(&tmp));
	b->add_size(&(b->size), 1);
	// printf("rb\n");
}

void	rotate_ab(t_stack *a, t_stack *b)
{
	rotate_a(a);
	rotate_b(b);
	// printf("rr\n");
}
