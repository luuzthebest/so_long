/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:50:13 by lvvz              #+#    #+#             */
/*   Updated: 2025/04/13 22:41:32 by lvvz             ###   ########.fr       */
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

void	is_rectangular(char **map)
{
	int	i;
	int	first_len;
	int	current_len;

	i = 0;
	first_len = ft_strlen(map[i]);
	if (map[i][first_len - 1] == '\n')
		first_len--;
	i++;
	while (map[i])
	{
		current_len = ft_strlen(map[i]);
		if (map[i][current_len - 1] == '\n')
			current_len--;
		if (current_len != first_len)
			ft_error("Map is Not Rectangular");
		i++;
	}
}

void	objs_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = ft_strlen(map[i]) - 1;
		if (map[i][j] == '\n')
			j--;
		while (j >= 0)
		{
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'C' && map[i][j] != 'P'
				&& map[i][j] != 'E')
				ft_error("Invalid Char in the Map");
			j--;
		}
		i++;
	}
}

void	surr_walls_check(char **map, int height)
{
	int	last;
	int	j;
	int	i;

	i = 0;
	while (map[i])
	{
		if (i == 0 || i == height - 1)
		{
			j = ft_strlen(map[i]) - 1;
			if (map[i][j] == '\n')
				j--;
			while (map[i][j])
			{
				if (map[i][j] != '1')
					ft_error("Map is Not Surrounded by Walls");
				j--;
			}
		}
		last = ft_strlen(map[i]) - 1;
		if (map[i][last] == '\n')
			last--;
		if (map[i][0] != '1' || map[i][last] != '1')
			ft_error("Map is Not Surrounded by Walls");
		i++;
	}
}

void	objs_recheck(char **map, t_objects *objs)
{
	int	i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = ft_strlen(map[i]) - 1;
		if (map[i][j] == '\n')
			j--;
		while (j >= 0)
		{
			if (map[i][j] == 'C')
				objs->c += 1;
			else if (map[i][j] == 'E')
				objs->e += 1;
			else if (map[i][j] == 'P')
				objs->p += 1;
			j--;
		}
		i++;
	}
	if (objs->c < 1 || objs->p != 1 || objs->e != 1)
		ft_error("Invalid Objects in the Map");
}

void	map_check(char **map, int height, t_objects *objs)
{
	is_rectangular(map);
	objs_check(map);
	surr_walls_check(map, height);
	objs_recheck(map, objs);
}

void	parse(int ac, char *av[], t_game *game, t_objects *objs)
{
	(void)objs;
	int	i;
	int	fd;

	i = 0;
	if (ac != 2)
		ft_error("Invalid ARGS");
	ext_check(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error("Cannot open the file");
	game->map = malloc(sizeof(t_game));
	if (!game->map)
		ft_error("Memory allocation failed");
	while (((*game).map[i] = get_next_line(fd)))
		i++;
	map_check((*game).map, i, objs);
}
