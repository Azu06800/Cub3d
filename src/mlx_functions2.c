/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:16:18 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/02 01:12:36 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_map *map)
{
	map->key_states[keycode] = 1;
	return (0);
}

int	key_release(int keycode, t_map *map)
{
	map->key_states[keycode] = 0;
	mlx_clear_window(map->mlx, map->win);
	raycasting(map);
	return (0);
}
