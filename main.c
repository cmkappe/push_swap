/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 03:25:15 by ckappe            #+#    #+#             */
/*   Updated: 2025/02/12 17:42:17 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	leaks(void)
{
	system ("leaks a.out");
}

int main (int ac, char **av)
{
	int	*array;
	int	size;
	
	atexit (leaks);
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		array = init_arr_str(av, &size);
	// if (ac > 2)
	else
		array = init_arr_int(ac, av, &size);
	if (!array)
	{
		printf("Error in init_arr!\n");
		return (1);
	}
	
	if (check_data(array, size))
	{
		free(array);
		return (1);
		
	}	
	int i = 0;
	while (i < size)
		printf("%d\n", array[i++]);
	free(array);
	return (0);
}

    // char    *test = " 2 64 784 5648 1154  87484 41548";
	// char 	**splited;

	
	// splited = ft_split(test);
	// while (*splited) // Correct the loop to check for the end of the array
	// {
	// 	printf("%s\n", *splited);
	// 	splited++;
	// }
    // printf("word count is %d\n", count_words(test));
