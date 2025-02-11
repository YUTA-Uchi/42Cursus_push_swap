/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort_strategy_private.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:59:37 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/11 18:01:47 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

static char	*get_next_line(int fd)
{
	char	*line;
	char	buf[2];
	ssize_t	read_size;
	char	*tmp;

	line = ft_strdup("");
	if (!line)
		return (NULL);

	while (1)
	{
		read_size = read(fd, buf, 1);
		if (read_size == -1)
		{
			free(line);
			return (NULL);
		}
		if (read_size == 0)
			break ;
		buf[read_size] = '\0';

		if (buf[0] == '\n')
			break ;
		tmp = line;
		line = ft_strjoin(line, buf);
		free(tmp);
		if (!line)
			return (NULL);
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static bool	do_operation(char *line, t_sort_solver *solver)
{
	if (ft_strncmp(line, "sa", 2) == 0)
		solver->ops->sa(solver->stack_a);
	else if (ft_strncmp(line, "sb", 2) == 0)
		solver->ops->sb(solver->stack_b);
	else if (ft_strncmp(line, "ss", 2) == 0)
		solver->ops->ss(solver->stack_a, solver->stack_b);
	else if (ft_strncmp(line, "pa", 2) == 0)
		solver->ops->pa(solver->stack_a, solver->stack_b);
	else if (ft_strncmp(line, "pb", 2) == 0)
		solver->ops->pb(solver->stack_b, solver->stack_a);
	else if (ft_strncmp(line, "ra", 2) == 0)
		solver->ops->ra(solver->stack_a);
	else if (ft_strncmp(line, "rb", 2) == 0)
		solver->ops->rb(solver->stack_b);
	else if (ft_strncmp(line, "rr", 2) == 0)
		solver->ops->rr(solver->stack_a, solver->stack_b);
	else if (ft_strncmp(line, "rra", 3) == 0)
		solver->ops->rra(solver->stack_a);
	else if (ft_strncmp(line, "rrb", 3) == 0)
		solver->ops->rrb(solver->stack_b);
	else if (ft_strncmp(line, "rrr", 3) == 0)
		solver->ops->rrr(solver->stack_a, solver->stack_b);
	else
		return (false);
	return (true);
}

bool	manual_sort(t_sort_solver *solver)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!do_operation(line, solver))
		{
			free(line);
			return (false);
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(solver->stack_a) && !solver->stack_b->top)
		ft_printf(STDOUT_FILENO, "OK\n");
	else
		ft_printf(STDOUT_FILENO, "KO\n");
	return (true);
}

void	manual_sort_strategy_destroy(t_sort_strategy *strategy)
{
	free(strategy);
}
