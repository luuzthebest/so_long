# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 05:50:08 by hounajar          #+#    #+#              #
#    Updated: 2025/03/18 00:37:33 by lvvz             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Wextra -Werror

AR = ar rcs

RM = rm -rf

SRCS =	ft_atoi.c		ft_isprint.c	ft_strnstr.c 	ft_strncmp.c	ft_striteri.c	\
		ft_bzero.c 		ft_strdup.c		ft_strrchr.c 	ft_tolower.c	ft_split.c		\
		ft_calloc.c		ft_memchr.c		ft_strlcat.c 	ft_toupper.c	ft_putchar_fd.c	\
		ft_isalnum.c	ft_memcmp.c		ft_strlcpy.c 	ft_substr.c		ft_putstr_fd.c	\
		ft_isalpha.c	ft_memcpy.c		ft_strlen.c		ft_strjoin.c	ft_putendl_fd.c	\
		ft_isascii.c	ft_memmove.c	ft_strchr.c		ft_itoa.c		ft_putnbr_fd.c	\
		ft_isdigit.c	ft_memset.c		ft_strtrim.c 	ft_strmapi.c \
		ft_lstnew_bonus.c		ft_lstadd_front_bonus.c		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c		ft_lstadd_back_bonus.c		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c	\

OBJS = $(SRCS:.c=.o)


NAME = libft.a

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)


%.o: %.c
	@$(CC) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all