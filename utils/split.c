/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:43:58 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/06 10:37:31 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_split(char **out, int k)
{
	while (k >= 0)
		free(out[k--]);
	free(out);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**out;

	i = 0;
	j = 0;
	k = count_words(str);
	out = (char **)malloc(sizeof(char *) * (k + 1));
	if (!out)
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
			out[k] = strndup(&str[j], i - j);
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


/* char	**ft_split(char *str)
{
	int		i;
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
			out[k] = strndup(&str[j], i - j);
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
} */
