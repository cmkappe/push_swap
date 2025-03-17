/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:35:50 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/17 15:36:27 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
