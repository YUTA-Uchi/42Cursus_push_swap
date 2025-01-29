
#include "operations_private.h"

void	reverse_rotate_a(t_stack *a)
{
	t_list	*tmp;
	t_list	*last;
	int		last_content;

	if (a->size < 2)
		return ;
	last = a->top;
	while (last->next->next)
		last = last->next;
	tmp = last->next;
	last_content = *(int *)(tmp->content);
	last->next = NULL;
	ft_lstdelone(tmp, free);
	a->add_size(&(a->size), -1);
	a->push(a, last_content);
	// printf("rra\n");
}

void	reverse_rotate_b(t_stack *b)
{
	t_list	*tmp;
	t_list	*last;
	int		last_content;

	if (b->size < 2)
		return ;
	last = b->top;
	while (last->next->next)
		last = last->next;
	tmp = last->next;
	last_content = *(int *)(tmp->content);
	last->next = NULL;
	ft_lstdelone(tmp, free);
	b->add_size(&(b->size), -1);
	b->push(b, last_content);
	// printf("rrb\n");
}

void	reverse_rotate_ab(t_stack *a, t_stack *b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
	// printf("rrr\n");
}
