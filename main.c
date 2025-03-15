/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 03:25:15 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/15 16:24:45 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		size_a;
	int		i;
	int		*temp;

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
	select_sorting(&stack_a, &stack_b);

	free(stack_a.arr);
	free(stack_b.arr);
	return (0);
}

int	parse_args(int ac, char **av, t_stack *stack_a, int *size)
{
	int	*temp;

	if (ac == 2 && strchr(av[1], ' '))
		temp = init_arr_str(av, size);
	else
		temp = init_arr_int(ac, av, size);
	if (!temp || (stack_a->arr = temp) == NULL)
		return (0);
	stack_a->size = *size;
	if (check_data(stack_a))
		return (free(temp), 0);
	temp = map_to_ranks(stack_a);
	if (!temp)
		return (free(stack_a->arr), 0);
	free (stack_a->arr);
	return ((stack_a->arr = temp) != NULL);
}

int	check_sorted(t_stack *stack_a, t_stack *stack_b)
{
	if (check_if_sorted(stack_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	init_stack_b(t_stack *stack_b, t_stack size_a)
{
	stack_b->arr = (int *)malloc(sizeof(int) * size_a);
	if (!stack_b->arr)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack_b->size = 0;
	return (1);
}

int	error_exit(t_stack *stack_a, t_stack *stack_b, int code)
{
	if (stack_a->arr)
		free (stack_a->arr);
	if (stack_b->arr)
		free (code);
}

void	select_sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sa(stack_a);
	else if (stack_a->size == 3)
		sort_three(&stack_a);
	else if (stack_a->size == 4 || stack_a->size == 5)
		sort_five(&stack_a, &stack_b);
	else
		chunk_sort(&stack_a, &stack_b);
}




/* 
if (stack_a.size == 2)
sa(&stack_a);
else if (stack_a.size == 3)
sort_three(&stack_a);
else if (stack_a.size == 4 || stack_a.size == 5)
sort_five(&stack_a, &stack_b);
else
chunk_sort(&stack_a, &stack_b);
















*/