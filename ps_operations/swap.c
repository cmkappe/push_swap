/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:43:29 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/07 13:50:22 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Swap Operations (sa, sb, ss)
sa: swap the first two elements of stack A.
sb: swap the first two elements of stack B.
ss: swap both A and B at the same time. */

void	ft_swap(t_stack *stack)
{
	int		temp;

	temp = 0;
	if (stack->size > 1)
	{
		temp = stack->arr[0];
		stack->arr[0] = stack->arr[1];
		stack->arr[1] = temp;
	}
}

void	sa(t_stack	*stack_a)
{
	ft_swap(stack_a);
	printf("sa\n");
}

void	sb(t_stack	*stack_b)
{
	ft_swap(stack_b);
	printf ("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	printf("ss\n");
}
