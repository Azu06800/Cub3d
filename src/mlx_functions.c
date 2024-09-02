/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:19:42 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/01 20:59:22 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_start(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, SCREENWIDTH, SCREENHEIGHT, "Cub3d");
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	make_floor(t_map *map)
{
	int	x;
	int	y;

	x = map->x;
	y = map->drawend;
	while (y < SCREENHEIGHT - 1)
	{
		my_mlx_pixel_put(map->imgs, x, y, create_trgb(0, \
		map->ffinal[0], map->ffinal[1], map->ffinal[2]));
		y++;
	}
}

void	wall(t_map *map)
{
	int		y;
	double	y_texture;
	double	step;
	t_img	*texture;

	texture = get_wall(map);
	y_texture = 0;
	step = (double)((double)texture->height \
	/ (double)(map->drawend - map->drawstart));
	if (map->drawstart < 0)
	{
		y_texture = step * map->drawstart * -1;
		map->drawstart = 0;
	}
	y = map->drawstart;
	while (y < map->drawend)
	{
		if (y >= SCREENHEIGHT)
			break ;
		my_mlx_pixel_put(map->imgs, map->x, y, \
		choose_color(texture, map->wall_x * (double)texture->width, y_texture));
		y++;
		y_texture += step;
	}
}

void	make_sky(t_map *map)
{
	int	x;
	int	y;

	x = map->x;
	y = 0;
	while (y < map->drawstart)
	{
		my_mlx_pixel_put(map->imgs, x, y, create_trgb(0, \
		map->cfinal[0], map->cfinal[1], map->cfinal[2]));
		y++;
	}
}
