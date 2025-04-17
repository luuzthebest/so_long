/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:54:26 by lvvz              #+#    #+#             */
/*   Updated: 2025/04/17 15:27:50 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	map_error(char *str, t_game *game)
{
	ft_putstr_fd(str, 2);
	free_map(game);
	exit(1);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
	i = 0;
	if (game->map_copy)
	{
		while (game->map_copy[i])
		{
			free(game->map_copy[i]);
			i++;
		}
		free(game->map_copy);
		game->map_copy = NULL;
	}
	return ;
}
void	mlx_destroy(t_game *game)
{
	if (game->infos.mlx && game->infos.win)
		mlx_destroy_window(game->infos.mlx, game->infos.win);
	if (game->infos.mlx)
	{
		mlx_destroy_display(game->infos.mlx);
		free(game->infos.mlx);
		game->infos.mlx = NULL;
	}
}

void	game_error(char *str, t_game *game)
{
	mlx_destroy(game);
	map_error(str, game);
}

int	count_rows(char **av)
{
	int		i;
	int		fd;
	char	*res;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error("Cannot open the Map file");
	i = 0;
	res = get_next_line(fd);
	while (res)
	{
		i++;
		free(res);
		res = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	count_cols(char *av)
{
	int		len;
	char	*res;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error("Cannot open the Map file");
	res = get_next_line(fd);
	len = ft_strlen(res);
	if (res[len - 1] == '\n')
		len--;
	close(fd);
	free(res);
	return (len);
}
