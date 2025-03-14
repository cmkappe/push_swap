/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:49:49 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/03/14 01:20:59 by chiarakappe      ###   ########.fr       */
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
	while (i < count - 1)
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

void	final_rotate(t_stack *stack)
{
	int	min_index;

	min_index = find_index_of_min(stack);
	if (min_index <= stack->size / 2)
		rotate_up(stack, min_index, 'a');
	else
		rotate_down(stack, stack->size - min_index, 'a');
}
