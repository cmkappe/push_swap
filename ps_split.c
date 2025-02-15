/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:43:58 by ckappe            #+#    #+#             */
/*   Updated: 2025/02/12 16:58:34 by chiarakappe      ###   ########.fr       */
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

void	free_split(char **out, int k)
{
	while (k >= 0)
		free(out[k--]);
	free(out);
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
			out[k] = ft_strndup(&str[j], i - j);// or plus two to account for null terminator to mimic ac?
			if (!out[k])
			{
				free_split(out, k - 1);
				return (NULL);
			}
			k++;
		}
	}
	out[k] = NULL;
	return (out);
}

