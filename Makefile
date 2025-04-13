# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/15 12:44:47 by hounajar          #+#    #+#              #
#    Updated: 2025/04/12 17:16:02 by lvvz             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL = gnl/gnl.c gnl/gnl_utils.c

NAME = so_long

SRCS = main.c parsing.c utils.c $(GNL)

OBJS = $(SRCS:.c=.o)

MAKEFLAGS += --no-print-directory

all: $(LIBFT) $(NAME)


	
$(LIBFT):
	@echo LIBFT LOADING.. 
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT) so_long.h
	@echo SO_LONG LOADING..
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)


%.o: %.c
	@$(CC) -c $< -o $@
clean:
	@echo CLEANING..
	@$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo FULL CLEANING..
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re bonus