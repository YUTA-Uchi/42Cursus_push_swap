/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:37:43 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/08 11:32:04 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATOR_PRIVATE_H
# define VALIDATOR_PRIVATE_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft.h"
# include "validator_public.h"

struct s_validator
{
	char			**args;
	int				arg_count;
	int				*parsed_nums;
	int				num_count;
	t_error_code	error_code;
};

typedef struct s_validator	t_validator;

bool	validate_number(char *str, long *result);
int		check_duplicates(int *nums, int count);
// utils
void	set_parsed_nums(t_validator *self, int num);
void	set_error(t_validator *self, int error_code);
int		init_parsed_nums(int **parsednums, int count);
int		count_args(char **args);

#endif