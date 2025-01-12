/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:04:12 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/01/12 19:04:13 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

bool	validate_and_init(int argc, char **argv, t_stack *a)
{
	long num;
	char *str;
	bool is_valid;

	while (--argc > 0)
	{
		str = argv[argc];
		is_valid = true;
		// 空文字チェック
		if (!*str)
			return (false);
		// 符号チェック
		if (*str == '-' || *str == '+')
			str++;
		// 数字以外チェック
		while (*str && is_valid)
			is_valid = (*str >= '0' && *str++ <= '9');
		if (!is_valid)
			return (false);
		// オーバーフローチェック & 数値変換
		num = ft_atol(argv[argc]);
		if (num > INT_MAX || num < INT_MIN)
			return (false);
		// 重複チェック & スタックAに追加
		if (has_duplicate(a, (int)num))
			return (false);
		push_front(a, (int)num);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size_a;
	int		size_b;

	// check and parse arguments
	// sort the stack
	
	return (0);
}
