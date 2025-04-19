/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:45:32 by lvvz              #+#    #+#             */
/*   Updated: 2025/04/19 15:05:21 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <mlx.h>

enum e_keys
{
	KEY_ESC = 65307,
	UP = 65362,
	DOWN = 65364,
	LEFT = 65361,
	RIGHT = 65363,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100
};

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
	int		screen_h;
	int		screen_w;
}	t_infos;

typedef struct s_imgs
{
	void	*player;
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit;
	void	*on_box;
}	t_imgs;

typedef struct s_game
{
	t_infos		infos;
	t_imgs		*t_imgs;
	t_objects	objects;
	char		**map;
	char		**map_copy;
	int			rows;
	int			cols;
	int			player_x;
	int			player_y;
	int			moves;
}	t_game;
// gnl
# define BUFFER_SIZE 1

size_t	gnl_strlcpy(char *dst, const char *src, size_t size);
char	*gnl_strdup(const char *s);
size_t	gnl_strlen(const char *str);
int		gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

void	parse(int ac, char *av[], t_game *game);
void	ft_error(char *str);
void	map_error(char *str, t_game *game);
void	free_map(t_game *game);
void	game_error(char *str, t_game *game);
int		count_rows(char **av);
int		count_cols(char *av);
void	ext_check(char *av);
void	is_rectangular(t_game *game);

void	objs_recheck(t_game *game);
void	surr_walls_check(t_game *game, int height);
void	objs_check(t_game *game);

void	render_map(t_game *game);
int		handle_keypress(int keycode, t_game *game);
int		exit_game(t_game *game);

#endif