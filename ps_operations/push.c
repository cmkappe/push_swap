/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:43:43 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/18 19:19:28 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Purpose: Move the top element from stack_src to the top of stack_dest.
Key Steps:
    Shift all elements in stack_dest up by 1 position to make space.
    Copy the top element of stack_src to stack_dest[0].
    Shift all elements in stack_src down by 1 to fill the gap.
    Update sizes: stack_dest->size++, stack_src->size--.
Edge Cases:
    Does nothing if stack_src is empty.
*/

void	push(t_stack *stack_src, t_stack *stack_dest)
{
	int	i;

	if (stack_src->size <= 0)
		return ;
	i = stack_dest->size;
	while (i > 0)
	{
		stack_dest->arr[i] = stack_dest->arr[i - 1];
		i--;
	}
	stack_dest->arr[0] = stack_src->arr[0];
	i = 0;
	while (i < stack_src->size - 1)
	{
		stack_src->arr[i] = stack_src->arr[i + 1];
		i++;
	}
	stack_dest->size++;
	stack_src->size--;
}

/* 2. Push Operations (pa, pb)
pb: push the top element of stack a onto stack B;
pa: push the top element of stack B onto stack A; */

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push (stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push (stack_b, stack_a);
	write(1, "pa\n", 3);
}
