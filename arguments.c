/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:31:14 by mel-moun          #+#    #+#             */
/*   Updated: 2023/05/01 16:48:56 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	it_is_sorted(t_stack **a)
{
	if (!*a)
		return (0);
	while ((*a)->next != NULL)
	{
		if ((*a)->rank > (*a)->next->rank)
			return (1);
		a = &(*a)->next;
	}
	return (0);
}

int	is_valid(char *arg)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (arg[i])
	{
		if (arg[i] == '+' || arg[i] == '-')
			count++;
		i++;
	}
	if ((arg[0] == '-' || arg[0] == '+') && count == 1)
		return (0);
	if ((arg[0] == '-' || arg[0] == '+') && count > 1)
		return (1);
	else if ((arg[0] != '+' || arg[0] != '-') && count >= 1)
		return (1);
	return (0);
}

void	split_arguments(t_push *all, int i, t_stack **a)
{
	all->av = ft_split(all->arg, ' ');
	free(all->arg);
	i = 0;
	while (all->av[i])
	{
		all->temp = ft_lstnew(ft_atoi(all->av[i], all, a));
		if (length_string(all->av[i]) > 10 || is_valid(all->av[i]) \
		|| is_duplicated(a, all->temp))
		{
			write(2, "Error\n", 6);
			free_split(all);
			ft_lstadd_back(a, all->temp);
			deallocating(a);
			exit(1);
		}
		ft_lstadd_back(a, all->temp);
		i++;
	}
	free_split(all);
}

void	taking_arguments(char **av, t_stack **a)
{
	t_push	all;
	int		i;

	all.arg = ft_calloc(1, 1);
	i = 1;
	while (av[i])
	{
		if (space_empty(av[i]) || only_num(av[i]))
		{
			write(2, "Error\n", 6);
			free(all.arg);
			exit(1);
		}
		all.arg = ft_strjoin(all.arg, av[i]);
		all.arg = ft_strjoin(all.arg, " ");
		i++;
	}
	split_arguments(&all, i, a);
}

int	value_max(t_stack **a)
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
	return (max);
}
