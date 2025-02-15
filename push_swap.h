/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 03:23:14 by ckappe            #+#    #+#             */
/*   Updated: 2025/02/15 23:29:10 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>



char 	**ft_split(char *str);
int     count_words (char *str);
int		*init_arr_str(char **av);
int		*init_arr_int(int ac, char **av);
int		ft_atoi(const char *str);
int		check_data(int *arr, int size);












#endif