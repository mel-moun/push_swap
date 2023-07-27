/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:04:39 by mel-moun          #+#    #+#             */
/*   Updated: 2023/05/01 16:40:35 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	final(t_stack *a, t_stack *b, int status)
{
	if (!it_is_sorted(&a) && !b && status != 1)
	{
		write(1, "OK\n", 3);
		deallocating(&a);
		exit(0);
	}
	else if ((it_is_sorted(&a) || b) && status != 1)
	{
		write(1, "KO\n", 3);
		deallocating(&a);
		deallocating(&b);
		exit(0);
	}
	write(1, "Error\n", 6);
	deallocating(&a);
	deallocating(&b);
	exit(1);
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	int			status;
	char		*line;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	taking_arguments(av, &a);
	ranking(a, ft_lstsize(a));
	line = get_next_line(0);
	while (line)
	{
		status = instructions(&a, &b, line);
		if (status == 1)
			break ;
		free(line);
		line = get_next_line(0);
	}
	final(a, b, status);
}
