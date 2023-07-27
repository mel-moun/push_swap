/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:53:16 by mel-moun          #+#    #+#             */
/*   Updated: 2023/04/25 13:43:42 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize(t_stack *lst)
{
	int		num;

	num = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		num++;
	}
	return (num);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while ((*lst)->next != NULL)
		lst = &(*lst)->next;
	(*lst)->next = new;
}

void	ranking(t_stack *root, int size)
{
	t_stack	*curr;
	t_stack	*comp;

	curr = root;
	while (curr != NULL)
	{
		curr->rank = size;
		curr = curr->next;
	}
	curr = root;
	comp = root;
	while (curr != NULL)
	{
		while (comp)
		{
			if (curr->content < comp->content)
				curr->rank--;
			comp = comp->next;
		}
		comp = root;
		curr = curr->next;
	}
}
