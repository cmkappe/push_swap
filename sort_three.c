/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:44:00 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/03/05 15:38:02 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// put check_if_sorted in front

/* test cases:

2 1 3
3 2 1
1 3 2
2 3 1
3 1 2 */

void	sort_three(t_stack *stack)
{
	if (stack->arr[0] > stack->arr[1] && stack->arr[0] < stack->arr[2])
		sa(stack);
	else if (stack->arr[0] > stack->arr[1] && stack->arr[1] > stack->arr[2])
	{
		ra(stack);
		sa(stack);
	}
	else if (stack->arr[0] < stack->arr[1] && stack->arr[2] > stack->arr[0])
	{
		sa(stack);
		ra(stack);
	}
	else if (stack->arr[1] > stack->arr[0] && stack->arr[0] > stack->arr[2])
		rra(stack);
	else if (stack->arr[0] > stack->arr[1] && stack->arr[1] < stack->arr[2])
		ra(stack);
	return ;
}
