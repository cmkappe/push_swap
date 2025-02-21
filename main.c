/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 03:25:15 by ckappe            #+#    #+#             */
/*   Updated: 2025/02/21 20:23:27 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static void	leaks(void)
{
	system ("leaks a.out");
} */

int main(int ac, char **av)
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	i;
	int	*mapped;
	
	// atexit (leaks);
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		stack_a = init_arr_str(av, &size_a);
	// if (ac > 2)
	else
		stack_a = init_arr_int(ac, av, &size_a);
	if (!stack_a)
	{
		printf("Error in init_arr!\n");
		return (1);
	}
	if (check_data(stack_a, size_a))
	{
		free(stack_a);
		return (1);
	}

	mapped = map_to_ranks(stack_a, size_a);
	if (!mapped)
	{
		printf("Error in mapping to ranks!\n");
		free(stack_a);
		return (1);
	}
	free(stack_a);
	stack_a = mapped;

	
	// initializing stack_b as an empty stack
	stack_b = (int *)malloc(sizeof(int) * size_a);
	if (!stack_b)
	{
		free(stack_a);
		return (1);
	}
	size_b = 0;



/*     printf("\n\nStack A (mapped) initially:\n");
	i = 0;
    while (i < size_a)
    {
        printf("%d ", stack_a[i]);
        i++;
    } */
    printf("\n\nStack B initially is empty.\n\n");

	// chunk sort

	chunk_sort(stack_a, &size_a, stack_b, &size_b);

	// print sorted stack_a
/* 	printf("\nStack a after radix sort: \n");
	i = 0;
	while (i < size_a)
	{
		printf("%d ", stack_a[i]);
		i++;
	}
	printf("\n"); */

	free(stack_a);
	free(stack_b);
	return (0);
}

    // char    *test = " 2 64 784 5648 1154  87484 41548";
	// char 	**splited;

	
	// splited = ft_split(test);
	// while (*splited)
	// {
	// 	printf("%s\n", *splited);
	// 	splited++;
	// }
    // printf("word count is %d\n", count_words(test));
