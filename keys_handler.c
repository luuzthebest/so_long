/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 01:54:05 by lvvz              #+#    #+#             */
/*   Updated: 2025/04/18 15:52:02 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	game_error("", game);
	return (0);
}

void	cal_new_pos(t_game *game, int direction, int *new_x, int *new_y)
{
	*new_x = game->player_x;
	*new_y = game->player_y;
	if (direction == UP || direction == KEY_W)
		(*new_y)--;
	else if (direction == DOWN || direction == KEY_S)
		(*new_y)++;
	else if (direction == LEFT || direction == KEY_A)
		(*new_x)--;
	else if (direction == RIGHT || direction == KEY_D)
		(*new_x)++;
}

int	handle_target(t_game *game, char target, int new_x, int new_y)
{
	if (target == '1')
		return (0);
	if (target == 'C')
		game->objects.c--;
	else if (target == 'E')
	{
		if (game->objects.c == 0)
		{
			game->moves++;
			ft_putstr_fd("Moves: ", 1);
			ft_putnbr_fd(game->moves, 1);
			ft_putstr_fd("\n", 1);
			ft_putstr_fd("You won!\n", 1);
			exit_game(game);
		}
		game->map[new_y][new_x] = 'B';
		return (1);
	}
	game->map[new_y][new_x] = 'P';
	return (1);
}

void	move_player(t_game *game, int direction)
{
	char	target;
	int		new_y;
	int		new_x;

	cal_new_pos(game, direction, &new_x, &new_y);
	target = game->map[new_y][new_x];
	if (!handle_target(game, target, new_x, new_y))
		return ;
	if (game->map[game->player_y][game->player_x] == 'B')
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	render_map(game);
	game->moves++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n", 1);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == KEY_W || keycode == UP)
		move_player(game, UP);
	else if (keycode == KEY_S || keycode == DOWN)
		move_player(game, DOWN);
	else if (keycode == KEY_A || keycode == LEFT)
		move_player(game, LEFT);
	else if (keycode == KEY_D || keycode == RIGHT)
		move_player(game, RIGHT);
	return (0);
}
