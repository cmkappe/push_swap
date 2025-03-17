/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 03:25:15 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/17 16:33:00 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static void	leaks(void)
{
	system ("leaks push_swap");
}
 */


int	parse_and_validate_args(int ac, char **av, t_stack *stack_a, int *size)
{
	int	*temp_arr;

	temp_arr = NULL;
	if (ac == 2 && strchr(av[1], ' '))
		temp_arr = init_arr_str(av, size);
	else
		temp_arr = init_arr_int(ac, av, size);
	if (!temp_arr || check_data(stack_a))
	{
		free(temp_arr);
		return (0);
	}
	stack_a->arr = temp_arr;
	stack_a->size = *size;
	temp_arr = map_to_ranks(stack_a);
	if (!temp_arr)
	{
		free(stack_a->arr);
		stack_a->arr = NULL;
		return (0);
	}
	free(stack_a->arr);
	stack_a->arr = temp_arr;
	return (1);
}

int	init_stack_b(t_stack *stack_b, int size_a)
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

int	clean_exit(t_stack *stack_a, t_stack *stack_b, int code)
{
	if (stack_a->arr)
		free (stack_a->arr);
	if (stack_b->arr)
		free (stack_b->arr);
	stack_a = NULL;
	stack_b = NULL;
	return (code);
}

void	select_sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sa(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4 || stack_a->size == 5)
		sort_five(stack_a, stack_b);
	else
		chunk_sort(stack_a, stack_b);
}
int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		size;

	// atexit(leaks);
	stack_a = (t_stack){0};
	stack_b = (t_stack){0};
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (!parse_and_validate_args(ac, av, &stack_a, &size))
		return (clean_exit(&stack_a, &stack_b, 1));
	if (!init_stack_b(&stack_b, size))
		return (clean_exit(&stack_a, &stack_b, 1));
	if (check_data(&stack_a))
	{
		clean_exit(&stack_a, &stack_b, 1);
		return (1);
	}
	if (check_if_sorted(&stack_a))
	{
		write(2, "Error\n", 6);
		return (clean_exit(&stack_a, &stack_b, 0));
	}
	select_sorting(&stack_a, &stack_b);
	return (clean_exit(&stack_a, &stack_b, 0));
}
