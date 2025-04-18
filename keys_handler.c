/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 01:54:05 by lvvz              #+#    #+#             */
/*   Updated: 2025/04/18 01:58:59 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void    exit_game(t_game *game)
{
    game_error("", game);
}
int handle_keypress(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        exit_game(game);
    // else if (keycode == KEY_W)
    //     move_player(game, UP);
    // else if (keycode == KEY_S)
    //     move_player(game, DOWN);
    // else if (keycode == KEY_A)
    //     move_player(game, LEFT);
    // else if (keycode == KEY_D)
    //     move_player(game, RIGHT);
    return (0);
}