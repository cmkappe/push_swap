/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:44:00 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/03/04 19:00:23 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	if (stack->arr[0] < stack->arr[1] && stack->arr[1] < stack->arr[2])
		return;
	else if (stack->arr[0] > stack->arr[1] && stack->arr[0] > stack->arr[2])
	{
		ra(stack);
		return;
	}
	else if (stack->arr[0] > stack->arr[1] && stack->arr[1] > stack->arr[2])
	{
		sa(stack);
		return;
	}
	else if (stack->arr[2] > stack->arr[1] && stack->arr[2] > stack->arr[0])
	{
		ra(stack);
		sa(stack);
		return;
	}
	else if (stack->arr[1] > stack->arr[0] && stack->arr[1] > stack->arr[2])
	{
		sa(stack);
		ra(stack);
		return;
	}
	else
	{
		rra(stack);
		return;
	}
}

/* ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one. */


int main()
{
	t_stack	stack_a;
	int	i;
	
	stack_a.size = 3;
	stack_a.arr = (int *)malloc(sizeof(int) * stack_a.size);
	if (!stack_a.arr)
		return (1);
	
	i = 0;
	while (i < stack_a.size)
	{
		if (i == 0)
			stack_a.arr[i] = 3;
		else if (i == 1)
			stack_a.arr[i] = 1;
		else
			stack_a.arr[i] = 2;
		i++;
	}
	
	printf("stack_a before sorting ");
	i = 0;
	while (i < stack_a.size)
	{
		printf("%d", stack_a.arr[i]);
		i++;
	}
	printf("\n");

	sort_three(&stack_a);

	printf("stack_a after sorting ");
	i = 0;
	while (i < stack_a.size)
	{
		printf("%d", stack_a.arr[i]);
		i++;
	}
	printf("\n");

	free(stack_a.arr);
	return (0);
}