
#include "stack_private.h"

void	add_size(int *size, int add_num)
{
	*size += add_num;
}

void	set_stack_top(t_list **self_top, t_list *top)
{
	*self_top = top;
}