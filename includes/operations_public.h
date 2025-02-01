/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_public.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:33:32 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/01 14:52:58 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_PUBLIC_H
# define OPERATIONS_PUBLIC_H

# include "stack_public.h"

typedef struct s_operations
{
	void	(*sa)(t_stack*);
	void	(*sb)(t_stack*);
	void	(*ss)(t_stack*, t_stack*);
	void	(*pa)(t_stack*, t_stack*);
	void	(*pb)(t_stack*, t_stack*);
	void	(*ra)(t_stack*);
	void	(*rb)(t_stack*);
	void	(*rr)(t_stack*, t_stack*);
	void	(*rra)(t_stack*);
	void	(*rrb)(t_stack*);
	void	(*rrr)(t_stack*, t_stack*);
}	t_operations;

t_operations	*operations_create(void);
void			operations_destroy(t_operations *ops);

#endif