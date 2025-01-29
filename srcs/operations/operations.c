/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:04:21 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/01/29 20:02:14 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	swap_a(t_stack *a, int size)
{
	int	tmp;

	if (size < 2)
		return ;
	tmp = a->content;
	a->content = a->next->content;
	a->next->content = tmp;
	// printf("sa\n");
}

void	swap_b(t_stack *b, int size)
{
	int	tmp;

	if (size < 2)
		return ;
	tmp = b->content;
	b->content = b->next->content;
	b->next->content = tmp;
	// printf("sb\n");
}

void	swap_ab(t_stack *a, t_stack *b, int size_a, int size_b)
{
	swap_a(a, size_a);
	swap_b(b, size_b);
	// printf("ss\n");
}

void	push_a(t_stack **a, t_stack **b, int *size_a, int *size_b)
{
	t_stack	*tmp;

	if (*size_b == 0)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	(*size_a)++;
	(*size_b)--;
	// printf("pa\n");
}

void	push_b(t_stack **a, t_stack **b, int *size_a, int *size_b)
{
	t_stack	*tmp;

	if (*size_a == 0)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	(*size_a)--;
	(*size_b)++;
	// printf("pb\n");
}

void	rotate_a(t_stack **a, int size)
{
	t_stack	*tmp;
	t_stack	*last;

	if (size < 2)
		return ;
	tmp = *a;
	*a = (*a)->next;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	// printf("ra\n");
}

void	rotate_b(t_stack **b, int size)
{
	t_stack	*tmp;
	t_stack	*last;

	if (size < 2)
		return ;
	tmp = *b;
	*b = (*b)->next;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	// printf("rb\n");
}

void	rotate_ab(t_stack **a, t_stack **b, int size_a, int size_b)
{
	rotate_a(a, size_a);
	rotate_b(b, size_b);
	// printf("rr\n");
}

void	reverse_rotate_a(t_stack **a, int size)
{
	t_stack	*tmp;
	t_stack	*last;

	if (size < 2)
		return ;
	last = *a;
	while (last->next->next)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = *a;
	*a = tmp;
	// printf("rra\n");
}

void	reverse_rotate_b(t_stack **b, int size)
{
	t_stack	*tmp;
	t_stack	*last;

	if (size < 2)
		return ;
	last = *b;
	while (last->next->next)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = *b;
	*b = tmp;
	// printf("rrb\n");
}

void	reverse_rotate_ab(t_stack **a, t_stack **b, int size_a, int size_b)
{
	reverse_rotate_a(a, size_a);
	reverse_rotate_b(b, size_b);
	// printf("rrr\n");
}

t_push_swap	*push_swap_create(void)
{
	t_push_swap	*new_ps;

	new_ps = malloc(sizeof(t_push_swap));
	if (!new_ps)
		return (NULL);
	new_ps->stack_a = stack_create('a');
	new_ps->stack_b = stack_create('b');
	new_ps->sa = swap_a;
	new_ps->sb = swap_b;
	new_ps->ss = swap_ab;
	new_ps->pa = push_a;
	new_ps->pb = push_b;
	new_ps->ra = rotate_a;
	new_ps->rb = rotate_b;
	new_ps->rr = rotate_ab;
	new_ps->rra = reverse_rotate_a;
	new_ps->rrb = reverse_rotate_b;
	new_ps->rrr = reverse_rotate_ab;
	return (new_ps);
}

void	push_swap_destroy(t_push_swap *ps)
{
	stack_destroy(ps->stack_a);
	stack_destroy(ps->stack_b);
	free(ps);
}
