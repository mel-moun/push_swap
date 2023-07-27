/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:32:07 by mel-moun          #+#    #+#             */
/*   Updated: 2023/04/25 13:23:21 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	coming_back_bonus(t_stack **a, t_stack **b)
{
	ranking(*b, ft_lstsize(*b));
	while (*b != NULL)
	{
		if (position_max(b) <= (ft_lstsize(*b) / 2))
		{
			while ((*b)->content != value_max(b))
			{
				ra_rb(b, 'm');
			}
			pa(a, b, 'm');
		}
		else
		{
			while (ft_lstlast(*b)->content != value_max(b))
			{
				rra_rrb(b, 'm');
			}
			rra_rrb(b, 'm');
			pa(a, b, 'm');
		}
	}
}

void	sort_one_hundred_bonus(t_stack **a, t_stack **b, int rmax)
{
	int	rmin;

	rmin = 1;
	ranking(*a, ft_lstsize(*a));
	while ((*a) != NULL)
	{
		if ((*a)->rank >= rmin && (*a)->rank < rmax)
		{
			pb(a, b, 'm');
			rmin++;
			rmax++;
		}
		else if ((*a)->rank < rmin)
		{
			pb(a, b, 'm');
			ra_rb(b, 'm');
			rmin++;
			rmax++;
		}
		else if ((*a)->rank >= rmax)
			ra_rb(a, 'm');
	}
	coming_back(a, b);
}
