/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_to_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:30:13 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/03/14 16:08:29 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void bring_to_top(t_stack *stack, int index, char stack_name)
{
	int	moves;

	if (index <= (stack->size / 2))
	{
		moves = index;
		rotate_up(stack, moves, stack_name);
	}
	else
	{
		moves = stack->size - index + 1;
		rotate_down(stack, moves, stack_name);
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
	int	common;

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

void	bring_to_top_both(t_stack *stack_a, int index_a,
									t_stack *stack_b, int index_b)
{
	int	moves_a;
	int	moves_b;

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
		bring_to_top(stack_a, index_a, 'a');
		bring_to_top(stack_b, index_b, 'b');
	}
}
