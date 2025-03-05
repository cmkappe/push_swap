/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:38:13 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/03/05 10:40:36 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			break;
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
			break;
		}
		i--;
	}
	return (index);	
}

int	find_index_in_chunk(t_stack *stack, int low, int high)
{
	int	top;
	int	bottom;
	
	top = find_top_index_in_chunk(stack->arr, stack->size, low, high);
	bottom = find_bottom_index_in_chunk(stack->arr, stack->size, low, high);
	if (top == -1)
		return (-1);
	if (bottom == -1)
		return (top);
	if (top <= (stack->size - bottom))
		return (top);
	else
		return (bottom);
}

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
			break;
		}
		i++;
	}
	return (best_index);
}

void process_chunk(t_stack *stack_a, t_stack *stack_b, int low, int high)
{
	int	index;
	int	mid;
	
	mid = ((low + high) / 2);
	while (1)
	{
		index = find_index_in_chunk(stack_a->arr, stack_a->size, low, high);
		if (index == -1)
			break;
		bring_to_top(stack_a, index, 'a');
		if (stack_a->arr[0] <= mid)
		{
			pb(stack_a->arr, &(stack_a->size), stack_b->arr, &(stack_b->size));
			rb(stack_b->arr, stack_b->size);
		}
		else
			pb(stack_a->arr, &(stack_a->size), stack_b, &(stack_b->size));
	}
}


void chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	total;
	int	num_chunks;
	int	cur;
	int	low;
	int	high;
	int	index_a;
	int	index_b;
	int	value;

	total = stack_a->size;
	num_chunks = decide_chunks(total);
	cur = 0;
	while (cur < num_chunks)
	{
		get_chunk_limits(cur, total, &low, &high);
		process_chunk(stack_a, stack_b, low, high);
		cur++;
	}
	while (stack_b->size > 0)
	{
		index_b = find_index_of_max(stack_b->arr, stack_b->size);
		value = stack_b->arr[index_b];
		index_a = find_best_spot(stack_a, value);
		bring_to_top_both(stack_a->arr, &(stack_a->size), index_a, stack_b->arr, index_b);
		pa(stack_a, stack_b);
	}
}
