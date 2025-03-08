/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:43:35 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/07 13:50:15 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack *stack)
{
	int		i;
	int		first;

	if (stack->size <= 1)
		return ;
	i = 0;
	first = stack->arr[0];
	while (i < stack->size - 1)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[stack->size - 1] = first;
}

void	ra(t_stack *stack_a)
{
	rotate (stack_a);
	printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	rotate (stack_b);
	printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate (stack_a);
	rotate (stack_b);
	printf("rr\n");
}
