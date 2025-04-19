/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:54:26 by lvvz              #+#    #+#             */
/*   Updated: 2025/04/19 14:41:31 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

int	count_rows(char **av)
{
	int		i;
	int		fd;
	char	*res;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error("Cannot open the Map file");
	i = 0;
	res = get_next_line(fd);
	while (res)
	{
		i++;
		free(res);
		res = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	count_cols(char *av)
{
	int		len;
	char	*res;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error("Cannot open the Map file");
	res = get_next_line(fd);
	if (!res)
	{
		free(res);
		ft_error("Invalid");
	}
	len = ft_strlen(res);
	if (res[len - 1] == '\n')
		len--;
	close(fd);
	free(res);
	return (len);
}

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
