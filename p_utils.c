/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:25:20 by lvvz              #+#    #+#             */
/*   Updated: 2025/04/18 16:33:29 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	objs_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = ft_strlen(game->map[i]) - 1;
		if (game->map[i][j] == '\n')
			j--;
		while (j >= 0)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'P'
				&& game->map[i][j] != 'E')
				map_error("Invalid Char in the Map", game);
			j--;
		}
		i++;
	}
}

void	surr_walls_check(t_game *game, int height)
{
	int	j;
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (i == 0 || i == height - 1)
		{
			j = ft_strlen(game->map[i]) - 1;
			if (game->map[i][j] == '\n')
				j--;
			while (j >= 0)
			{
				if (game->map[i][j] != '1')
					map_error("Map is Not Surrounded by Walls", game);
				j--;
			}
		}
		j = ft_strlen(game->map[i]) - 1;
		if (game->map[i][j] == '\n')
			j--;
		if (game->map[i][0] != '1' || game->map[i][j] != '1')
			map_error("Map is Not Surrounded by Walls", game);
		i++;
	}
}

void	process_map(t_game *game, char obj, int x, int y)
{
	if (obj == 'C')
		game->objects.c += 1;
	else if (obj == 'E')
	{
		game->objects.e += 1;
		game->exit_x = x;
		game->exit_y = y;
	}
	else if (obj == 'P')
	{
		game->objects.p += 1;
		game->player_x = x;
		game->player_y = y;
	}
}

void	objs_recheck(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (game->map[i])
	{
		j = ft_strlen(game->map[i]) - 1;
		if (game->map[i][j] == '\n')
			j--;
		while (j >= 0)
		{
			process_map(game, game->map[i][j], j, i);
			j--;
		}
		i++;
	}
	if (game->objects.c < 1 || game->objects.p != 1 || game->objects.e != 1)
		map_error("Invalid Objects in the Map", game);
}
