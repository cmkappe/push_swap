/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 03:25:15 by ckappe            #+#    #+#             */
/*   Updated: 2025/02/11 04:38:28 by ckappe           ###   ########.fr       */
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
	
	atexit (leaks);
	if (ac < 2)
		return (0);
	if (ac == 2)
		array = init_arr_str(av);
	if (ac > 2)
		array = init_arr_int(ac, av);
	int i = 0;
	while (array[i])
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
