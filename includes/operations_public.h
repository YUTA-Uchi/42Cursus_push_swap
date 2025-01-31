/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:33:32 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/01/29 13:34:59 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_PUBLIC_H
# define OPERATIONS_PUBLIC_H

# include "stack_public.h"

typedef struct s_operations
{
	void	(*swap)(t_stack*);
	// void	(*sb)(t_stack*);
	void	(*ss)(t_stack*, t_stack*);
	void	(*push)(t_stack*, t_stack*);
	// void	(*pb)(t_stack*, t_stack*);
	void	(*rotate)(t_stack*);
	// void	(*rb)(t_stack*);
	void	(*rr)(t_stack*, t_stack*);
	void	(*reverse_rotate)(t_stack*);
	// void	(*rrb)(t_stack*);
	void	(*rrr)(t_stack*, t_stack*);
}	t_operations;

t_operations	*operations_create(void);
void		operations_destroy(t_operations *ops);

#endif