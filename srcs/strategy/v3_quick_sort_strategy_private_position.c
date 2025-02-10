/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_quick_sort_strategy_private_position.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:52:57 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/10 18:53:17 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_solver_public.h"
#include "sort_strategy_private.h"

t_stack_pos	get_max_pos(t_stack_pos pos)
{
	if (pos == TOP_A)
		return (BOTTOM_A);
	else if (pos == BOTTOM_A)
		return (TOP_A);
	else if (pos == TOP_B)
		return (TOP_A);
	else
		return (TOP_A);
}

t_stack_pos	get_mid_pos(t_stack_pos pos)
{
	if (pos == TOP_A)
		return (TOP_B);
	else if (pos == BOTTOM_A)
		return (TOP_B);
	else if (pos == TOP_B)
		return (BOTTOM_A);
	else
		return (BOTTOM_A);
}

t_stack_pos	get_min_pos(t_stack_pos pos)
{
	if (pos == TOP_A)
		return (BOTTOM_B);
	else if (pos == BOTTOM_A)
		return (BOTTOM_B);
	else if (pos == TOP_B)
		return (BOTTOM_B);
	else
		return (TOP_B);
}
