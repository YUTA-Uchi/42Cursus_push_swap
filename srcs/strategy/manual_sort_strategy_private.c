/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort_strategy_private.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:59:37 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/12 12:33:19 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_strategy_private.h"
#include "sort_solver_public.h"

static void	get_next_line(int fd, char **line)
{
	char	buf[2];
	ssize_t	read_size;
	char	*tmp;

	while (1)
	{
		read_size = read(fd, buf, 1);
		if (read_size == -1)
			break ;
		buf[read_size] = '\0';
		if (read_size == 0 || buf[0] == '\n')
			break ;
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
		if (!*line)
			return ;
	}
	if (read_size == -1 || ft_strlen(*line) == 0)
	{
		free(*line);
		*line = NULL;
	}
}

static bool	do_opetation_push_swap(char *line, t_sort_solver *solver)
{
	if (ft_strncmp(line, "sa", 3) == 0)
		solver->stack_a->swap(solver->stack_a);
	else if (ft_strncmp(line, "sb", 3) == 0)
		solver->stack_b->swap(solver->stack_b);
	else if (ft_strncmp(line, "ss", 3) == 0)
	{
		solver->stack_a->swap(solver->stack_a);
		solver->stack_b->swap(solver->stack_b);
	}
	else if (ft_strncmp(line, "pa", 3) == 0 && solver->stack_b->size > 0)
	{
		solver->stack_a->push(solver->stack_a \
							, solver->stack_b->pop(solver->stack_b));
	}
	else if (ft_strncmp(line, "pb", 3) == 0 && solver->stack_a->size > 0)
	{
		solver->stack_b->push(solver->stack_b \
							, solver->stack_a->pop(solver->stack_a));
	}
	else
		return (false);
	return (true);
}

static bool	do_operation_rotate(char *line, t_sort_solver *solver)
{
	if (ft_strncmp(line, "ra", 3) == 0)
		solver->stack_a->rotate(solver->stack_a);
	else if (ft_strncmp(line, "rb", 3) == 0)
		solver->stack_b->rotate(solver->stack_b);
	else if (ft_strncmp(line, "rr", 3) == 0)
	{
		solver->stack_a->rotate(solver->stack_a);
		solver->stack_b->rotate(solver->stack_b);
	}
	else if (ft_strncmp(line, "rra", 4) == 0)
		solver->stack_a->reverse_rotate(solver->stack_a);
	else if (ft_strncmp(line, "rrb", 4) == 0)
		solver->stack_b->reverse_rotate(solver->stack_b);
	else if (ft_strncmp(line, "rrr", 4) == 0)
	{
		solver->stack_a->reverse_rotate(solver->stack_a);
		solver->stack_b->reverse_rotate(solver->stack_b);
	}
	else
		return (false);
	return (true);
}

static bool	do_operation(char *line, t_sort_solver *solver)
{
	return (do_opetation_push_swap(line, solver) \
			|| do_operation_rotate(line, solver));
}

bool	manual_sort(t_sort_solver *solver)
{
	char	*line;

	line = ft_strdup("");
	if (!line)
		return (false);
	get_next_line(STDIN_FILENO, &line);
	while (line)
	{
		if (!do_operation(line, solver))
			return (free(line), false);
		free(line);
		line = ft_strdup("");
		if (!line)
			return (false);
		get_next_line(STDIN_FILENO, &line);
	}
	if (is_sorted(solver->stack_a) && !solver->stack_b->size)
		ft_printf(STDOUT_FILENO, "OK\n");
	else
		ft_printf(STDOUT_FILENO, "KO\n");
	return (true);
}
