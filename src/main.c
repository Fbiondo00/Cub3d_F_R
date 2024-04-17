/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:50:28 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/17 01:43:49 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

//TODO:
// 1) MAKEFILE COMPILE V
// 2) FINISH FUNCTION
// 3) IMPORT MAPS && TESTS
// 4) CHECK RENDER FLOW V

void	ft_print_mat(char **mat)
{
	int	y;
	int	x;

	y = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			write(1, &mat[y][x], 1);
			x++;
		}
		y++;
		write(1, "\n", 1);
	}
}

void build_game(t_game *game)
{
    if (game->argc != 2)
        clean_exit(game, throw_exception(ERR_ARGC, NULL, NULL));
    // 0)INIT STRUCTURES TO DEFAULT VALUES
    init_game(game); // -> ??
    //      0.A) MLX CONFIGURATION  ->done
    //      0.B)init mlx && win
    set_mlx(game);

    // 1)CHECK ARGC && .CUB EXTENSION
    check_input(game, CUB, game->argv[1]);

    // 2.A)initial_parse file cub
    //      2.A.1)read line numbers
    //      2.A.2) alloc **matr && read file      ->done
    // 2.B)transfer information from file to structures ->done
    //      2.B.1)transfer cardinals
    //      2.B.2)transfer color
    //      2.B.3)transfer map
    transfer_info_file(game);
    // ft_print_mat(game->map);
    
    
    
    // 3)PARSE INFORMATION FILE FROM STRUCTURES ->wip
    //      3.1)parse cardinals
    //      3.2)parse_colors()
    //          set colors
    //          check color validity
    //      3.3)parse map
    //          3.3.A)set 1 if is_space
    //          3.3.B)check map validity
    //          3.3.C)check map is last
    //          3.3.D)check map_elements()
    //          3.3.E)check walls
    //          3.3.F)check elements
    //          3.3.G)check player
    //          3.3.H)init player
    //      3.4)parse texture
    //          3.4.A)check file
    //          3.4.B)check rgb
    //          3.4.C)convert rgb
    //          3.4.D)check texture validity
    parse_game(game);
    ft_print_mat(game->map);
  
    //      4.2)mlx hooks config
    key_bind(game);
}

void start_game(t_game *game)
{
    display_menu();
    render_screen(game);
}

void run_game(t_game *game)
{
    mlx_loop_hook(game->mlx, render, game);
    mlx_loop(game->mlx);
}

int main(int argc, char **argv)
{
    t_game game;
    
    game.argc = argc;
    game.argv = argv;
    build_game(&game);
    start_game(&game);
    run_game(&game);
}
