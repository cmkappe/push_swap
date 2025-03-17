/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:44:00 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/03/16 18:44:34 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->arr[0];
	b = stack->arr[1];
	c = stack->arr[2];
	if (a < b && b < c)
		return ;
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
