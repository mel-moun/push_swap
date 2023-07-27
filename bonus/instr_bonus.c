/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:04:40 by mel-moun          #+#    #+#             */
/*   Updated: 2023/04/25 13:05:07 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	instructions(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa_sb(a, 'm');
	else if (!ft_strcmp(line, "sb\n"))
		sa_sb(b, 'm');
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, 'm');
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b, 'm');
	else if (!ft_strcmp(line, "pb\n"))
		pb(a, b, 'm');
	else if (!ft_strcmp(line, "ra\n"))
		ra_rb(a, 'm');
	else if (!ft_strcmp(line, "rb\n"))
		ra_rb(b, 'm');
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, 'm');
	else if (!ft_strcmp(line, "rra\n"))
		rra_rrb(a, 'm');
	else if (!ft_strcmp(line, "rrb\n"))
		rra_rrb(b, 'm');
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, 'm');
	else
		return (1);
	return (0);
}
