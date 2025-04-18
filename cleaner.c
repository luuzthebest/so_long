/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:15:22 by lvvz              #+#    #+#             */
/*   Updated: 2025/04/18 16:17:36 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	clean_imgs(t_game *game)
{
	if (game->t_imgs)
	{
		if (game->t_imgs->player)
			mlx_destroy_image(game->infos.mlx, game->t_imgs->player);
		if (game->t_imgs->wall)
			mlx_destroy_image(game->infos.mlx, game->t_imgs->wall);
		if (game->t_imgs->collectible)
			mlx_destroy_image(game->infos.mlx, game->t_imgs->collectible);
		if (game->t_imgs->exit)
			mlx_destroy_image(game->infos.mlx, game->t_imgs->exit);
		if (game->t_imgs->floor)
			mlx_destroy_image(game->infos.mlx, game->t_imgs->floor);
		if (game->t_imgs->on_box)
			mlx_destroy_image(game->infos.mlx, game->t_imgs->on_box);
		free(game->t_imgs);
		game->t_imgs = NULL;
	}
}

void	game_error(char *str, t_game *game)
{
	clean_imgs(game);
	mlx_destroy(game);
	map_error(str, game);
}
