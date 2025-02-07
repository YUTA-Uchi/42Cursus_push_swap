/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_private.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:05:40 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/07 18:38:29 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator_private.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
			c == '\v' || c == '\f' || c == '\r');
}

bool	is_overflow(int result_sign, long result_num, char *str)
{
	int	num;

	num = *str - '0';
	if (result_sign == 1 && \
		(result_num > (LONG_MAX / 10) || num > LONG_MAX % 10))
	{
		return (true);
	}
	else if (result_sign == -1 && (result_sign * result_num) < (LONG_MIN / 10) \
			&& num > -(LONG_MIN % 10))
	{
		return (true);
	}
	return (false);
}

static long	ft_atol(char *str)
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
		// overflow check 9223372036854775807 ok 18446744073709551615 ok 18446744073709551616 ok 18446744073709551617 NG why?
		if (sign == 1 && is_overflow(sign, num, str))
			return (LONG_MAX);
		if (sign == -1 && is_overflow(sign, num, str))
			return (LONG_MIN);
		num = num * 10 + (*str++ - '0');
	}
	return (num * sign);
}

bool	validate_number(char *str, long *result)
{
	long	num;
	bool	is_valid;
	char	*strptr;

	is_valid = true;
	strptr = str;
	while (is_space(*strptr))
		strptr++;
	if (*strptr == '-' || *strptr == '+')
		strptr++;
	while (*strptr && is_valid)
		is_valid = ft_isdigit(*strptr++);
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
