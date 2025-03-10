/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 04:14:38 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/10 16:15:22 by ckappe           ###   ########.fr       */
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
	if (!(array = (int *)malloc(sizeof(int) * (*size))))
		return (NULL);
	i = 0;
	while (stack_data[i])
	{
		if (!is_valid_int(stack_data[i])) // Input validation
		{
			free_split(stack_data, i - 1);
			free(array);
			return (NULL);
		}
		array[i] = ft_atoi(stack_data[i]);
		i++;
	}
	i = 0;
	while (stack_data[i])
		free (stack_data[i++]);
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
		if (!is_valid_int(av[i + 1]))
		{
			free(arr);
			return (NULL);
		}
		arr[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (arr);
}
