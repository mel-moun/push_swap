/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:57:28 by mel-moun          #+#    #+#             */
/*   Updated: 2023/05/01 16:55:25 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_atoi(t_push *all, t_stack **a)
{
	write(2, "Error\n", 6);
	deallocating(a);
	free_split(all);
	exit(1);
}

void	min_max(long num, int sign, t_push *all, t_stack **a)
{
	if (num * sign > 2147483647 || num * sign < -2147483648)
		error_atoi(all, a);
}

int	ft_atoi(char *s, t_push *all, t_stack **a)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = sign * (-1);
		if (s[++i] == 0)
			error_atoi(all, a);
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + s[i] - 48;
		i++;
	}
	if (s[i] != '\0')
		error_atoi(all, a);
	min_max(num, sign, all, a);
	return (sign * num);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*p;
	int		j;

	i = 0;
	j = 0;
	if (!s2 || !s1)
		return (NULL);
	p = (char *) malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen (s2)) + 1);
	if (p == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	free(s1);
	return (p);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
