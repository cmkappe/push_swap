/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:38:13 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/03/18 19:18:26 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_best_spot(t_stack *stack_a, int value)
{
	int	i;
	int	best_index;

	i = 0;
	best_index = stack_a->size;
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

/* 
Goal of process_chunk: 
Move elements from stack_a to stack_b within a value range (low to high),
	keeping partial order in stack_b.
Key Steps
    Calculate Midpoint:
    mid = (low + high) / 2 splits the chunk into lower and upper halves.
    Find and Move Elements:
        Locate elements in stack_a within the chunk using find_index_in_chunk.
        Bring them to the top of stack_a with bring_to_top.
    Push to stack_b:
        Values ≤ mid → Simple push (pb).
        Values > mid → Push and rotate down stack_b (pb + rb) to group larger 
			values at the bottom.
    Finalize stack_b Order:
        Rotate stack_b (rrb) if the top element is smaller than the next,
			ensuring ascending order.
Edge Cases Handled
    Empty chunks.
    Elements at the bottom of stack_a.
    Maintaining order in stack_b for efficient merging.
 */

void	process_chunk(t_stack *stack_a, t_stack *stack_b, int low, int high)
{
	int	index;
	int	mid;

	mid = (low + high) / 2;
	index = find_index_in_chunk(stack_a, low, high);
	while (index != -1)
	{
		bring_to_top(stack_a, index, 'a');
		if (stack_a->arr[0] <= mid)
			pb(stack_a, stack_b);
		else
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		index = find_index_in_chunk(stack_a, low, high);
	}
	while (stack_b->size > 1 && stack_b->arr[0] < stack_b->arr[1])
		rrb(stack_b);
}

/* 
Goal of reassemble_chunk: 
Merge sorted chunks from stack_b back into stack_a in ascending order.
Key Steps
    Find Largest in stack_b:
    	index_b = find_index_of_max(stack_b) finds the largest remaining value.
    Determine Insertion Point in stack_a:
    	index_a = find_best_spot(stack_a, value) finds where 
		the value fits in stack_a.
    Align Stacks:
   		bring_to_top_both rotates stack_a and stack_b to minimize moves.
    Push Back to stack_a:
    	pa moves the value from stack_b to stack_a.
Edge Cases Handled
    Merging chunks of different sizes.
    Aligning stacks when elements are at opposite ends.
 */

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
		bring_to_top_both(stack_a, index_a, stack_b, index_b);
		pa(stack_a, stack_b);
	}
}

/* 
Goal of chunk_sort: Orchestrate the chunk sorting process.
Key Steps
    Initialize Chunks:
        Calculate num_chunks based on stack_a size 
			(e.g., 5 chunks for 100 elements).
        For each chunk, determine its low/high range with get_chunk_limits.
    Process All Chunks:
   		Call process_chunk for each range to distribute elements to stack_b.
    Merge Back:
    	Use reassemble_stack to rebuild stack_a in sorted order.
    Final Rotation:
		final_rotate ensures the smallest element is at the top of stack_a.
Edge Cases Handled
    Small input sizes (e.g., 2–5 elements use simpler sorts).
    Uneven chunk sizes.
 */

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
