
#include "operations_private.h"

void	rotate(t_stack *stack)
{
	t_stack_content	top_content;

	if (stack->size < 2)
		return ;
	top_content = stack->pop(stack);
	ft_lstadd_back(&(stack->top), ft_lstnew(top_content));
	stack->add_size(&(stack->size), 1);
	if (stack->name == 'a')
		ft_printf(STDOUT_FILENO, "ra\n");
	else
		ft_printf(STDOUT_FILENO, "rb\n");
}

// void	rotate_b(t_stack *b)
// {
// 	int				tmp;
// 	t_stack_content	tmp_content;

// 	if (b->size < 2)
// 		return ;
// 	tmp = b->pop(b);
// 	tmp_content = malloc(sizeof(int));
// 	if (!tmp_content)
// 		return ;
// 	*tmp_content = tmp;
// 	ft_lstadd_back(&(b->top), ft_lstnew(tmp_content));
// 	b->add_size(&(b->size), 1);
// 	// printf("rb\n");
// }

void	rotate_ab(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	// printf("rr\n");
}
