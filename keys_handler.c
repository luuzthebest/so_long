/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 01:54:05 by lvvz              #+#    #+#             */
/*   Updated: 2025/04/18 11:24:28 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int    exit_game(t_game *game)
{
    game_error("", game);
    return (0);
}
void    move_player(t_game *game, int direction)
{
    char target;
    int new_y;
    int new_x;

    new_x = game->player_x;
    new_y = game->player_y;
    if (direction == UP || direction == KEY_W)
        new_y--;
    else if (direction == DOWN || direction == KEY_S)
        new_y++;
    else if (direction == KEY_A || direction == LEFT)
        new_x--;
    else if (direction == KEY_S || direction == RIGHT)
        new_x++;
    target = game->map[new_y][new_x];
    if (target == '1')
        return;
    if (target == 'C')
    {
        game->map[new_y][new_x] = 'P';
        game->objects.c--;
    }
    else if (target == 'E')
    {
        if (game->objects.c == 0)
        {
            ft_putstr_fd("You won !", 1);
            exit_game(game);
        }
        game->map[new_y][new_x] = 'B';
    } else
        game->map[new_y][new_x] = 'P';

    if (game->map[game->player_y][game->player_x] == 'B')
        game->map[game->player_y][game->player_x] = 'E';
    else
        game->map[game->player_y][game->player_x] = '0';
    game->player_x = new_x;
    game->player_y = new_y;
    render_map(game);       
}

int handle_keypress(int keycode, t_game *game)
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