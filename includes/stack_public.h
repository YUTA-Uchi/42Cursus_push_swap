/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_public.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:05:43 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/09 15:34:42 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_PUBLIC_H
# define STACK_PUBLIC_H

# include <stdlib.h>
# include "libft.h"

typedef int*			t_stack_node;
typedef struct s_stack	t_stack;

struct s_stack
{
	t_list			*top;
	int				size;
	char			name;
	void			(*push)(t_stack *, t_stack_node);
	t_stack_node	(*pop)(t_stack *);
	int				(*value)(t_stack *, int);
	void			(*rotate)(t_stack *);
	void			(*reverse_rotate)(t_stack *);
	void			(*clear)(t_stack *);
	void			(*print)(t_stack *);
	void			(*add_size)(int *, int);
	void			(*set_stack_top)(t_list **, t_list *);
};

// constructor
t_stack	*stack_create(char name);
// deconstructor
void	stack_destroy(t_stack *stack);
// util
int		get_smallest_value(t_stack *stack, int size);
int		get_second_smallest_value(t_stack *stack, int size);
int		get_insert_position(t_stack *stack, int value, int size);
int		get_distance_to_min(t_stack *stack, int size);
int		get_distance_to_max(t_stack *stack, int size);
#endif