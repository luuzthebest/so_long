/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:45:32 by lvvz              #+#    #+#             */
/*   Updated: 2025/04/16 09:42:04 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"
typedef struct s_objects
{
	int	c;
	int	e;
	int	p;
} t_objects;

typedef struct s_game
{
	char	**map;
	char	**map_copy;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
} t_game;
// gnl
# define BUFFER_SIZE 1
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);
char	*gnl_strdup(const char *s);
size_t	gnl_strlen(const char *str);
int		gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

void parse(int ac, char *av[], t_game *game, t_objects *obj);
void ft_error(char *str);
void map_error(char *str, t_game *game);
void free_map(t_game *game);
int	count_rows(char **av);
int	count_cols(char *av);