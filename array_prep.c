/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_prep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 00:25:27 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/02/17 01:56:05 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	*map_to_ranks(int *arr, int size)
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
}



int main(void)
{
    // Test array
    int arr[] = {42, 15, 73, -8, 23, -60, 4};
    int size;
    int i;
    int *mapped;

    size = sizeof(arr) / sizeof(arr[0]);

    // Print the original array
    printf("Original array:\n");
    i = 0;
    while (i < size)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n\n");

    // Map the original array to ranks
    mapped = map_to_ranks(arr, size);
    if (!mapped)
    {
        printf("Error mapping ranks.\n");
        return (1);
    }

    // Print the mapped array
    printf("Mapped (ranked) array:\n");
    i = 0;
    while (i < size)
    {
        printf("%d ", mapped[i]);
        i++;
    }
    printf("\n\n");

    free(mapped);
    return (0);
}




