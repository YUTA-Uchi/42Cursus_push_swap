
#include "operations_private.h"

void	reverse_rotate(t_stack *stack)
{
	t_list	*tmp;
	t_list	*last;
	int		last_content;

	if (stack->size < 2)
		return ;
	last = stack->top;
	while (last->next->next)
		last = last->next;
	tmp = last->next;
	last_content = *(t_stack_content)(tmp->content);
	last->next = NULL;
	ft_lstdelone(tmp, free);
	stack->add_size(&(stack->size), -1);
	stack->push(stack, last_content);
	// printf("rra\n");
}

// void	reverse_rotate_b(t_stack *b)
// {
// 	t_list	*tmp;
// 	t_list	*last;
// 	int		last_content;

// 	if (b->size < 2)
// 		return ;
// 	last = b->top;
// 	while (last->next->next)
// 		last = last->next;
// 	tmp = last->next;
// 	last_content = *(t_stack_content)(tmp->content);
// 	last->next = NULL;
// 	ft_lstdelone(tmp, free);
// 	b->add_size(&(b->size), -1);
// 	b->push(b, last_content);
// 	// printf("rrb\n");
// }

void	reverse_rotate_ab(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	// printf("rrr\n");
}
