/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:30:13 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/03/10 18:25:08 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_up(t_stack *stack, int count, char stack_name)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (stack_name == 'a')
			ra(stack);
		else
			rb(stack);
		i++;
	}
}

void	rotate_down(t_stack *stack, int count, char stack_name)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (stack_name == 'a')
			rra(stack);
		else
			rrb(stack);
		i++;
	}
}

void	simultaneous_rotate_up_common(t_stack *stack_a,
										t_stack *stack_b, int common)
{
	int	i;

	i = 0;
	while (i < common)
	{
		rr(stack_a, stack_b);
		i++;
	}
}

void	simultaneous_rotate_down_common(t_stack *stack_a,
										t_stack *stack_b, int common)
{
	int	i;

	i = 0;
	while (i < common)
	{
		rrr(stack_a, stack_b);
		i++;
	}
}

void	finish_rotate_up(t_stack *stack, int diff, char stack_name)
{
	int	i;

	i = 0;
	while (i < diff)
	{
		if (stack_name == 'a')
			ra(stack);
		else
			rb(stack);
		i++;
	}
}

void	finish_rotate_down(t_stack *stack, int diff, char stack_name)
{
	int	i;

	i = 0;
	while (i < diff)
	{
		if (stack_name == 'a')
			rra(stack);
		else
			rrb(stack);
		i++;
	}
}

void bring_to_top_struct(t_stack *stack, int index, char stack_name)
{
	int	moves;

	printf("Bringing %d (from %c) to top at index %d\n", stack->arr[index], stack_name, index);

	if (index <= (stack->size / 2))
	{
		moves = index;
		while (moves > 0)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
			moves--;
		}
	}
	else
	{
		moves = stack->size - index;
		while (moves > 0)
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
			moves--;
		}
	}
}

void bring_to_top_both_up(t_stack *stack_a, int moves_a,
							t_stack *stack_b, int moves_b)
{
	int	common;

	if (moves_a < moves_b)
		common = moves_a;
	else
		common = moves_b;
	simultaneous_rotate_up_common(stack_a, stack_b, common);
	if (moves_a > moves_b)
		finish_rotate_up(stack_a, moves_a - moves_b, 'a');
	else if (moves_b > moves_a)
		finish_rotate_up(stack_b, moves_b - moves_a, 'b');
}


void bring_to_top_both_down(t_stack *stack_a, int moves_a,
                            t_stack *stack_b, int moves_b)
{
	int common;

	if (moves_a < moves_b)
		common = moves_a;
	else
		common = moves_b;
	simultaneous_rotate_down_common(stack_a, stack_b, common);
	if (moves_a > moves_b)
		finish_rotate_down(stack_a, moves_a - moves_b, 'a');
	else if (moves_b > moves_a)
		finish_rotate_down(stack_b, moves_b - moves_a, 'b');
}

void	bring_to_top_both_struct(t_stack *stack_a, int index_a,
									t_stack *stack_b, int index_b)
{
	int	moves_a;
	int	moves_b;

	printf("Moving A[%d] to %d, B[%d] to %d\n", stack_a->arr[index_a], index_a, stack_b->arr[index_b], index_b);
	

	if (index_a <= ((stack_a->size) / 2))
		moves_a = index_a;
	else
		moves_a = stack_a->size - index_a;
	if (index_b <= ((stack_b->size) / 2))
		moves_b = index_b;
	else
		moves_b = stack_b->size - index_b;
	if (index_a <= ((stack_a->size) / 2) && index_b <= ((stack_b->size) / 2))
		bring_to_top_both_up(stack_a, moves_a, stack_b, moves_b);
	else if (index_a > ((stack_a->size) / 2) && index_b > ((stack_b->size) / 2))
		bring_to_top_both_down(stack_a, moves_a, stack_b, moves_b);
	else
	{
		bring_to_top_struct(stack_a, index_a, 'a');
		bring_to_top_struct(stack_b, index_b, 'b');
	}
}
