# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 18:25:40 by dcheng            #+#    #+#              #
#    Updated: 2025/12/11 18:25:40 by dcheng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
TEST_NAME = push_swap_test
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
SRC = arg.c arr.c ops_a.c ops_b.c ops.c push_swap.c turksort_cost.c turksort_helpers.c turksort.c
OBJS = $(SRC:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFTDIR) -c $< -o $@

test: $(FILES)
	$(CC) test.c $(FILES) -o $(TEST_NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re test

