/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:43:38 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/24 15:22:30 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	free_matrix(void **matrix)
{
	int	i;

	i = 0;
    if(matrix)
    {
	    while (matrix[i])
        {
            free(matrix[i]);
            i++;
        }	
	    free(matrix);
        matrix = NULL;
    }
    return ;

}

void free_color_and_walls(t_game *game)
{
    int i;

    i = 0;
    while (i < 2)
        free(game->type[i].path);
    i = 0;
    while (i < 4)
        free(game->walls[i].path);
}


// compone un messaggio di errore, a partire dalle stringe input e stampa su fd 2.
// msg non puoi essere NULL, specific e sub_specific sono opzionali.
int throw_exception(char *msg, char *specific, char *sub_specific)
{
    ft_printstr_fd("Error\n", 2);
    ft_printstr_fd(msg, 2);
    if (specific != NULL)
        ft_printstr_fd(specific, 2);
    if (sub_specific != NULL)
        ft_printstr_fd(sub_specific, 2);
    ft_printstr_fd("\n", 2);
    return (EXIT_FAILURE);
}

// exit status SUCCESS -> msg == NULL
// exit status ERROR -> msg != NULL
void clean_exit(t_game *game, int exit_status)
{
    (void)game;
    if (game->mlx && game->mlx_win)
    {
        mlx_destroy_window(game->mlx, game->mlx_win);
        free(game->mlx);
    }
    free_matrix((void **)game->map);
    free_matrix((void **)game->raw_file);
    free_matrix((void **)game->pixels);
    free_matrix((void **)game->textures);
    free_color_and_walls(game);
    exit(exit_status);
    // mlx + win + loop_end
    // free_data(matrix)
    // free_texture
    // free_pixels
    // free_texture_info
    // free_map

}