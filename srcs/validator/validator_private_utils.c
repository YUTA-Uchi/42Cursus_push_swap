/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_private_util.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:43:02 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/01/29 18:30:01 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator_private.h"

static void	add_num_count(t_validator *self, int count)
{
	self->num_count += count;
}

int	init_parsed_nums(int **parsed_nums, int count)
{
	*parsed_nums = malloc(sizeof(int) * count);
	if (!*parsed_nums)
		return (0);
	return (1);
}

void	set_error(t_validator *self, int error_code)
{
	self->error_code = error_code;
}

void	set_parsed_nums(t_validator *self, int num)
{
	self->parsed_nums[self->num_count] = num;
	add_num_count(self, 1);
}
