/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 03:23:14 by ckappe            #+#    #+#             */
/*   Updated: 2025/02/21 20:13:43 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

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



int		get_max(int *stack_a, int *size_a);
int		get_bit_count(int max);
void	process_bit_pass(int bit_index, int *stack_a, 
			int *size_a, int *stack_b, int *size_b);
void	radix_sort_stack(int *stack_a, int *size_a, int *stack_b, int *size_b);


void 	chunk_sort(int *stack_a, int *size_a, int *stack_b, int *size_b);
void	 process_chunk(int *stack_a, int *size_a, int *stack_b, int *size_b,
					int low, int high);
int		find_best_spot(int *stack_a, int size_a, int value);
void 	bring_to_top_both(int *stack_a, int *size_a, int index_a,
						int *stack_b, int *size_b, int index_b);
void 	bring_to_top_both_down(int *stack_a, int *size_a, int moves_a,
                            int *stack_b, int *size_b, int moves_b);
void	bring_to_top_both_up(int *stack_a, int *size_a, int moves_a,
							int *stack_b, int *size_b, int moves_b);
void	finish_rotate_down(int *stack, int size, int diff, char stack_name);
void 	finish_rotate_up(int *stack, int size, int diff, char stack_name);
void 	simultaneous_rotate_down_common(int *stack_a, int size_a, int *stack_b, int size_b, int common);
void 	simultaneous_rotate_up_common(int *stack_a, int size_a, 
									int *stack_b, int size_b, int common);
void	 bring_to_top(int *stack, int *size, int index, char stack_name);
void 	rotate_down(int *stack, int size, int count, char stack_name);
void	 rotate_up(int *stack, int size, int count, char stack_name);
int		find_index_of_max(int *stack, int size);
int		find_index_in_chunk(int *stack, int size, int low, int high);
int		find_bottom_index_in_chunk(int *stack, int size, int low, int high);
int		find_top_index_in_chunk(int *stack, int size, int low, int high);
void 	get_chunk_limits(int chunk_index, int size, int *low, int *high);
int 	decide_chunks(int size);


int	check_sorted_or_error(int *arr, int size);

int	*copy_array(int *arr, int size);
void	bubble_sort(int *arr, int size);
void	fill_mapping(int *arr, int *copy, int *mapped, int size);
int	*map_to_ranks(int *arr, int size);








#endif