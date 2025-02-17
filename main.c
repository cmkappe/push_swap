/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 03:25:15 by ckappe            #+#    #+#             */
/*   Updated: 2025/02/17 00:42:31 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	leaks(void)
{
	system ("leaks a.out");
}

int main(int ac, char **av)
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	i;
	
	atexit (leaks);
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

	// initialization of stack_b
	stack_b = (int *)malloc(sizeof(int) * size_a);
	if (!stack_b)
	{
		free(stack_a);
		return (1);
	}
	size_b = 0;
	i = 0;

	// printing both stacks before any operation
    printf("\n\nStack A initially:\n");
    while (i < size_a)
    {
        printf("%d ", stack_a[i]);
        i++;
    }
    printf("\n\nStack B initially is empty.\n\n");

	// testing functionality of stacks with pb
	pb(stack_a, &size_a, stack_b, &size_b);
	pb(stack_a, &size_a, stack_b, &size_b);

    printf("After two pb operation:\n\n");
    printf("Stack A:\n");
    i = 0;
    while (i < size_a)
    {
        printf("%d ", stack_a[i]);
        i++;
    }
    printf("\nStack B:\n");
    i = 0;
    while (i < size_b)
    {
        printf("%d ", stack_b[i]);
        i++;
    }
    printf("\n\n\n");

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
