/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:10:45 by mel-moun          #+#    #+#             */
/*   Updated: 2023/04/25 13:23:48 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two_bonus(t_stack **a)
{
	if ((*a)->content > (*a)->next->content)
		sa_sb(a, 'm');
}

void	sort_three_bonus(t_stack **a)
{
	ranking(*a, ft_lstsize(*a));
	if ((*a)->rank == 3)
	{
		ra_rb(a, 'm');
		sort_two(a);
	}
	else if ((*a)->rank != 3 && (*a)->next->rank != 3)
		sort_two(a);
	else
	{
		rra_rrb(a, 'm');
		sort_two(a);
	}
}

void	sort_four_bonus(t_stack **a, t_stack **b)
{
	t_stack	*curr;
	int		n;

	n = 0;
	curr = *a;
	while (curr != NULL)
	{
		if (curr->rank == 1)
			break ;
		curr = curr->next;
		n++;
	}
	if (n >= ft_lstsize(*a) / 2)
	{
		if (ft_lstlast(*a)->rank != 1)
			rra_rrb(a, 'm');
		rra_rrb(a, 'm');
	}
	else if ((*a)->rank != 1)
		ra_rb(a, 'm');
	pb(a, b, 'm');
	sort_three(a);
	pa(a, b, 'm');
	ranking(*a, ft_lstsize(*a));
}

void	sort_five_bonus(t_stack **a, t_stack **b)
{
	if (position_one(a) < ft_lstsize(*a) / 2)
	{
		if ((*a)->rank != 1)
			ra_rb(a, 'm');
	}
	else
	{
		while (ft_lstlast(*a)->rank != 1)
			rra_rrb(a, 'm');
		rra_rrb(a, 'm');
	}
	pb(a, b, 'm');
	ranking(*a, ft_lstsize(*a));
	sort_four(a, b);
	pa(a, b, 'm');
	ranking(*a, ft_lstsize(*a));
}
