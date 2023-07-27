/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:10:22 by mel-moun          #+#    #+#             */
/*   Updated: 2023/04/25 12:34:56 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(int count, int size)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *) malloc (count * size);
	if (p == NULL)
		return (NULL);
	while (i < (count * size))
	{
		p[i] = 0;
		i++;
	}
	return (p);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*p;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len >= ft_strlen(s) - start)
		return (ft_strdup(s + start));
	p = (char *) malloc(len * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	while (i < len && start <= ft_strlen(s))
	{
		p[i] = s[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

static int	check(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	**writeplz(char *s, char **p, char c, int i)
{
	int	j;
	int	k;
	int	len;

	j = 0;
	k = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i - 1;
		while (s[++j] != c && s[j] != '\0')
			len++;
		if (s[i] == '\0')
		{
			p[k] = 0;
			break ;
		}
		p[k++] = ft_substr(s, i, len);
		len = 0;
		i = j;
	}
	return (p);
}

char	**ft_split(char *s, char c)
{
	char	**p;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	p = (char **) ft_calloc ((check(s, c) + 1), sizeof(char *));
	if (p == NULL)
		return (NULL);
	return (writeplz(s, p, c, i));
}
