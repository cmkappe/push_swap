/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 04:14:38 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/17 17:18:44 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*init_arr_str(char **av, int *size)
{
	char	**stack_data;
	int		*array;
	int		i;

	stack_data = ft_split(av[1]);
	*size = count_words(av[1]);
	array = (int *)malloc(sizeof(int) * (*size));
	if (!array)
		return (NULL);
	i = -1;
	while (stack_data[++i])
	{
		if (is_valid_int(stack_data[i]))
			exit (write(2, "Error\n", 6));
		array[i] = ft_atoi(stack_data[i]);
		if (array[i] < INT_MIN || array[i] > INT_MAX)
			exit (write(2, "Error\n", 6));
	}
	i = -1;
	while (stack_data[++i])
		free (stack_data[i]);
	free (stack_data);
	return (array);
}

int	*init_arr_int(int ac, char **av, int *size)
{
	int		*arr;
	int		i;

	*size = ac - 1;
	arr = (int *)malloc(sizeof(int) * (*size));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < *size)
	{
		if (is_valid_int(av[i + 1]))
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		arr[i] = ft_atoi(av[i + 1]);
		if (arr[i] < INT_MIN || arr[i] > INT_MAX)
			exit (write(2, "Error\n", 6));
		i++;
	}
	return (arr);
}
