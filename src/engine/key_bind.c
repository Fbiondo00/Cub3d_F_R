/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:03:17 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/25 23:18:29 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int key_press(int keycode, t_game *game)
{
    if (keycode == S)
       game->player.move.y = 1;
    if (keycode == D)
        game->player.move.x = 1;
    if (keycode == W)
        game->player.move.y = -1;
    if (keycode == A)
        game->player.move.x = -1;
    if (keycode == LEFT)
        game->player.rotate = -1;
    if (keycode == RIGHT)
        game->player.rotate = 1;
   else if (keycode == ESC)
        clean_exit(game, throw_exception(SYSTEM_EXCEPTION, ERR_ELEMENT_NOT_FOUND, NULL));
    return (0);
}

int key_release(int keycode, t_game *game)
{
    if (keycode == S)
        game->player.move.y = 0;
    if (keycode == D)
        game->player.move.x = 0;
    if (keycode == W)
        game->player.move.y = 0;
    if (keycode == A)
        game->player.move.x = 0;
    if (keycode == LEFT)
        game->player.rotate = 0;
    if (keycode == RIGHT)
        game->player.rotate = 0;
    return (0);
}

int quit(t_game *game)
{
    (void)game;
    exit(0);
    //clean_exit(game, throw_exception(SYSTEM_EXCEPTION, ERR_MALLOC, NULL));
    return (0);
}

static void	rotate_camera(t_game *m, float cos2, float sin2)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = m->player.direction.x;
	old_plane_x = m->player.cam_plane.x;
	m->player.direction.x = m->player.direction.x * cos2 - m->player.direction.y * sin2;
	m->player.direction.y = old_dir_x * sin2 + m->player.direction.y * cos2;
	m->player.cam_plane.x = m->player.cam_plane.x * cos2- m->player.cam_plane.y * sin2;
	m->player.cam_plane.y = old_plane_x * sin2 + m->player.cam_plane.y * cos2;
}

int	mause_controll(int x, int y, t_game *m)
{
	(void)y;
	if (m->xmause != 42)
	{
		if (x - m->xmause < 0)
			rotate_camera(m, cos((WC2 * m->sp)), sin((WC2 * m->sp)));
		else
			rotate_camera(m, cos((-WC2 * m->sp)), sin((-WC2 * m->sp)));
	}
	m->xmause = x;
	return (0);
}

void key_bind(t_game *game)
{
    mlx_hook(game->mlx_win, 17, 0, quit, game);
    mlx_hook(game->mlx_win, 2, 1L << 0, key_press, game);
    mlx_hook(game->mlx_win, 6, 1L << 6, mause_controll, game);
    mlx_hook(game->mlx_win, 3, 1L << 1, key_release, game);
    // mouse rotation è bonus
}