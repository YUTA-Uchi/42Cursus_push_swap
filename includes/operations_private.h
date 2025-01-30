
#ifndef OPERATIONS_PRIVATE_H
# define OPERATIONS_PRIVATE_H

# include "operations_public.h"

void	swap(t_stack *stack);
// void	swap_b(t_stack *b);
void	swap_ab(t_stack *a, t_stack *b);
void	push(t_stack *to, t_stack *from);
// void	push_b(t_stack *a, t_stack *b);
void	rotate(t_stack *stack);
// void	rotate_b(t_stack *b);
void	rotate_ab(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *stack);
// void	reverse_rotate_b(t_stack *b);
void	reverse_rotate_ab(t_stack *a, t_stack *b);


#endif