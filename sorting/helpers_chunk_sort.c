/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_chunk_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:27:51 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/11 16:59:09 by ckappe           ###   ########.fr       */
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

int	find_index_of_min(t_stack *stack)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = stack->arr[0];
	index = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] < min)
		{
			min = stack->arr[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	find_best_spot(t_stack *stack_a, int value)
{
	int	i;

	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->arr[i] > value)
			return (i);
		i++;
	}
	return (0);
}


/* int	find_best_spot(t_stack *stack_a, int value)
{
	int	i;
	int	best_index;

	i = 0;
	best_index = stack_a->size;

	printf("Finding best spot for %d in A\n", value);
	
	while (i < stack_a->size)
	{
		if (stack_a->arr[i] > value)
		{
			best_index = i;
			break ;
		}
		i++;
	}

	printf("Best spot for %d is index %d\n", value, best_index);

	return (best_index);
} */



/* int	find_index_of_min(int *stack, int size)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = stack[0];
	index = 0;
	while (i < size)
	{
		if (stack[i] < min)
		{
			min = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
} */