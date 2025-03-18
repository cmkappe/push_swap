/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_prep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 00:25:27 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/03/14 16:06:47 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	decide_chunks(int size)
{
	if (size < 10)
		return (2);
	else if (size >= 10 && size <= 100)
		return (5);
	else if (size <= 500)
		return (10);
	else
		return (20);
}

void	get_chunk_limits(int chunk_index, int total, int *low, int *high)
{
	int	chunk_size;
	int	amount_chunks;

	amount_chunks = decide_chunks(total);
	chunk_size = total / amount_chunks;
	*low = chunk_index * chunk_size;
	if (chunk_index == amount_chunks - 1)
		*high = total - 1;
	else
		*high = (chunk_index + 1) * chunk_size - 1;
}
