/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:32:07 by mel-moun          #+#    #+#             */
/*   Updated: 2023/05/01 16:47:30 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_max(t_stack **a)
{
	int		max;
	int		max_p;	
	int		curr_p;

	max = (*a)->content;
	max_p = 1;
	curr_p = 1;
	while (*a != NULL)
	{
		if ((*a)->content > max)
		{
			max = (*a)->content;
			max_p = curr_p;
		}
		a = &(*a)->next;
		curr_p++;
	}
	return (max_p);
}

void	coming_back(t_stack **a, t_stack **b)
{
	ranking(*b, ft_lstsize(*b));
	while (*b != NULL)
	{
		if (position_max(b) <= (ft_lstsize(*b) / 2))
		{
			while ((*b)->content != value_max(b))
				ra_rb(b, 'b');
			pa(a, b, 'a');
		}
		else
		{
			while (ft_lstlast(*b)->content != value_max(b))
				rra_rrb(b, 'b');
			rra_rrb(b, 'b');
			pa(a, b, 'a');
		}
	}
}

void	sort_one_hundred(t_stack **a, t_stack **b, int rmax)
{
	int	rmin;

	rmin = 1;
	while ((*a) != NULL)
	{
		if ((*a)->rank >= rmin && (*a)->rank < rmax)
		{
			pb(a, b, 'b');
			rmin++;
			rmax++;
		}
		else if ((*a)->rank < rmin)
		{
			pb(a, b, 'b');
			ra_rb(b, 'b');
			rmin++;
			rmax++;
		}
		else if ((*a)->rank >= rmax)
			ra_rb(a, 'a');
	}
	coming_back(a, b);
}

int	length_string(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (s[0] == '+' || s[0] == '-')
		i++;
	while (s[i] && s[i] == '0')
		i++;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		len++;
		i++;
	}
	return (len);
}

char	*ft_strdup( char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *) malloc (ft_strlen(s1) + 1);
	if (p == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
