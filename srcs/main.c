/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:04:12 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/01/29 20:05:16 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	const t_validator	*validator = validator_create(argc - 1, argv + 1);
	t_push_swap			*ps;

	if (argc < 2)
		return (print_error(), 0);
	if (!validator)
		return (print_error(), 0);
	ps = push_swap_create();
	if (!validate_all(validator))
	{
		print_error_code(get_error_code(validator));
		validator_destroy(validator);
		return (0);
	}
	fill_stack(ps->stack_a, validator);
	validator_destroy(validator);
	// sort
	return (0);
}
