/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:02:45 by mel-moun          #+#    #+#             */
/*   Updated: 2023/05/01 17:06:57 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deallocating(t_stack **ptr)
{
	t_stack	*pk;

	while (*ptr != NULL)
	{
		pk = *ptr;
		*ptr = (*ptr)->next;
		free(pk);
	}
	*ptr = NULL;
}

int	is_duplicated(t_stack **root, t_stack *node)
{
	t_stack	*curr;

	curr = *root;
	if (!*root)
		return (0);
	while (curr != NULL)
	{
		if (curr->content == node->content)
			return (1);
		curr = curr->next;
	}
	return (0);
}

void	free_split(t_push *all)
{
	int	i;

	i = 0;
	while (all->av[i])
	{
		free(all->av[i]);
		i++;
	}
	free(all->av);
}

int	space_empty(char *s)
{
	while (*s && *s == ' ')
		s++;
	if (!*s)
		return (1);
	return (0);
}

int	only_num(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') \
		&& (s[i] != '+' && s[i] != '-' && s[i] != 32))
			return (1);
		i++;
	}
	return (0);
}
