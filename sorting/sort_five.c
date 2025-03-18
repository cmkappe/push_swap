/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:46:05 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/03/18 18:02:12 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;

	while (stack_a->size > 3)
	{
		min_index = find_index_of_min(stack_a);
		bring_to_top(stack_a, min_index, 'a'),
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}
