/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:38:13 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/03/11 18:00:36 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	process_chunk(t_stack *stack_a, t_stack *stack_b, int low, int high)
{
	int	index;
	int	mid;

	mid = ((low + high) / 2);
	index = find_index_in_chunk(stack_a, low, high);
	while (index != -1)
	{
		bring_to_top_struct(stack_a, index, 'a');
		if (stack_a->arr[0] <= mid)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else
			pb(stack_a, stack_b);
	}
}

void	reassemble_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	index_a;
	int	index_b;
	int	value;

	while (stack_b->size > 0)
	{
		index_b = find_index_of_max(stack_b);
		value = stack_b->arr[index_b];
		index_a = find_best_spot(stack_a, value);
		bring_to_top_both_struct(stack_a, index_a, stack_b, index_b);
		pa(stack_a, stack_b);
	}
}

void	chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	original_total;
	int	num_chunks;
	int	cur;
	int	low;
	int	high;

	original_total = stack_a->size;
	num_chunks = decide_chunks(original_total);
	cur = 0;
	while (cur < num_chunks)
	{
		get_chunk_limits(cur, original_total, &low, &high);
		process_chunk(stack_a, stack_b, low, high);
		cur++;
	}
	reassemble_stack(stack_a, stack_b);
	final_rotate(stack_a);
}

/* void	partition_chunks(t_stack *stack_a, t_stack *stack_b)
{
	int	total;
	int	num_chunks;
	int	cur;
	int	low;
	int	high;

	total = stack_a->size;
	num_chunks = decide_chunks(total);
	cur = 0;
	while (cur < num_chunks)
	{
		get_chunk_limits(cur, stack_a, &low, &high);
		process_chunk(stack_a, stack_b, low, high);
		cur++;
	}
} */
