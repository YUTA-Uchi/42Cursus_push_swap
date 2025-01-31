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

t_push_swap	*push_swap_create(int argc, char **argv)
{
	t_push_swap	*ps;

	ps = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!ps)
		return (NULL);
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

int	push_swap_execute(t_push_swap *ps)
{
	t_sort_strategy	*strategy;

	strategy = turkey_sort_strategy_create(15);
	if (!strategy)
		return (1);
	ps->solver->set_strategy(ps->solver, strategy);
	ps->solver->solve(ps->solver);
	return (0);
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
	int				result;

	if (argc < 2)
		return (ft_putstr_fd("Error1\n", 2), 1);
	ps = push_swap_create(argc - 1, argv + 1);
	if (!ps)
		return (ft_putstr_fd("Error2\n", 2), 1);
	result = push_swap_execute(ps);
	if (result)
		ft_putstr_fd("Error3\n", 2);
	push_swap_destroy(ps, argc - 1);
	return (0);
}
