/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:35:23 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/02/16 02:44:50 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr

void	ft_swap (int *stack, int size)
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
pb: push the top element of stack a onto stack B;
pa: push the top element of stack B onto stack A; */

void	push (int *src, int *src_size, int *dest, int *dest_size)
{
	int		i;

	if (*src_size <= 0)
		return;
	i = *dest_size;
	
	while (i > 0) // shifts up destination stack
	{
		dest[i] = dest[i - 1];
		i--;
	}
	dest[0] = src[0];
	i = 0;

	while (i < *src_size - 1)
	{
		src[i] = src[i + 1];
		i++;
	}
	(*dest_size)++; // Update sizes
    (*src_size)--;
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


// ra, rb, rr

void	rotate (int *stack, int size)
{
	int		i;
	int		first;

	if (size <= 1)
		return;
	i = 0;
	first = stack[0];
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = first;
}

void	ra (int *stack_a, int size_a)
{
	rotate (stack_a, size_a);
	printf("ra\n");
}

void	rb (int *stack_b, int size_b)
{
	rotate (stack_b, size_b);
	printf("rb\n");
}

void	rr (int *stack_a, int size_a, int *stack_b, int size_b)
{
	rotate (stack_a, size_a);
	rotate (stack_b, size_b);
	printf("rr\n");
}

void	reverse_rotate(int *stack, int size)
{
	int	i;
	int	last;
	if (size > 1)
	{
		last = stack[size - 1];
		i = size - 1;
		while (i > 0)
		{
			stack[i] = stack[i - 1];
			i--;
		}
		stack[0] = last;
	}
}

void	rra (int *stack_a, int size_a)
{
	reverse_rotate (stack_a, size_a);
	printf ("rra\n");
}

void	rrb (int *stack_b, int size_b)
{
	reverse_rotate (stack_b, size_b);
	printf ("rrb\n");
}

void	rrr (int *stack_a, int size_a, int *stack_b, int size_b)
{
	reverse_rotate (stack_a, size_a);
	reverse_rotate (stack_b, size_b);
	printf ("rrr\n");
}

/* #include <unistd.h>

static void	leaks_comm(void)
{
	system ("leaks a.out");
}

int main ()
{
	atexit (leaks_comm);
	int stack_a[5] = {1, 2, 3, 7, 5};
    int stack_b[5] = {7, 86, 536, 9, 87};
    int size_a = 5;
    int size_b = 5;
    int i;

    write(1, "Before rb:\nStack A: ", 21);
    i = 0;
    while (i < size_a)
    {
        printf("%d ", stack_a[i]);
        i++;
    }
    printf("\nStack B: ");
    i = 0;
    while (i < size_b)
    {
        printf("%d ", stack_b[i]);
        i++;
    }
    printf("\n");

    rb(stack_b, size_b);

    write(1, "After rb:\nStack A: ", 20);
    i = 0;
    while (i < size_a)
    {
        printf("%d ", stack_a[i]);
        i++;
    }
    printf("\nStack B: ");
    i = 0;
    while (i < size_b)
    {
        printf("%d ", stack_b[i]);
        i++;
    }
    printf("\n");

    return 0;
} */