/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:43:58 by ckappe            #+#    #+#             */
/*   Updated: 2025/02/11 03:42:11 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// need to replace strncpy

/* char **ft_split(char *str, char delim)
{
    int     i;
	int		j;
	int		k;
    int		wc;
	char	**out;

	i = 0;
	j = 0;
	k = 0;
	wc = count_words(str);
	if (!(out = (char **)malloc(sizeof(char *) * (wc + 1)))) // or plus two to account for null terminator to mimic ac?
		return (NULL);
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'|| str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (j < i)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			strncpy(out[k++], &str[j], i - j);
		}
	}
	return (out);
} */


int     count_words (char *str)
{
    int     wc;

    wc = 0;
    while (*str)
    {
        while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
            str++;
        if (*str)
            wc++;
        while (*str && (*str != ' ' && *str != '\t' && *str != '\n'))
            str++;
    }
    return (wc);
}

char **ft_split(char *str)
{
    int     i;
	int		j;
	int		k;
	char	**out;

	i = 0;
	j = 0;
	k = count_words(str);
	if (!(out = (char **)malloc(sizeof(char *) * (k + 1))))
		return (NULL);
	k = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'|| str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (j < i)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));// or plus two to account for null terminator to mimic ac?
			strncpy(out[k], &str[j], i - j);
			out[k++][i - j] = '\0'; 
		}
	}
	out[k] = NULL;
	return (out);
}

