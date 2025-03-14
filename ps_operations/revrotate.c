/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:43:49 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/07 13:48:49 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	last;

	if (stack->size > 1)
	{
		last = stack->arr[stack->size - 1];
		i = stack->size - 1;
		while (i > 0)
		{
			stack->arr[i] = stack->arr[i - 1];
			i--;
		}
		stack->arr[0] = last;
	}
}

void	rra(t_stack *stack_a)
{
	reverse_rotate (stack_a);
	printf ("rra\n");
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate (stack_b);
	printf ("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate (stack_a);
	reverse_rotate (stack_b);
	printf ("rrr\n");
}
