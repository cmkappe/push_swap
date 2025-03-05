/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:35:23 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/03/05 10:25:25 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr

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

/* 2. Push Operations (pa, pb)
pb: push the top element of stack a onto stack B;
pa: push the top element of stack B onto stack A; */

/* 				src				dest; */
				
void	push(t_stack stack_src, t_stack stack_dest)
{
	int		i;

	if (stack_src.size <= 0)
		return;
	i = stack_dest.size;
	
	while (i > 0) // shifts up destination stack
	{
		stack_dest.arr[i] = stack_dest.arr[i - 1];
		i--;
	}
	stack_dest.arr[0] = stack_src.arr[0];
	i = 0;

	while (i < stack_src.size - 1)
	{
		stack_src.arr[i] = stack_src.arr[i + 1];
		i++;
	}
	(stack_dest.size)++; // Update sizes
    (stack_src.size)--;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push (*stack_a, *stack_b);
	printf("pb\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push (*stack_b, *stack_a);
	printf("pa\n");
}


// ra, rb, rr

void	rotate(t_stack *stack)
{
	int		i;
	int		first;

	if (stack->size <= 1)
		return;
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

void	rrb (t_stack *stack_b)
{
	reverse_rotate (stack_b);
	printf ("rrb\n");
}

void	rrr (t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate (stack_a);
	reverse_rotate (stack_b);
	printf ("rrr\n");
}

