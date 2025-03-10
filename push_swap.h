/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 03:23:14 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/10 17:49:46 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*arr;
	int	size;
}				t_stack;


void		free_split(char **out, int k);
char		**ft_split(char *str);


int			count_words(char *str);
int			ft_atoi(const char *str);
char		*ft_strncpy(char *dest, char *src, int len);
char		*ft_strndup(const char *src, int len);

int			*init_arr_str(char **av, int *size);
int			*init_arr_int(int ac, char **av, int *size);
int			is_valid_int(const char *str);
int			check_data(t_stack *arr);
int			check_if_sorted(t_stack *arr);
int			check_duplicates(t_stack *arr);

int			*copy_array(t_stack *arr);
void		fill_mapping(t_stack *arr, int *copy, int *mapped);
int			*map_to_ranks(t_stack *arr);
void		bubble_sort(t_stack *arr);

void		get_chunk_limits(int chunk_index, t_stack *stack,
				int *low, int *high);
int			decide_chunks(int size);

void		ft_swap(t_stack *stack);
void		sa(t_stack	*stack_a);
void		sb(t_stack	*stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);

void		push(t_stack *stack_src, t_stack *stack_dest);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);

void		rotate(t_stack *stack);
void		ra(t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);

void		reverse_rotate(t_stack *stack);
void		rra(t_stack *stack_a);
void		rrb(t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);

void		sort_three(t_stack *stack);
int			find_index_of_min(t_stack *stack);
void		sort_five(t_stack *stack_a, t_stack *stack_b);


void		chunk_sort(t_stack *stack_a, t_stack *stack_b);
void		partition_chunks(t_stack *stack_a, t_stack *stack_b);
void		reassemble_stack(t_stack *stack_a, t_stack *stack_b);
void		process_chunk(t_stack *stack_a, t_stack *stack_b,
				int low, int high);
int			find_best_spot(t_stack *stack_a, int value);
int			find_index_of_max(t_stack *stack);
int			find_index_in_chunk(t_stack *stack, int low, int high);
int			find_bottom_index_in_chunk(t_stack *stack, int low, int high);
int			find_top_index_in_chunk(t_stack *stack, int low, int high);

void		bring_to_top_both_struct(t_stack *stack_a, int index_a,
				t_stack *stack_b, int index_b);

void		bring_to_top_both_down(t_stack *stack_a, int moves_a,
				t_stack *stack_b, int moves_b);
void		bring_to_top_both_up(t_stack *stack_a, int moves_a,
				t_stack *stack_b, int moves_b);
void		simultaneous_rotate_down_common(t_stack *stack_a,
				t_stack *stack_b, int common);
void		simultaneous_rotate_up_common(t_stack *stack_a,
				t_stack *stack_b, int common);
void		finish_rotate_down(t_stack *stack, int diff, char stack_name);
void		finish_rotate_up(t_stack *stack, int diff, char stack_name);
void		bring_to_top_struct(t_stack *stack, int index, char stack_name);
void		rotate_down(t_stack *stack, int count, char stack_name);
void		rotate_up(t_stack *stack, int count, char stack_name);















void		print_stack(t_stack *stack, char name);


#endif