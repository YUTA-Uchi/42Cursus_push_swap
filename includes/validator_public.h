/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_public.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:36:28 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/01/29 19:10:48 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATOR_PUBLIC_H
# define VALIDATOR_PUBLIC_H

typedef enum e_validator_error	t_error_code;
typedef struct s_validator		t_validator;

// error codes
enum e_validator_error
{
	V_SUCCESS = 0,
	V_EMPTY_ARG,
	V_INVALID_CHAR,
	V_INVALID_SIGN,
	V_OUT_OF_RANGE,
	V_DUPLICATE,
	V_MALLOC_ERROR
};

// constructor/deconstructor
t_validator		*validator_create(int argc, char **argv);
void			validator_destroy(t_validator *validator);
// public methods
int				validate_all(const t_validator *v);
int				fill_stack(const t_validator *v, const t_stack *stack);
t_error_code	get_error_code(const t_validator *v);

#endif