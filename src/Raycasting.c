/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:32:38 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/02 00:37:52 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*get_wall(t_map *map)
{
	if (map->side && map->stepy < 0)
		return (map->we_tex);
	if (map->side && map->stepy > 0)
		return (map->ea_tex);
	if (!map->side && map->stepx < 0)
		return (map->no_tex);
	if (!map->side && map->stepx > 0)
		return (map->so_tex);
	return (map->no_tex);
}

void	start_draw(t_map *map)
{
	make_floor(map);
	wall(map);
	make_sky(map);
}

void	calculate_wall_distance(t_map *map)
{
	if (map->side == 0)
		map->perpwalldist = (map->sidedistx - map->deltadistx);
	else
		map->perpwalldist = (map->sidedisty - map->deltadisty);
	if (map->side)
		map->wall_x = map->posx + map->perpwalldist * map->raydirx;
	else
		map->wall_x = map->posy + map->perpwalldist * map->raydiry;
	map->wall_x -= floor(map->wall_x);
	map->lineheight = SCREENHEIGHT / map->perpwalldist;
	map->drawstart = (int)(-map->lineheight / 2) + (SCREENHEIGHT / 2);
	map->drawend = (int)map->lineheight / 2 + SCREENHEIGHT / 2;
}

void	raycasting(t_map *map)
{
	map->x = 0;
	while (map->x < SCREENWIDTH)
	{
		calculate_ray_position_direction(map);
		initialize_side_distances(map);
		perform_dda(map);
		calculate_wall_distance(map);
		start_draw(map);
		map->x++;
	}
	mlx_put_image_to_window(map->mlx, map->win, map->imgs->img, 0, 0);
}
