/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:54:26 by lvvz              #+#    #+#             */
/*   Updated: 2025/04/14 12:36:47 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}
void map_error(char *str, t_game *game)
{
	ft_putstr_fd(str, 2);
	free_map(game);
	exit(1);
}
void free_map(t_game *game)
{
	int i;

	if (!game->map)
		return ;
	
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}
int	count_rows(int fd)
{
	int i;
	char *res;

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