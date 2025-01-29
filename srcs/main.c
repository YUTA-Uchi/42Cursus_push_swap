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
	t_validator	*validator;
	t_push_swap			*ps;

	if (argc < 2)
		return (1);
	validator = validator_create(argc - 1, argv + 1);
	if (!validator)
		return (1);
	ft_printf(1, "validator created\n");
	ps = push_swap_create();
	if (!validate_all(validator))
	{
		//print_error_code(get_error_code(validator));
		ft_printf(1, "error:%d\n", get_error_code(validator));
		validator_destroy(validator);
		return (1);
	}
	fill_stack(validator, ps->stack_a);
	ft_printf(1, "stack filled\n");
	validator_destroy(validator);
	ft_printf(1, "validator destroyed\n");
	// sort
	ps->stack_a->print(ps->stack_a);
	ps->sa(ps->stack_a);
	ps->pa(ps->stack_a, ps->stack_b);
	ps->ra(ps->stack_a);
	ps->rra(ps->stack_a);
	ps->stack_a->print(ps->stack_a);
	ps->stack_b->print(ps->stack_b);
	push_swap_destroy(ps);

	return (0);
}
