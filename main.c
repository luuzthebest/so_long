/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:44:23 by lvvz              #+#    #+#             */
/*   Updated: 2025/04/17 15:27:46 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void mlx_run(t_game *game)
{
	game->infos.mlx = mlx_init();
	mlx_get_screen_size(game->infos.mlx, &game->infos.screen_w, &game->infos.screen_h);
	
	if (game->rows * 64 > game->infos.screen_w || game->cols * 64 > game->infos.screen_h)
		game_error("Map size has exceed the screen size", game);
	
	game->infos.win = mlx_new_window(game->infos.mlx, game->rows * 64 , game->cols * 64, "so_long");
	// mlx_loop(game->infos.mlx);
}

int	main(int ac, char *av[])
{
	t_game		game;
	t_objects	objects;

	game = (t_game){0};
	objects = (t_objects){0};
	parse(ac, av, &game, &objects);

	mlx_run(&game);
	game_error("done", &game);
}
