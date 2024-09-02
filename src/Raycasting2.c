/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:39:38 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/02 00:36:58 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_map(t_map *map)
{
	map->x = -1;
	while (++map->x < 65536)
		map->key_states[map->x] = 0;
	init_player(map);
	init_angleplayer(map, map->player_pos);
	map->x = 0;
	map->posx = 3.5;
	map->posy = 6.5;
	map->drawend = 0;
	map->drawstart = 0;
	map->wall_x = 0;
	map->camerax = 0;
	map->raydirx = 0;
	map->raydiry = 0;
	map->sidedistx = 0;
	map->sidedisty = 0;
	map->deltadistx = 0;
	map->deltadisty = 0;
	map->perpwalldist = 0;
	map->wall_x = 0;
	map->p_old_dir = 0;
	map->p_old_fov = 0;
	initialize_map2(map);
}

void	initialize_map2(t_map *map)
{
	map->mapx = 0;
	map->mapy = 0;
	map->stepx = 0;
	map->stepy = 0;
	map->hit = 0;
	map->side = 0;
	map->lineheight = 0;
}

void	calculate_ray_position_direction(t_map *map)
{
	map->camerax = 2 * map->x / (double)SCREENWIDTH - 1;
	map->mapx = (int)map->posx;
	map->mapy = (int)map->posy;
	map->raydirx = map->dirx + map->planex * map->camerax;
	map->raydiry = map->diry + map->planey * map->camerax;
	if (map->raydirx == 0)
		map->deltadistx = INFINITY;
	else
		map->deltadistx = fabs(1 / map->raydirx);
	if (map->raydiry == 0)
		map->deltadisty = INFINITY;
	else
		map->deltadisty = fabs(1 / map->raydiry);
	map->hit = 0;
}

void	initialize_side_distances(t_map *map)
{
	if (map->raydirx < 0)
	{
		map->stepx = -1;
		map->sidedistx = (map->posx - map->mapx) * map->deltadistx;
	}
	else
	{
		map->stepx = 1;
		map->sidedistx = (map->mapx + 1.0 - map->posx) * map->deltadistx;
	}
	if (map->raydiry < 0)
	{
		map->stepy = -1;
		map->sidedisty = (map->posy - map->mapy) * map->deltadisty;
	}
	else
	{
		map->stepy = 1;
		map->sidedisty = (map->mapy + 1.0 - map->posy) * map->deltadisty;
	}
}

void	perform_dda(t_map *map)
{
	while (map->hit == 0)
	{
		if (map->sidedistx < map->sidedisty)
		{
			map->sidedistx += map->deltadistx;
			map->mapx += map->stepx;
			map->side = 0;
		}
		else
		{
			map->sidedisty += map->deltadisty;
			map->mapy += map->stepy;
			map->side = 1;
		}
		if (map->tab_map[map->mapx][map->mapy] == '1')
			map->hit = 1;
	}
}
