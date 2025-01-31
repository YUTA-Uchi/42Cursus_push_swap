/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_public.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:52:22 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/01/29 19:10:27 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator_private.h"
#include "validator_public.h"

int	validate_all(t_validator *v)
{
	long	temp_num;
	int		i;

	if (!init_parsed_nums(&(v->parsed_nums), v->arg_count))
		return (set_error(v, V_MALLOC_ERROR), 1);
	// if (v->arg_count == 1)
	// 	return (set_error(v, V_NO_MORE_OPERATION), 1);
	if (v->arg_count == INT_MAX)
		return (set_error(v, V_TOO_MANY_ARG), 1);
	i = 0;
	while (i < v->arg_count)
	{
		if (!v->args[i][0])
			return (set_error(v, V_EMPTY_ARG), 1);
		if (!validate_number(v->args[i], &temp_num))
			return (set_error(v, V_INVALID_NUM), 1);
		set_parsed_nums(v, (int)temp_num);
		i++;
	}
	if (!check_duplicates(v->parsed_nums, v->num_count))
		return (set_error(v, V_DUPLICATE), 1);
	return (V_SUCCESS);
}

int	fill_stack(t_validator *v, t_stack *stack)
{
	int	i;
	t_stack_content	content;

	i = v->num_count - 1;
	while (i >= 0)
	{
		content = malloc(sizeof(int));
		if (!content)
			return (set_error(v, V_MALLOC_ERROR), 1);
		*content = v->parsed_nums[i];
		stack->push(stack, content);
		i--;
	}
	return (V_SUCCESS);
}

t_error_code	get_error_code(t_validator *v)
{
	return (v->error_code);
}

t_validator	*validator_create(int argc, char **argv)
{
	t_validator	*new_validator;

	new_validator = malloc(sizeof(t_validator));
	if (!new_validator)
		return (NULL);
	if (argc == 1)
	{
		new_validator->args = ft_split(argv[0], ' ');
		if (!new_validator->args)
			return (validator_destroy(new_validator), NULL);
		new_validator->arg_count = count_args(new_validator->args);
	}
	else
	{
		new_validator->args = argv;
		new_validator->arg_count = argc;
	}
	new_validator->parsed_nums = NULL;
	new_validator->num_count = 0;
	new_validator->error_code = V_SUCCESS;
	return (new_validator);
}

void	validator_destroy(t_validator *v)
{
	if (!v)
		return ;
	if (v->parsed_nums)
		free(v->parsed_nums);
	free(v);
}
