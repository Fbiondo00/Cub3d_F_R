/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 01:21:50 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/04/26 02:54:09 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"


void	rotate_camera(t_game *m, float cos2, float sin2)
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

int	mouse_control(int x, int y, t_game *m)
{
	(void)y;
	if (m->xmouse != 42)
	{
		if (x - m->xmouse < 0)
			rotate_camera(m, cos((.05 * m->sp)), sin((.05 * m->sp)));
		else
			rotate_camera(m, cos((-.05 * m->sp)), sin((-.05 * m->sp)));
	}
	m->xmouse = x;
	return (0);
}