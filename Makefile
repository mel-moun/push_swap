# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 11:43:55 by mel-moun          #+#    #+#              #
#    Updated: 2023/04/25 15:26:29 by mel-moun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME1 = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra
CFILES =add.c\
		arguments.c\
		ft_split.c\
		instructions.c\
		instructions1.c\
		libft_utils.c\
		linked.c\
		push_swap.c\
		range100.c\
		ranging.c\
		
CFILESB = ./bonus/get_next_line_bonus.c\
		./bonus/get_next_line_utils_bonus.c\
		./bonus/instr_bonus.c\
		./bonus/push_swap_bonus.c\
		./bonus/range100_bonus.c\
		./bonus/sorting_bonus.c\
		add.c\
		arguments.c\
		ft_split.c\
		libft_utils.c\
		linked.c\
		range100.c\
		ranging.c\
		instructions.c\
		instructions1.c\
		
OBJECTS=$(CFILES:.c=.o)
OBJECTSB=$(CFILESB:.c=.o)

all : $(NAME)
bonus : $(NAME1)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(NAME1): $(OBJECTSB)
	$(CC) $(CFLAGS) $(OBJECTSB) -o $(NAME1)
	
clean:
	rm -f $(OBJECTS) $(OBJECTSB)

fclean: clean
	rm -f $(NAME) $(NAME1)

re: fclean all

.PHONY: all clean fclean re bonus