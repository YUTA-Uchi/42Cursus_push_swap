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
		return (set_error(v, V_MALLOC_ERROR), 0);
	i = 0;
	while (i < v->arg_count)
	{
		if (!v->args[i][0])
			return (set_error(v, V_EMPTY_ARG), 0);
		if (!validate_number(v->args[i], &temp_num))
			return (set_error(v, V_INVALID_CHAR), 0);
		set_parsed_nums(v, (int)temp_num);
		i++;
	}
	if (!check_duplicates(v->parsed_nums, v->num_count))
		return (set_error(v, V_DUPLICATE), 0);
	return (1);
}

int	fill_stack(t_validator *v, t_stack *stack)
{
	int	i;

	i = v->num_count - 1;
	while (i >= 0)
	{
		ft_printf(STDOUT_FILENO, "push %p\n", stack->top);
		stack->push(stack, v->parsed_nums[i]);
		ft_printf(STDOUT_FILENO, "pushed %d\n", *(int*)stack->top->content);
		i--;
	}
	return (1);
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
	new_validator->args = argv;
	new_validator->arg_count = argc;
	new_validator->parsed_nums = NULL;
	new_validator->num_count = 0;
	new_validator->error_code = V_SUCCESS;
	return (new_validator);
}

void	validator_destroy(t_validator *v)
{
	if (!v)
		return ;
	free(v->parsed_nums);
	free(v);
}
