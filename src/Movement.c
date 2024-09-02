/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:36:19 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/02 17:27:56 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	forward_backward(t_map *map)
{
	if (map->key_states[KEY_Z])
	{
		if (map->tab_map[(int)floor(map->posx + map->dirx * MOVEMENT)] \
		[(int)floor(map->posy)] != '1')
			map->posx = map->posx + map->dirx * MOVEMENT;
		if (map->tab_map[(int)floor(map->posx)] \
		[(int)floor(map->posy + map->diry * MOVEMENT)] != '1')
			map->posy += map->diry * MOVEMENT;
	}
	if (map->key_states[KEY_S])
	{
		if (map->tab_map[(int)floor(map->posx - map->dirx * MOVEMENT)] \
		[(int)floor(map->posy)] != '1')
			map->posx -= map->dirx * MOVEMENT;
		if (map->tab_map[(int)floor(map->posx)] \
		[(int)floor(map->posy - map->diry * MOVEMENT)] != '1')
			map->posy -= map->diry * MOVEMENT;
	}
}

void	right_left(t_map *map)
{
	if (map->key_states[KEY_Q])
	{
		if (map->tab_map[(int)floor(map->posx)] \
		[(int)floor(map->posy - map->planey * MOVEMENT)] != '1')
			map->posy -= map->planey * MOVEMENT;
		if (map->tab_map[(int)floor(map->posx - map->planex * MOVEMENT)] \
		[(int)floor(map->posy)] != '1')
			map->posx -= map->planex * MOVEMENT;
	}
	if (map->key_states[KEY_D])
	{
		if (map->tab_map[(int)floor(map->posx)] \
		[(int)floor(map->posy + map->planey * MOVEMENT)] != '1')
			map->posy += map->planey * MOVEMENT;
		if (map->tab_map[(int)floor(map->posx + map->planex * MOVEMENT)] \
		[(int)floor(map->posy)] != '1')
			map->posx += map->planex * MOVEMENT;
	}
}

void	turn_left(t_map *map)
{
	if (map->key_states[KEY_LEFT])
	{
		map->p_old_dir = map->dirx;
		map->dirx = map->dirx * cos(-ROTATION * map->p_rota) - \
		map->diry * sin(-ROTATION * map->p_rota);
		map->diry = map->p_old_dir * sin(-ROTATION * map->p_rota) + \
		map->diry * cos(-ROTATION * map->p_rota);
		map->p_old_fov = map->planex;
		map->planex = map->planex * cos(-ROTATION * map->p_rota) - \
		map->planey * sin(-ROTATION * map->p_rota);
		map->planey = map->p_old_fov * sin(-ROTATION * map->p_rota) + \
		map->planey * cos(-ROTATION * map->p_rota);
	}
}

void	turn_right(t_map *map)
{
	if (map->key_states[KEY_RIGHT])
	{
		map->p_old_dir = map->dirx;
		map->dirx = map->dirx * cos(ROTATION * map->p_rota) - \
		map->diry * sin(ROTATION * map->p_rota);
		map->diry = map->p_old_dir * sin(ROTATION * map->p_rota) + \
		map->diry * cos(ROTATION * map->p_rota);
		map->p_old_fov = map->planex;
		map->planex = map->planex * cos(ROTATION * map->p_rota) - \
		map->planey * sin(ROTATION * map->p_rota);
		map->planey = map->p_old_fov * sin(ROTATION * map->p_rota) + \
		map->planey * cos(ROTATION * map->p_rota);
	}
}

void	move_player(t_map *map)
{
	if (map->key_states[KEY_ESC])
		exit(1);
	forward_backward(map);
	right_left(map);
	turn_right(map);
	turn_left(map);
	mlx_clear_window(map->mlx, map->win);
	raycasting(map);
}
