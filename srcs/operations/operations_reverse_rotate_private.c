
#include "operations_private.h"

void	reverse_rotate(t_stack *stack)
{
	t_list			*tail;
	t_list			*pretail;
	t_stack_content	tail_content;

	if (stack->size < 2)
		return ;
	pretail = stack->top;
	while (pretail->next->next)
		pretail = pretail->next;
	tail = pretail->next;
	tail_content = (t_stack_content)(tail->content);
	pretail->next = NULL;
	free(tail);
	stack->add_size(&(stack->size), -1);
	stack->push(stack, tail_content);
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
