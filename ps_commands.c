/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:35:23 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/02/15 23:37:30 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr

void	ft_swap (int	*stack, int	size)
{
	int		temp;

	temp = 0;
	if (size > 1)
	{
		temp = stack[0];
		stack[0] = stack[1];
		stack[1] = temp;
	}
}

/* Swap Operations (sa, sb, ss)
sa: swap the first two elements of stack A.
sb: swap the first two elements of stack B.
ss: swap both A and B at the same time. */

void	sa (int	*stack_a, int size_a)
{
	ft_swap(stack_a, size_a);
	printf("sa\n");
}

void	sb (int	*stack_b, int size_b)
{
	ft_swap(stack_b, size_b);
	printf ("sb\n");
}

void	ss(int *stack_a, int size_a, int *stack_b, int size_b)
{
	ft_swap(stack_a, size_a);
	ft_swap(stack_b, size_b);
	printf("ss\n");
}

/* 2. Push Operations (pa, pb)
pb: push the top element of stack a onto stack B.
pa: push the top element of stack B onto stack A. */

void	push (int *src, int *src_size, int *dest, int *dest_size)
{
	int		i;
	// ff source stack is empty, do nothing

	i = *dest_size;
	
}

void	pb (int *stack_a, int *size_a, int *stack_b, int *size_b)
{
	push (stack_a, size_a, stack_b, size_b);
	printf("pb\n");
}

void	pa (int *stack_a, int *size_a, int *stack_b, int *size_b)
{
	push (stack_b, size_b, stack_a, size_a);
	printf("pa\n");
}

int main ()
{
	
}