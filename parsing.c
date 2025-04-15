/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:50:13 by lvvz              #+#    #+#             */
/*   Updated: 2025/04/15 15:54:52 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ext_check(char *av)
{
	char	*ext;
	int		len;
	int		i;

	ext = "reb.";
	len = ft_strlen(av) - 1;
	i = 0;
	while (ext[i])
	{
		if (ext[i] == av[len])
		{
			i++;
			len--;
		}
		else
			ft_error("Invalid Extension");
	}
}

void	is_rectangular(t_game *game)
{
	int	i;
	int	first_len;
	int	current_len;

	i = 0;
	first_len = ft_strlen(game->map[i]);
	if (game->map[i][first_len - 1] == '\n')
		first_len--;
	i++;
	while (game->map[i])
	{
		current_len = ft_strlen(game->map[i]);
		if (game->map[i][current_len - 1] == '\n')
			current_len--;
		if (current_len != first_len)
			map_error("Map is Not Rectangular", game);
		i++;
	}
}

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
	int	last;
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
		last = ft_strlen(game->map[i]) - 1;
		if (game->map[i][last] == '\n')
			last--;
		if (game->map[i][0] != '1' || game->map[i][last] != '1')
			map_error("Map is Not Surrounded by Walls", game);
		i++;
	}
}

void	objs_recheck(t_game *game, t_objects *objs)
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
			if (game->map[i][j] == 'C')
				objs->c += 1;
			else if (game->map[i][j] == 'E')
			{
				objs->e += 1;
				game->exit_x = j;
				game->exit_y = i;
			}
			else if (game->map[i][j] == 'P')
			{
				objs->p += 1;
				game->player_x = j;
				game->player_y = i;
			}
			j--;
		}
		i++;
	}
	if (objs->c < 1 || objs->p != 1 || objs->e != 1)
		map_error("Invalid Objects in the Map", game);
}

// void	map_copy(t_game *game)
// {
// 	int i = 0;
// 	int j;

// 	game->map_copy = malloc(sizeof(char *) * (game->rows + 1));
// 	while (game->map[i])
// 	{
// 		j = 0;
// 		while (game->map[i][j])
// 		{
// 			game->map_copy[i][j] = game->map[i][j];
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void seed_fill(t_game *game, t_objects *objs)
// {
// 	(void)objs;
// 	map_copy(game);
// }

void	map_check(t_game *game, int height, t_objects *objs)
{
	is_rectangular(game);
	objs_check(game);
	surr_walls_check(game, height);
	objs_recheck(game, objs);
	// seed_fill(game, objs);
}

void	parse(int ac, char *av[], t_game *game, t_objects *objs)
{
	int	i;
	int	fd;

	i = 0;
	if (ac != 2)
		ft_error("Invalid ARGS");
	ext_check(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error("Cannot open the Map file");
	game->rows = count_rows(fd);
	game->map = malloc(sizeof(char *) * (game->rows + 1));
	if (!game->map)
		ft_error("Memory allocation failed");
	fd = open(av[1], O_RDONLY);
	while (((*game).map[i] = get_next_line(fd)))
		i++;
	close(fd);
	game->map_copy = malloc(sizeof(char *) * (game->rows + 1));
	fd = open(av[1], O_RDONLY);
	i = 0;
	while (((*game).map_copy[i] = get_next_line(fd))) // leaks here
		i++;
	// printf("%i, %i", i, game->rows);
	map_check(game, i, objs);
}
