/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_ranks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:56:05 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/03/05 16:13:10 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_array(t_stack *arr)
{
	int	i;
	int	*copy;

	i = 0;
	copy = (int *)malloc(sizeof(int) * arr->size);
	if (!copy)
		return (NULL);
	while (i < arr->size)
	{
		copy[i] = arr->arr[i];
		i++;
	}
	return (copy);
}

void	bubble_sort(t_stack *arr)
{
	int	i;
	int	swapped;
	int	temp;

	swapped = 1;
	while (swapped)
	{
		i = 0;
		swapped = 0;
		while (i < arr->size - 1)
		{
			if (arr->arr[i] > arr->arr[i + 1])
			{
				temp = arr->arr[i];
				arr->arr[i] = arr->arr[i + 1];
				arr->arr[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

void	fill_mapping(t_stack *arr, int *copy, int *mapped)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr->size)
	{
		j = 0;
		while (j < arr->size)
		{
			if (arr->arr[i] == copy[j])
			{
				mapped[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	*map_to_ranks(t_stack *arr)
{
	int	*copy;
	int	*mapped;

	copy = copy_array(arr);
	if (!copy)
		return (NULL);
	bubble_sort(copy);
	mapped = (int *)malloc(sizeof(int) * arr->size);
	if (!mapped)
	{
		free(copy);
		return (NULL);
	}
	fill_mapping(arr, copy, mapped);
	free(copy);
	return (mapped);
}
