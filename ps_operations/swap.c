/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:43:29 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/18 19:22:02 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 
Purpose: Swap the top two elements of the stack.
Key Steps:
    Store the first element in a temporary variable.
    Assign the second element to the first position.
    Assign the temporary value to the second position.
Edge Cases:
    Does nothing if the stack has ≤ 1 element.
*/

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

/* Swap Operations (sa, sb, ss)
sa: swap the first two elements of stack A.
sb: swap the first two elements of stack B.
ss: swap both A and B at the same time. */

void	sa(t_stack	*stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack	*stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}
