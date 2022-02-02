# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 16:41:58 by mkuehl            #+#    #+#              #
#    Updated: 2022/01/26 15:19:26 by mkuehl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
HEADER = push_swap.h
LIBRARIES = $(LIBFT)
INCLUDES = -I$(HEADER) -I$(LIBFT_HEADER)
LIBFT_DIRECTORY = ./libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_HEADER = $(LIBFT_DIRECTORY)/libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = algorithm_utils.c algorithm_utils2.c algorithm.c checks.c combinations.c free.c init.c main.c\
	markup_utils.c markups.c push.c remarkup.c reverse.c rotate.c sort.c swap.c utils.c
SRCS_BONUS = checker.c push.c reverse.c rotate.c swap.c free.c init.c checks.c
OBJS := $(SRCS:.c=.o)
OBJS_BONUS := $(SRCS_BONUS:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

bonus: $(NAME_BONUS)

%.o: %.c $(HEADER)
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(OBJS) -o $(NAME)

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(OBJS_BONUS) -o $(NAME_BONUS)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_BONUS)

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)

re:
	@$(MAKE) fclean
	@$(MAKE) all