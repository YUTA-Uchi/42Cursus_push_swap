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

typedef struct s_push_swap
{
	t_stack		*stack_a;
	t_stack		*stack_b;
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
}	t_push_swap;

t_push_swap	*push_swap_create(void);
void		push_swap_destroy(t_push_swap *ps);

#endif