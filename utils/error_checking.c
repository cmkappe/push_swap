/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 04:45:06 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/15 14:22:34 by ckappe           ###   ########.fr       */
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
		free (arr->arr);
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

static int	skip_special_char(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\f')
		i++;
	return (i);
}

int	is_valid_int(const char *str)
{
	int				i;
	int				sign;
	long long		result;

	i = skip_special_char(str);
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9') // check if there's no digit at all
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result > (long long)INT_MAX + 1))
			return (0);
		i++;
	}
	return (str[i] == '\0');
}
