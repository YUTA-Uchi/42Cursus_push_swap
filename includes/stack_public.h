/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_public.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:05:43 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/11 11:39:26 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_PUBLIC_H
# define STACK_PUBLIC_H

# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"
# include "doubly_linked_list_public.h"

typedef struct s_stack		t_stack;

typedef enum e_stack_search_from
{
	TOP,
	BOTTOM
}	t_stack_search_from;

struct s_stack
{
	t_stack_node	*top;
	t_stack_node	*bottom;
	int				size;
	char			name;
	void			(*push)(t_stack *, t_stack_value);
	t_stack_value	(*pop)(t_stack *);
	void			(*swap)(t_stack *);
	int				(*value)(t_stack *, int, t_stack_search_from);
	void			(*rotate)(t_stack *);
	void			(*reverse_rotate)(t_stack *);
	void			(*clear)(t_stack *);
	void			(*add_size)(int *, int);
};

// constructor
t_stack	*stack_create(char name);
// deconstructor
void	stack_destroy(t_stack *stack);
// util
bool	is_sorted(t_stack *stack);
int		get_distance_to_max_from_top(t_stack *stack, int size);
int		get_distance_to_max_from_bottom(t_stack *stack, int size);
#endif