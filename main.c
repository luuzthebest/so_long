/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:44:23 by lvvz              #+#    #+#             */
/*   Updated: 2025/04/18 01:54:29 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void mlx_run(t_game *game)
{
	game->infos.mlx = mlx_init();
	mlx_get_screen_size(game->infos.mlx, &game->infos.screen_w, &game->infos.screen_h);
	
	if (game->rows * 50 > game->infos.screen_w || game->cols * 50 > game->infos.screen_h)
		game_error("Map size has exceed the screen size", game);
	
	game->infos.win = mlx_new_window(game->infos.mlx, game->cols * 50 , game->rows * 50, "so_long");
	if (!game->infos.win)
		game_error("Failed to create window", game);

	// mlx_loop(game->infos.mlx);

}

void	mlx_imgs(t_game *game)
{
	int	x;

	x = 50;
	game->t_imgs = malloc(sizeof(t_imgs));
	if (!game->t_imgs)
		game_error("Assets allocation failed.", game);
	game->t_imgs->wall = mlx_xpm_file_to_image(game->infos.mlx, "assets/wall.xpm", &x, &x);
	game->t_imgs->player = mlx_xpm_file_to_image(game	->infos.mlx, "assets/player.xpm", &x, &x);
	game->t_imgs->floor = mlx_xpm_file_to_image(game->infos.mlx, "assets/floor.xpm", &x, &x);
	game->t_imgs->exit = mlx_xpm_file_to_image(game->infos.mlx, "assets/exit.xpm", &x, &x);
	game->t_imgs->collectible = mlx_xpm_file_to_image(game->infos.mlx, "assets/sheep1.xpm", &x, &x);
	if (!game->t_imgs->player || !game->t_imgs->wall
		|| !game->t_imgs->collectible || !game->t_imgs->exit)
		game_error("Error :\nOne or more assets are missing!\n", game);
	// mlx_loop(game->infos.mlx);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == '1')
				mlx_put_image_to_window(game->infos.mlx, game->infos.win, game->t_imgs->wall, y * 50, x * 50);
			else if (game->map[x][y] == 'P')
				mlx_put_image_to_window(game->infos.mlx, game->infos.win, game->t_imgs->player, y * 50, x * 50);
			else if (game->map[x][y] == 'C')
				mlx_put_image_to_window(game->infos.mlx, game->infos.win, game->t_imgs->collectible, y * 50, x * 50);
			else if (game->map[x][y] == '0')
				mlx_put_image_to_window(game->infos.mlx, game->infos.win, game->t_imgs->floor, y * 50, x * 50);
			else if (game->map[x][y] == 'E')
				mlx_put_image_to_window(game->infos.mlx, game->infos.win, game->t_imgs->exit, y * 50, x * 50);
			y++;
		}
		x++;
	}
}


int	main(int ac, char *av[])
{
	t_game		game;
	t_objects	objects;

	game = (t_game){0};
	objects = (t_objects){0};
	
	parse(ac, av, &game, &objects);
	mlx_run(&game);
	mlx_imgs(&game);
	render_map(&game);
	mlx_key_hook(game.infos.win, &handle_keypress, &game);
	mlx_loop(game.infos.mlx);
	game_error("done", &game);
}
