/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_public.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:36:28 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/01/29 20:11:02 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATOR_PUBLIC_H
# define VALIDATOR_PUBLIC_H

# include "stack_public.h"

typedef enum e_validator_error	t_error_code;
typedef struct s_validator		t_validator;

// error codes
enum e_validator_error
{
	V_SUCCESS = 0,
	V_EMPTY_ARG,
	V_INVALID_NUM,
	V_DUPLICATE,
	V_MALLOC_ERROR,
	V_NO_MORE_OPERATION,
	V_TOO_MANY_ARG
};

// constructor/deconstructor
t_validator		*validator_create(int argc, char **argv);
void			validator_destroy(t_validator *v);
// public methods
int				validate_all(t_validator *v);
int				fill_stack(t_validator *v, t_stack *stack);
t_error_code	get_error_code(t_validator *v);

#endif