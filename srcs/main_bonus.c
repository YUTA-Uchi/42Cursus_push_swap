/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:45:10 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/11 16:45:26 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	*push_swap_create(int argc, char **argv)
{
	t_push_swap	*ps;

	ps = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!ps)
		return (NULL);
	ps->solver = NULL;
	ps->validator = validator_create(argc, argv);
	if (!ps->validator)
		return (push_swap_destroy(ps, argc), NULL);
	if (validate_all(ps->validator) != V_SUCCESS)
	{
		return (push_swap_destroy(ps, argc), NULL);
	}
	ps->solver = sort_solver_create(stack_create('a'), stack_create('b'));
	if (!ps->solver)
		return (push_swap_destroy(ps, argc), NULL);
	if (fill_stack(ps->validator, ps->solver->stack_a) != V_SUCCESS)
		return (push_swap_destroy(ps, argc), NULL);
	return (ps);
}

bool	push_swap_execute(t_push_swap *ps)
{
	t_sort_strategy	*strategy;

	strategy = manual_sort_strategy_create();
	if (!strategy)
		return (false);
	ps->solver->set_strategy(ps->solver, strategy);
	if (!ps->solver->solve(ps->solver))
		return (false);
	return (true);
}

void	push_swap_destroy(t_push_swap *ps, int argc)
{
	if (ps->solver)
		sort_solver_destroy(ps->solver);
	if (ps->validator)
		validator_destroy(ps->validator, argc);
	free(ps);
}

int	main(int argc, char **argv)
{
	t_push_swap		*ps;

	if (argc < 2)
		return (1);
	ps = push_swap_create(argc - 1, argv + 1);
	if (!ps)
		return (ft_putstr_fd("Error\n", STDERR_FILENO), 1);
	if (!push_swap_execute(ps))
		ft_putstr_fd("Error\n", STDERR_FILENO);
	push_swap_destroy(ps, argc - 1);
	return (0);
}
