/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 04:14:38 by ckappe            #+#    #+#             */
/*   Updated: 2025/02/11 04:41:45 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*init_arr_str(char **av)
{
	char	**stack_data;
	int		*array;
	int		i;
	int		word_count;

		stack_data = ft_split(av[1]);
		word_count = count_words(av[1]);
		if (!(array = (int *)malloc(sizeof(int) * word_count)))
			return (NULL);
		i = 0;
		while (stack_data[i])
		{
			array[i] = atoi(stack_data[i]);
			i++;
		}
		i = 0;
		while(stack_data[i])
			free(stack_data[i++]);
		free(stack_data);
		return (array);
}

int	*init_arr_int(int ac, char **av)
{
	int		word_count;
	int		*array;
	int		i;

	word_count = ac - 1;
	if (!(array = (int *)malloc(sizeof(int) * word_count)))
			return (NULL);
	i = 0;
		while (word_count > 0)
		{
			array[i] = atoi(av[i + 1]);
			i++;
			word_count--;
		}
	return (array);
}
