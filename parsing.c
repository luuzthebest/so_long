/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:50:13 by lvvz              #+#    #+#             */
/*   Updated: 2025/04/13 12:47:07 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ext_check(char *av)
{
	char *ext;
	int len;
	int i;

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
	int i;
	int	first_len;
	int current_len;

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
void chars_check(char **map)
{
	int i, j;

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
	int last, i, j;

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
			ft_error("Map is Not Surrounded by Walls!!");		
		i++;
	}
	
}
void map_check(char **map, int height)
{
	is_rectangular(map);
	chars_check(map);
	surr_walls_check(map, height);
}
void parse(int ac, char *av[], t_game game)
{
	int i, fd;

	i = 0;
	if (ac != 2)
	ft_error("Invalid ARGS");
	ext_check(av[1]);
	fd = open(av[1], O_RDONLY);
	while ((game.map[i] = get_next_line(fd)))
		i++;
	map_check(game.map, i);
}