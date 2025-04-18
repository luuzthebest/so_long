/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:50:13 by lvvz              #+#    #+#             */
/*   Updated: 2025/04/18 09:57:09 by lvvz             ###   ########.fr       */
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
			if (game->map[i][j] == 'C')
				game->objects.c += 1;
			else if (game->map[i][j] == 'E')
			{
				game->objects.e += 1;
				game->exit_x = j;
				game->exit_y = i;
			}
			else if (game->map[i][j] == 'P')
			{
				game->objects.p += 1;
				game->player_x = j;
				game->player_y = i;
			}
			j--;
		}
		i++;
	}
	if (game->objects.c < 1 || game->objects.p != 1 || game->objects.e != 1)
		map_error("Invalid Objects in the Map", game);
}

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
	while (((*target)[i] = get_next_line(fd)))
		i++;
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
    printf("Map size: %d x %d\n", game->rows * 64, game->cols * 64);
	rc_map(game, av, &game->map);
	is_rectangular(game);
	objs_check(game);
	surr_walls_check(game, game->rows);
	objs_recheck(game);
	rc_map(game, av, &game->map_copy);
	seed_fill(game, game->player_x, game->player_y);
	last_check(game);
}
