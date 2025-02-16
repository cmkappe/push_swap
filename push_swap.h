/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 03:23:14 by ckappe            #+#    #+#             */
/*   Updated: 2025/02/16 03:01:32 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

char 	**ft_split(char *str);
void	free_split(char **out, int k);
int     count_words (char *str);
int		ft_atoi(const char *str);

int		is_valid_int(const char *str);
int		check_data(int *arr, int size);
int		*init_arr_str(char **av, int *size);
int		*init_arr_int(int ac, char **av, int *size);


void	ft_swap (int *stack, int size);
void	sa (int	*stack_a, int size_a);
void	sb (int	*stack_b, int size_b);
void	ss(int *stack_a, int size_a, int *stack_b, int size_b);

void	push (int *src, int *src_size, int *dest, int *dest_size);
void	pa (int *stack_a, int *size_a, int *stack_b, int *size_b);
void	pb (int *stack_a, int *size_a, int *stack_b, int *size_b);

void	rotate (int *stack, int size);
void	ra (int *stack_a, int size_a);
void	rb (int *stack_b, int size_b);
void	rr (int *stack_a, int size_a, int *stack_b, int size_b);

void	reverse_rotate(int *stack, int size);
void	rra (int *stack_a, int size_a);
void	rrb (int *stack_b, int size_b);
void	rrr (int *stack_a, int size_a, int *stack_b, int size_b);


#endif