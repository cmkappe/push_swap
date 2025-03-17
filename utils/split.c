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

void	free_split(char **out)
{
	while (*out)
		free(*out);
	free(out);
}

static int	skip_whitespace(char *str, int i)
{
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	return (i);
}

static int	word_length(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
	{
		i++;
		len++;
	}
	return (len);
}

static char	**fill_split(char *str, char **out)
{
	int	i;
	int	index;
	int	word_len;

	i = 0;
	index = 0;
	while (str[i])
	{
		i = skip_whitespace(str, i);
		if (!str[i])
			break ;
		word_len = word_length(str, i);
		out[index] = ft_strndup(&str[i], word_len);
		if (!out[index])
			return (NULL);
		index++;
		i += word_len;
	}
	out[index] = NULL;
	return (out);
}

char	**ft_split(char *str)
{
	int		count;
	char	**out;

	count = count_words(str);
	out = (char **)malloc(sizeof(char *) * (count + 1));
	if (!out)
		return (NULL);
	if (!fill_split(str, out))
	{
		free_split(out);
		return (NULL);
	}
	return (out);
}
