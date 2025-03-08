/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_prep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 00:25:27 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/03/07 15:24:40 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	decide_chunks(int size)
{
	if (size <= 100)
		return (5);
	else if (size <= 500)
		return (10);
	else
		return (20);
}

void	get_chunk_limits(int chunk_index, t_stack *stack, int *low, int *high)
{
	int	chunk_size;
	int	amount_chunks;

	amount_chunks = decide_chunks(stack->size);
	chunk_size = stack->size / amount_chunks;
	*low = chunk_index * chunk_size;
	if (chunk_index == amount_chunks - 1)
		*high = stack->size - 1;
	else
		*high = (chunk_index + 1) * chunk_size - 1;
}

/* int	find_index_in_chunk(int *stack, int size, int low, int high)
{
	int	i;
	int	index_top;
	int	index_bottom;

	i = 0;
	index_top = -1;
	while (i < size)
	{
		if (stack[i] >= low && stack[i] <= high)
		{
			index_top = i;
			break;
		}
		i++;
	}
	i = size - 1;
	index_bottom = -1;
	while (i >= 0)
	{
		if (stack[i] >= low && stack[i] <= high)
		{
			index_bottom = i;
			break;
		}
		i--;
	}
	if (index_top == -1)
		return (-1);
	if (index_bottom == -1)
		return (index_top);
	if (index_top <= (size - index_bottom))
		return (index_top);
	else
		return (index_bottom);
} */
