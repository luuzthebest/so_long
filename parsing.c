/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:50:13 by lvvz              #+#    #+#             */
/*   Updated: 2025/04/19 14:41:59 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rc_map(t_game *game, char **av, char ***target)//dynamic function
{
	int	i;
	int	fd;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error("Cannot open the Map file");
	*target = malloc(sizeof(char *) * (game->rows + 1));
	if (!*target)
		ft_error("Memory allocation failed");
	(*target)[i] = get_next_line(fd);
	while ((*target)[i])
	{
		i++;
		(*target)[i] = get_next_line(fd);
	}
	(*target)[i] = NULL;
	close(fd);
}

void	seed_fill(t_game *game, int x, int y)
{
	if (y < 0 || x < 0 || game->map_copy[y][x] == '1' || x >= game->cols
		|| y >= game->rows || game->map_copy[y][x] == 'V')
		return ;
	game->map_copy[y][x] = 'V';
	seed_fill(game, x + 1, y);
	seed_fill(game, x - 1, y);
	seed_fill(game, x, y + 1);
	seed_fill(game, x, y - 1);
}

void	last_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_copy[i])
	{
		j = 0;
		while (game->map_copy[i][j])
		{
			if (game->map_copy[i][j] == 'E' || game->map_copy[i][j] == 'C')
				map_error("Not All the Objs are reachable", game);
			j++;
		}
		i++;
	}
}

void	parse(int ac, char *av[], t_game *game)
{
	if (ac != 2)
		ft_error("Invalid ARGS");
	ext_check(av[1]);
	game->rows = count_rows(av);
	game->cols = count_cols(av[1]);
	if (game->rows <= 2 || game->cols <= 2)
		ft_error("Invalid map dimensions");
	rc_map(game, av, &game->map);
	is_rectangular(game);
	objs_check(game);
	surr_walls_check(game, game->rows);
	objs_recheck(game);
	rc_map(game, av, &game->map_copy);
	seed_fill(game, game->player_x, game->player_y);
	last_check(game);
}
