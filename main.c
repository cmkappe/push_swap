/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 03:25:15 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/14 17:19:20 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static void	leaks(void)
{
	system ("leaks push_swap");
} */



int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		size_a;
	// int		size_b;
	// int		i;
	int		*temp;

	// atexit (leaks);
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);

	if (ac == 2 && strchr(av[1], ' ') != NULL)
		temp = init_arr_str(av, &size_a);
	else
		temp = init_arr_int(ac, av, &size_a);
	if (!temp)
	{
		write(2, "Error\n", 6);
		return (1);
	}

	stack_a.arr = temp;
	stack_a.size = size_a;

	/* validate data */
	if (check_data(&stack_a))
		return (1);

	temp = map_to_ranks(&stack_a);
	if (!temp)
	{
		write(2, "Error\n", 6);
		free(stack_a.arr);
		return (1);
	}
	free(stack_a.arr);
	stack_a.arr = temp;


	// initializing stack_b as an empty stack with max size of stack_a
	stack_b.arr = (int *)malloc(sizeof(int) * size_a);
	if (!stack_b.arr)
	{
		free(stack_a.arr);
		return (1);
	}
	stack_b.size = 0;
	if (check_if_sorted(&stack_a))
	{
		write(2, "Error\n", 6);
		free(stack_a.arr);
		free(stack_b.arr);
		return (0);
	}
	if (stack_a.size == 2)
		sa(&stack_a);
	else if (stack_a.size == 3)
		sort_three(&stack_a);
	else if (stack_a.size == 4 || stack_a.size == 5)
		sort_five(&stack_a, &stack_b);
	else
		chunk_sort(&stack_a, &stack_b);



/*   	// Print final sorted stack
	printf("\nAfter sorting, Stack A: ");
	i = 0;
	while (i < stack_a.size)
	{
		printf("%d ", stack_a.arr[i]);
		i++;
	}
	printf("\n"); */

	free(stack_a.arr);
	free(stack_b.arr);
	return (0);
}

