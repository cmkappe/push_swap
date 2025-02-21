/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_ranks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:56:05 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/02/21 15:56:13 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * map_to_ranks: Given an array 'arr' of length 'size', 
 * returns a new array where each element is replaced by its rank
 * The smallest element gets rank 0, the next gets 1, ...;
 *
 * uses bubble sort to sort a copy of the arry
 */

/* int	*map_to_ranks(int *arr, int size)
{
	int	*copy;
	int	i;
	int	swapped;
	int	temp;
	int	*mapped;
	int	j;

	// copy of the original array
	if (!(copy = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = arr[i];
		i++;
	}

	// sort the copy with bubble sort
	
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (copy[i] > copy[i + 1])
			{
				temp = copy[i];
				copy[i] = copy[i + 1];
				copy[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
 	// Allocate array for mapped values
	mapped = (int *)malloc(sizeof(int) * size);
	if (!mapped)
	{
		free(copy);
		return (NULL);
	}


	// for each element in the original array, find its rank in the sorted copy
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == copy[j])
			{
				mapped[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
	free(copy);
	return (mapped);
} */




int	*copy_array(int *arr, int size)
{
	int	i;
	int	*copy;

	i = 0;
	copy = (int *)malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	while (i < size) // why not size - 1
	{
		copy[i] = arr[i];
		i++;
	}
	return (copy);
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	swapped;
	int	temp;
	
	swapped = 1;
	while (swapped)
	{
		i = 0;
		swapped = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

void	fill_mapping(int *arr, int *copy, int *mapped, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == copy[j])
			{
				mapped[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
}

int	*map_to_ranks(int *arr, int size)
{
	int	*copy;
	int	*mapped;

	copy = copy_array(arr, size);
	if (!copy)
		return (NULL);
	bubble_sort(copy, size);
	mapped = (int *)malloc(sizeof(int) * size);
	if (!mapped)
	{
		free(copy);
		return (NULL);
	}
	fill_mapping(arr, copy, mapped, size);
	free(copy);
	return (mapped);
}
