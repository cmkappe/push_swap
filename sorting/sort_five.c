/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:46:05 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/03/11 16:56:41 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	index;
	int	value;
	int	index_a;

	while (stack_a->size > 3)
	{
		index = find_index_of_min(stack_a);
		bring_to_top_struct(stack_a, index, 'a');
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
	{
		value = stack_b->arr[0];
		index_a = find_best_spot(stack_a, value);
		bring_to_top_struct(stack_a, index_a, 'a');
		pa(stack_a, stack_b);
	}
}
