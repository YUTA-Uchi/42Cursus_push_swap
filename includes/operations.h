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

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"

typedef struct s_push_swap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	void	(*sa)(struct s_push_swap*);
	void	(*sb)(struct s_push_swap*);
	void	(*ss)(struct s_push_swap*);
	void	(*pa)(struct s_push_swap*);
	void	(*pb)(struct s_push_swap*);
	void	(*ra)(struct s_push_swap*);
	void	(*rb)(struct s_push_swap*);
	void	(*rr)(struct s_push_swap*);
	void	(*rra)(struct s_push_swap*);
	void	(*rrb)(struct s_push_swap*);
	void	(*rrr)(struct s_push_swap*);
}	t_push_swap;

t_push_swap	*push_swap_create(void);
void		push_swap_destroy(t_push_swap *ps);

#endif