/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:04:26 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/11 17:15:39 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include "validator_public.h"
# include "stack_public.h"
# include "sort_solver_public.h"
# include "libft.h"

typedef struct s_push_swap
{
	t_sort_solver	*solver;
	t_validator		*validator;
}	t_push_swap;

t_push_swap	*push_swap_create(int argc, char **argv);
void		push_swap_destroy(t_push_swap *ps, int argc);
bool		push_swap_execute(t_push_swap *ps);

#endif
