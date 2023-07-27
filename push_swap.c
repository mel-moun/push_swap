/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:04:39 by mel-moun          #+#    #+#             */
/*   Updated: 2023/05/01 16:15:10 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 2)
		sort_two(a);
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else if (ft_lstsize(*a) == 4)
		sort_four(a, b);
	else if (ft_lstsize(*a) == 5)
		sort_five(a, b);
	else if (ft_lstsize(*a) <= 100)
		sort_one_hundred(a, b, 15);
	else
		sort_one_hundred(a, b, 35);
	deallocating(a);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	taking_arguments(av, &a);
	ranking(a, ft_lstsize(a));
	if (!it_is_sorted(&a))
	{
		deallocating(&a);
		return (0);
	}
	sorting(&a, &b);
}
