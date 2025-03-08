/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:43:43 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/07 16:06:04 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 2. Push Operations (pa, pb)
pb: push the top element of stack a onto stack B;
pa: push the top element of stack B onto stack A; */

void	push(t_stack *stack_src, t_stack *stack_dest)
{
	int	i;

	if (stack_src->size <= 0)
		return ;
	i = stack_dest->size;
	while (i > 0) // shifts up destination stack
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
	stack_dest->size++; // Update sizes
	stack_src->size--;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push (stack_a, stack_b);
	printf("pb\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push (stack_b, stack_a);
	printf("pa\n");
}
