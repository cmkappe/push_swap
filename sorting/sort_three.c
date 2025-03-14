/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:44:00 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/03/14 16:07:21 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack *stack)
{
	int a = stack->arr[0];
	int b = stack->arr[1];
	int c = stack->arr[2];

	if (a < b && b < c)
		return;
	else if (a > b && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > c && b < c)
		ra(stack);
	else if (a < c && b > c)
	{
		rra(stack);
		sa(stack);
	}
	else if (a < b && a > c)
		rra(stack);
}
