/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:45:32 by lvvz              #+#    #+#             */
/*   Updated: 2025/04/17 15:26:19 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <mlx.h>

typedef struct s_objects
{
	int	c;
	int	e;
	int	p;
}	t_objects;

typedef struct s_infos
{
	void	*mlx;
	void	*win;
	int	screen_h;
	int	screen_w;
}	t_infos;

typedef struct s_game
{
	t_infos	infos;
	char	**map;
	char	**map_copy;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
}	t_game;
// gnl
# define BUFFER_SIZE 1

size_t	gnl_strlcpy(char *dst, const char *src, size_t size);
char	*gnl_strdup(const char *s);
size_t	gnl_strlen(const char *str);
int		gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

void	parse(int ac, char *av[], t_game *game, t_objects *obj);
void	ft_error(char *str);
void	map_error(char *str, t_game *game);
void	free_map(t_game *game);
void	game_error(char *str, t_game *game);
int		count_rows(char **av);
int		count_cols(char *av);

#endif