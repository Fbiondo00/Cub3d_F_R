/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 01:21:50 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/04/26 03:27:36 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"


int	mouse_control(int x,int y, t_game *game)
{
	printf("x:%d", x);
	printf("y:%d", y);
	if (x < 0)
	{
		printf("gira a sinistra\n");
		game->player.rotate -= 0.1; 
	}
	else
	{
		printf("gira a destra\n");
		game->player.rotate += 0.1; 
	}
	return (0);
}