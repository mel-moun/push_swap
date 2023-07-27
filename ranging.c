/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:10:45 by mel-moun          #+#    #+#             */
/*   Updated: 2023/05/01 16:47:05 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->content > (*a)->next->content)
		sa_sb(a, 'a');
}

void	sort_three(t_stack **a)
{
	ranking(*a, ft_lstsize(*a));
	if ((*a)->rank == 3)
	{
		ra_rb(a, 'a');
		sort_two(a);
	}
	else if ((*a)->rank != 3 && (*a)->next->rank != 3)
		sort_two(a);
	else
	{
		rra_rrb(a, 'a');
		sort_two(a);
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	ranking(*a, ft_lstsize(*a));
	if (position_one(a) >= ft_lstsize(*a) / 2)
	{
		if (ft_lstlast(*a)->rank != 1)
			rra_rrb(a, 'a');
		rra_rrb(a, 'a');
	}
	else if ((*a)->rank != 1)
		ra_rb(a, 'a');
	pb(a, b, 'b');
	sort_three(a);
	pa(a, b, 'a');
	ranking(*a, ft_lstsize(*a));
}

int	position_one(t_stack **a)
{
	int		n;

	n = 0;
	while (*a != NULL)
	{
		if ((*a)->rank == 1)
			break ;
		a = &(*a)->next;
		n++;
	}
	return (n);
}

void	sort_five(t_stack **a, t_stack **b)
{
	if (position_one(a) < ft_lstsize(*a) / 2)
	{
		if ((*a)->rank != 1)
			ra_rb(a, 'a');
	}
	else
	{
		while (ft_lstlast(*a)->rank != 1)
			rra_rrb(a, 'a');
		rra_rrb(a, 'a');
	}
	pb(a, b, 'b');
	sort_four(a, b);
	pa(a, b, 'a');
	ranking(*a, ft_lstsize(*a));
}
