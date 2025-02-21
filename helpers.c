/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:10:02 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/02/21 15:10:23 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     count_words(char *str)
{
    int     wc;

    wc = 0;
    while (*str)
    {
        while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
            str++;
        if (*str)
            wc++;
        while (*str && (*str != ' ' && *str != '\t' && *str != '\n'))
            str++;
    }
    return (wc);
}

char	*ft_strndup(const char *src, int len)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	is_valid_int(const char *str)
{
	int				i;
	int				sign;
	long long		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\f')
		i++;
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
		if ((sign == 1 && result > INT_MAX) || (sign == -1 && -result < INT_MIN))
			return (0);
		i++;
	}
	return (str[i] == '\0'); // Ensure the entire string was a valid number
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		result = (result * 10) + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1 && -result < INT_MIN))
			return (0);
		i++;
	}
	return ((int)result * sign);
}


int	check_sorted_or_error(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}