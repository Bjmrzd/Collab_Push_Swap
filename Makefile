# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/22 09:03:04 by brouzaud          #+#    #+#              #
#    Updated: 2026/02/06 03:37:44 by brouzaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Wextra -Werror -ggdb 
INC = -I./include 

SRCS =	utils/parsing_utils.c utils/printf.c utils/printf_utils.c utils/split.c utils/utils.c utils/utils2.c utils/free_utils.c

SRCS +=	tools/parsing.c  tools/bench.c tools/disorder.c tools/sort_tools.c tools/strategy_select.c 

SRCS += ops/push.c ops/rotate.c ops/reverse_rotate.c ops/swap.c

SRCS += algo/complex_algo.c algo/simple_algo.c algo/medium_algo.c

SRCS += main.c

OBJS = $(SRCS:.c=.o)

HEADERS = push_swap.h

NAME = push_swap

all: $(NAME)
	@echo Compiled !

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INC) $(OBJS) $(HEADERS) -o $(NAME)
	@echo "$(NAME) is ready !"

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo -- $(NAME) is clean --

fclean: clean
	@rm -f $(NAME)
	@echo -- Everything is clean --

re: fclean all

test: $(NAME)
	@./$(NAME)
	@echo -- END OF TESTING--
	@rm -f $(OBJS)
	@rm -f $(NAME)
	
gdb: $(NAME)
	@(printf "Enter args :"; read arg; gdb --args ./$(NAME) $$arg);
	
val: $(NAME)
	@(printf "Enter args :"; read arg; valgrind --leak-check=full ./$(NAME) $$arg);
	@rm -f $(OBJS)
	@rm -f $(NAME)
	
run: $(NAME)
	@(printf "Enter args :"; read arg; ./$(NAME) $$arg);
	
shuf: $(NAME)
	@(printf "Enter size :"; read arg; printf "Enter flags :"; read args; shuf -i 0-9999 -n $$arg > args.txt; ./$(NAME) $$args $$(cat args.txt))
	@rm -f args.txt
	
.PHONY: all clean fclean re test val gdb run shuf