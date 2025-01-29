/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_private.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:05:40 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/01/29 20:06:14 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator_private.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
			c == '\v' || c == '\f' || c == '\r');
}

static long	ft_atol(const char *str)
{
	unsigned long	num;
	int				sign;

	num = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		num = num * 10 + (*str++ - '0');
		if (sign == 1 && num > LONG_MAX)
			return (LONG_MAX);
		if (sign == -1 && num > (unsigned long)LONG_MAX + 1)
			return (LONG_MIN);
	}
	return (num * sign);
}

bool	validate_number(const char *str, long *result)
{
	long	num;
	bool	is_valid;

	is_valid = true;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && is_valid)
		is_valid = ft_isdigit(*str++);
	if (!is_valid)
		return (false);
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (false);
	*result = num;
	return (true);
}

int	check_duplicates(int *nums, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (nums[i] == nums[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
