/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 03:23:14 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/04 19:16:36 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

typedef	struct s_stack
{
	int	*arr;
	int	size;
}				t_stack;


char 	**ft_split(char *str);
void	free_split(char **out, int k);
int     count_words (char *str);
int		ft_atoi(const char *str);

int		is_valid_int(const char *str);
int		check_data(int *arr, int size);
int		*init_arr_str(char **av, int *size);
int		*init_arr_int(int ac, char **av, int *size);

int		check_sorted_or_error(t_stack *arr);

int		*copy_array(t_stack *arr);
void	fill_mapping(t_stack *arr, int *copy, int *mapped);
int		*map_to_ranks(t_stack *arr);

void	ft_swap(t_stack *stack);
void	sa(t_stack	*stack_a);
void	sb(t_stack	*stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

void	push(t_stack stack_src, t_stack stack_dest);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

void	rotate(t_stack *stack);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

void	reverse_rotate(t_stack *stack);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);



/* int		get_max(int *stack_a, int *size_a);
int		get_bit_count(int max);
void	process_bit_pass(int bit_index, int *stack_a, 
			int *size_a, int *stack_b, int *size_b);
void	radix_sort_stack(int *stack_a, int *size_a, int *stack_b, int *size_b); */

void	sort_three(t_stack *stack);

void 	chunk_sort(t_stack *stack_a, t_stack *stack_b);
void	process_chunk(t_stack *stack_a, t_stack *stack_b,
						int low, int high);
int		find_best_spot(t_stack *stack_a, int value);
void	bring_to_top_both_struct(t_stack *stack_a, int index_a, 
								t_stack *stack_b, int index_b);

void 	bring_to_top_both_down(t_stack *stack_a, int moves_a,
								t_stack *stack_b, int moves_b);
void	bring_to_top_both_up(t_stack *stack_a, int moves_a,
								t_stack *stack_b, int moves_b);
void 	simultaneous_rotate_down_common(t_stack *stack_a, t_stack *stack_b, int common);
void 	simultaneous_rotate_up_common(t_stack *stack_a, t_stack *stack_b, int common);
void	finish_rotate_down(t_stack *stack, int diff, char stack_name);
void 	finish_rotate_up(t_stack *stack, int diff, char stack_name);
void	bring_to_top(t_stack *stack, int index, char stack_name);
void 	rotate_down(t_stack *stack, int count, char stack_name);
void	rotate_up(t_stack *stack, int count, char stack_name);
int		find_index_of_max(t_stack *stack);
int		find_index_in_chunk(t_stack *stack, int low, int high);
int		find_bottom_index_in_chunk(t_stack *stack, int low, int high);
int		find_top_index_in_chunk(t_stack *stack, int low, int high);
void 	get_chunk_limits(int chunk_index, t_stack size, int *low, int *high);
int 	decide_chunks(t_stack size);



#endif