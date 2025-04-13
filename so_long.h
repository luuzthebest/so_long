/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:45:32 by lvvz              #+#    #+#             */
/*   Updated: 2025/04/12 19:06:32 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

typedef struct s_game
{
	char **map;
} t_game;
// gnl
# define BUFFER_SIZE 1
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);
char	*gnl_strdup(const char *s);
size_t	gnl_strlen(const char *str);
int		gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

void parse(int ac, char *av[], t_game game);
void ft_error(char *str);