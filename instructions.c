/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:46:57 by mel-moun          #+#    #+#             */
/*   Updated: 2023/04/25 14:52:16 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_stack **root, char c)
{
	t_stack	*curr1;
	t_stack	*curr2;
	t_stack	*curr3;

	if (ft_lstsize(*root) <= 1)
		return ;
	curr2 = (*root)->next;
	curr1 = (*root);
	curr3 = (*root)->next->next;
	curr2->next = curr1;
	curr1->next = curr3;
	(*root) = curr2;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, char c)
{
	sa_sb(a, 'm');
	sa_sb(b, 'm');
	if (c == 's')
		write(1, "ss\n", 3);
}

void	pa(t_stack **a, t_stack **b, char c)
{
	t_stack	*tmp;

	if (ft_lstsize(*b) == 1)
	{
		tmp = (*b);
		(*b)->next = *a;
		*a = tmp;
		*b = NULL;
		if (c == 'a')
			write(1, "pa\n", 3);
		return ;
	}
	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	if (c == 'a')
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, char c)
{
	t_stack	*tmp;

	if (ft_lstsize(*a) == 1)
	{
		tmp = (*a);
		(*a)->next = *b;
		*b = tmp;
		*a = NULL;
		if (c == 'b')
			write(1, "pb\n", 3);
		return ;
	}
	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (c == 'b')
		write(1, "pb\n", 3);
}

void	ra_rb(t_stack **a, char c)
{
	t_stack	*curr;

	if (ft_lstsize(*a) <= 1)
		return ;
	curr = *a;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = *a;
	*a = (*a)->next;
	curr->next->next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}
