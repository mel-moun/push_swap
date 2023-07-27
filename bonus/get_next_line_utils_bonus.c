/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:58:19 by mel-moun          #+#    #+#             */
/*   Updated: 2023/05/01 16:55:09 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen_g(char *s, int j)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n' && j)
			i++;
	while (s[i] && !j)
		i++;
	return (i);
}

char	*ft_strjoin_g(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;

	if (!s2[0] && !s1)
		return (NULL);
	if (!s1)
		s1 = ft_calloc(1, 1);
	i = 0;
	j = 0;
	p = (char *) ft_calloc (ft_strlen_g(s1, 0) + ft_strlen_g(s2, 0) + 1, 1);
	while (s1[j] != '\0')
		p[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		p[i++] = s2[j++];
	p[i] = '\0';
	free(s1);
	return (p);
}

char	*beforenl(char *s)
{
	char	*line;
	int		i;

	i = 0;
	line = (char *) ft_calloc (ft_strlen_g(s, 1) + 2, 1);
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (checknl(s) == 1)
		line[i++] = '\n';
	line[i] = '\0';
	if (!line[0])
	{
		free (line);
		return (NULL);
	}
	return (line);
}

char	*afternl(char *save)
{
	char	*after;
	int		i;
	int		j;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free (save);
		return (NULL);
	}
	i++;
	j = 0;
	after = (char *) ft_calloc(ft_strlen_g(&save[i], 0) + 1, 1);
	while (save[i])
		after[j++] = save[i++];
	after[j] = '\0';
	free(save);
	return (after);
}

int	checknl(char *p)
{
	int	i;

	i = 0;
	if (!p)
		return (0);
	while (p[i])
	{
		if (p[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
