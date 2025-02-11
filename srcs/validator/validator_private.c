/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_private.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:05:40 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/02/11 12:47:06 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator_private.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
			c == '\v' || c == '\f' || c == '\r');
}

static long	return_limit(unsigned long long num, int sign)
{
	const unsigned long long	lim = (unsigned long long)(LONG_MAX) + 1;

	if (num >= lim && !(lim & 1) && !sign)
		return ((long)(lim - 1));
	else
		return ((long)(lim));
}

static long	ft_atol(char *str)
{
	unsigned long long			num;
	int							sign;

	num = 0;
	sign = 0;
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
		if (num <= (ULLONG_MAX / 10) && num * 10 <= (ULLONG_MAX - (*str - '0')))
			num = num * 10 + (*str++ - '0');
		else
		{
			return (return_limit(num, sign));
		}
	}
	return ((long)((num ^ sign) - sign));
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
	is_valid = ft_isdigit(*strptr++);
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
