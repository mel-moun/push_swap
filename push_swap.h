/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:57:47 by mel-moun          #+#    #+#             */
/*   Updated: 2023/05/01 16:47:41 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_a
{
	int			content;
	int			rank;
	struct s_a	*next;
}	t_stack;

typedef struct s_push
{
	char	*arg;
	char	**av;
	t_stack	*temp;
}	t_push;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int		value_max(t_stack **a);
int		ft_atoi(char *s, t_push *all, t_stack **a);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, int start, int len);
void	*ft_calloc(int count, int size);
char	*ft_strdup( char *s1);
void	ranking(t_stack *root, int size);
int		it_is_sorted(t_stack **a);
int		position_max(t_stack **a);
void	sort_one_hundred(t_stack **a, t_stack **b, int rmax);
void	coming_back(t_stack **a, t_stack **b);
void	taking_arguments(char **av, t_stack **a);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	sa_sb(t_stack **root, char c);
void	ss(t_stack **a, t_stack **b, char c);
void	ra_rb(t_stack **a, char c);
void	rr(t_stack **a, t_stack **b, char c);
void	rra_rrb(t_stack **a, char c);
void	rrr(t_stack **a, t_stack **b, char c);
void	pb(t_stack **a, t_stack **b, char c);
void	pa(t_stack **a, t_stack **b, char c);
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	free_split(t_push *all);
void	deallocating(t_stack **ptr);
void	split_arguments(t_push *all, int i, t_stack **a);
int		is_duplicated(t_stack **root, t_stack *node);
int		space_empty(char *s);
int		only_num(char *s);
void	error_atoi(t_push *all, t_stack **a);
int		position_one(t_stack **a);
int		length_string(char *s);

//bonus
char	*get_next_line(int fd);
size_t	ft_strlen_g(char *s, int j);
char	*ft_strjoin_g(char *s1, char *s2);
char	*beforenl(char *s);
char	*afternl(char *save);
int		checknl(char *p);
void	sort_two_bonus(t_stack **a);
void	sort_three_bonus(t_stack **a);
void	sort_four_bonus(t_stack **a, t_stack **b);
void	sort_five_bonus(t_stack **a, t_stack **b);
void	coming_back_bonus(t_stack **a, t_stack **b);
void	sort_one_hundred_bonus(t_stack **a, t_stack **b, int rmax);
int		instructions(t_stack **a, t_stack **b, char *line);
int		ft_strcmp(char *s1, char *s2);
#endif
