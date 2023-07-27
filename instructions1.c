/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:18:11 by mel-moun          #+#    #+#             */
/*   Updated: 2023/04/25 13:02:04 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **a, t_stack **b, char c)
{
	ra_rb(a, 'm');
	ra_rb(b, 'm');
	if (c == 'r')
		write(1, "rr\n", 3);
}

void	rra_rrb(t_stack **a, char c)
{
	t_stack	*last;
	t_stack	*before;

	last = *a;
	before = *a;
	if (ft_lstsize(*a) <= 1)
		return ;
	while (last->next != NULL)
	{
		if (last->next->next == NULL)
			before = last;
		last = last->next;
	}
	last->next = *a;
	*a = last;
	before->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, char c)
{
	rra_rrb(a, 'm');
	rra_rrb(b, 'm');
	if (c == 'r')
		write(1, "rrr\n", 4);
}
