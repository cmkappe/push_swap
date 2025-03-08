/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_chunk_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:27:51 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/07 22:00:08 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_top_index_in_chunk(t_stack *stack, int low, int high)
{
	int	i;
	int	index;

	i = 0;
	index = -1;
	while (i < stack->size)
	{
		if (stack->arr[i] >= low && stack->arr[i] <= high)
		{
			index = i;
			break ;
		}
		i++;
	}
	return (index);
}

int	find_bottom_index_in_chunk(t_stack *stack, int low, int high)
{
	int	i;
	int	index;

	i = stack->size - 1;
	index = -1;
	while (i >= 0)
	{
		if (stack->arr[i] >= low && stack->arr[i] <= high)
		{
			index = i;
			break ;
		}
		i--;
	}
	return (index);
}

int	find_index_in_chunk(t_stack *stack, int low, int high)
{
	int	top;
	int	bottom;

	top = find_top_index_in_chunk(stack, low, high);
	bottom = find_bottom_index_in_chunk(stack, low, high);
	if (top == -1)
		return (-1);
	if (bottom == -1)
		return (top);
	if (top <= (stack->size - bottom))
		return (top);
	else
		return (bottom);
}

int	find_index_of_max(t_stack *stack)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	max = stack->arr[0];
	index = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] > max)
		{
			max = stack->arr[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	find_best_spot(t_stack *stack_a, int value)
{
	int	i;
	int	best_index;

	i = 0;
	best_index = 0;
	while (i < stack_a->size)
	{
		if (stack_a->arr[i] > value)
		{
			best_index = i;
			break ;
		}
		i++;
	}
	return (best_index);
}
