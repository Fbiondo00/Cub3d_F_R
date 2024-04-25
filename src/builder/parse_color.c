/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 02:11:15 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/18 20:23:24 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int	is_valid_rgb(t_game *game, int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_MAP_COLOR, NULL));
		i++;
	}
	return (1);
}

int is_number(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int *char_matrix_to_int(t_game *game, char **mat)
{
    int i;
    int *rgb;

    i = 0;
    rgb = ft_calloc(3, sizeof(int));
    if (!rgb)
		 clean_exit(game, throw_exception(SYSTEM_EXCEPTION, ERR_MALLOC, NULL));
    while (mat[i])
    {
        if (is_number(mat[i]) == 0)
            clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_MAP_COLOR, NULL));
        rgb[i] = ft_atoi(mat[i]);
        i++;
    }
    free_matrix((void **)mat);
    return (rgb);
}

// fa lo split del path
// controlla che siano 3 elementi
// poi li inserisce in array trasformando elementi in int con atoi
int *get_rgb(t_game *game, int color)
{
    int     i;
    char    **mat;

    i = 0;
    mat = ft_split(game->type[color].path, ',');
    while (mat[i])
        i++;
    if (i != 3)
    {
        free_matrix((void **)mat);
        clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_MAP_COLOR, NULL));
    }

    return (char_matrix_to_int(game, mat));
}

void convert_rgb_to_hex(t_game *game, int color, int *rgb)
{
	int				r;
	int				g;
	int				b;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	game->type[color].hex = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void convert_in_hexadecimal(t_game *game, int color)
{
    int *rgb;
    // fa lo split del path, controlla che siano 3 int(atoi) e li setta in array
    rgb = get_rgb(game, color);
    // controlla che siano rgb validi ovvero da 0 a 255
    if (is_valid_rgb(game, rgb))
        convert_rgb_to_hex(game, color, rgb); // converte rgb in hexadecimal
    else
        clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_MAP_COLOR, NULL));
    free(rgb);
}

//parse_colors
//  check rgb
//  convert rgb
//  check color validity
void parse_color(t_game *game)
{
    enum e_color color;
    
	printf("entra in parse_color\n");
    color = FLOOR;
    while (color <= CEALING) {
        if (game->type[color].path == NULL)
            clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_MAP_COLOR, NULL));
        printf("game->type[color].path:%s| len:%d\n", game->type[color].path, (int)ft_strlen(game->type[color].path));
        convert_in_hexadecimal(game, (int)color);
        color++;
    }
	printf("esce in parse_color\n");
}


