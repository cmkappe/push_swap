/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error_checking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 04:45:06 by ckappe            #+#    #+#             */
/*   Updated: 2025/02/12 19:43:47 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(int *arr, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_data(int *arr, int size)
{
	if (check_duplicates(arr, size))
	{
		printf("Error: duplicates!");
		return (1);
	}
	return (0);
}

