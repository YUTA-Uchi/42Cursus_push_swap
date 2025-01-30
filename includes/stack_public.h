/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_public.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:05:43 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/01/29 19:32:33 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_PUBLIC_H
# define STACK_PUBLIC_H

# include <stdlib.h>
# include "libft.h"

typedef int	*t_stack_content;
typedef struct s_stack
{
	t_list			*top;
	int				size;
	char			name;
	void			(*push)(struct s_stack*, t_stack_content);
	t_stack_content	(*pop)(struct s_stack*);
	t_stack_content	(*peek)(struct s_stack*);
	void			(*clear)(struct s_stack*);
	void			(*print)(struct s_stack*);
	void			(*add_size)(int *, int);
	void			(*set_stack_top)(t_list **, t_list *);
}	t_stack;

// constructor
t_stack	*stack_create(char name);
// deconstructor
void	stack_destroy(t_stack *stack);
#endif