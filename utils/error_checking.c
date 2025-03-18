/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 04:45:06 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/18 17:57:41 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_duplicates(t_stack *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr->size - 1)
	{
		j = i + 1;
		while (j < arr->size)
		{
			if (arr->arr[i] == arr->arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_data(t_stack *arr)
{
	if (check_duplicates(arr))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	check_if_sorted(t_stack *arr)
{
	int	i;

	i = 0;
	while (i < arr->size - 1)
	{
		if (arr->arr[i] > arr->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
/*
Purpose of is_valid_int:
Validate if a string represents a valid 32-bit integer (INT_MIN to INT_MAX).
Key Features
    Format Checks:
        Allows optional leading + or - sign.
        Rejects empty strings, lone signs (e.g., "-"), or non-digit characters.
        Ensures all characters after the sign are digits (0-9).
    Range Checks:
        Uses long long to accumulate values during parsing to detect overflow.
        Rejects values:
            Positive: > INT_MAX (2147483647).
            Negative: > INT_MAX + 1 (to cover INT_MIN = -2147483648).
Return Value
    0: Valid integer.
    1: Invalid format or out-of-range value.
Edge Cases Handled
    Overflow: "2147483648", "-2147483649".
    Invalid Formats: "12a3", "++123", "-".
    Boundaries: "2147483647" (valid), "-2147483648" (valid).

How It Works
    Initial Checks:
        First character must be +, -, or a digit.
        Sign must be followed by a digit (rejects "-" or "+123a").
    Sign Handling:
        Converts + to 1 and - to -1 via ASCII math (sign = 44 - *ptr++).
    Digit Parsing:
        Accumulates digits into a long long to detect overflow early.
    Final Check:
        Ensures the entire string is consumed (no trailing non-digit characters).
 */

int	is_valid_int(const char *str)
{
	const char	*ptr;
	int			sign;
	long long	num;

	ptr = str;
	sign = 1;
	num = 0;
	if (!(*ptr == '+' || *ptr == '-' || (*ptr >= '0' && *ptr <= '9')))
		return (1);
	if ((*ptr == '+' || *ptr == '-') && !(ptr[1] >= '0' && ptr[1] <= '9'))
		return (1);
	if (*ptr == '-' || *ptr == '+')
		sign = 44 - *ptr++;
	if (*ptr < '0' || *ptr > '9')
		return (1);
	while (*ptr >= '0' && *ptr <= '9')
	{
		num = num * 10 + (*ptr++ - '0');
		if ((sign == 1 && num > INT_MAX) || \
			(sign == -1 && num > (long)INT_MAX + 1))
			return (1);
	}
	if (*ptr != '\0')
		return (1);
	return (0);
}
