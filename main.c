/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:44:23 by lvvz              #+#    #+#             */
/*   Updated: 2025/04/16 15:44:05 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_game game;
	t_objects objects;

	game.map = NULL;
	game.map_copy = NULL;

	// game = malloc(sizeof(t_game));
	// if (!game)
	// 	return (1);
	objects = (t_objects){0, 0, 0};
	parse(ac, av, &game, &objects);
	// printf("%s\n%s", game.map[1], game.map_copy[1]);
	free_map(&game);
}