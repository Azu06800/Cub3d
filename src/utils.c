/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:03:47 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/01 21:04:46 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	init_player(t_map *map)
{
	int		i;
	int		j;
	char	**mapp;

	i = 0;
	j = 0;
	mapp = map->tab_map;
	while (mapp[i])
	{
		j = 0;
		while (mapp[i][j])
		{
			if (mapp[i][j] == 'N' || mapp[i][j] == 'S' ||
				mapp[i][j] == 'W' || mapp[i][j] == 'E')
			{
				map->posx = (double)i + 0.5;
				map->posy = (double)j + 0.5;
				map->player_pos = mapp[i][j];
			}
			j++;
		}
		i++;
	}
}

void	init_angleplayer(t_map *map, char p)
{
	if (p == 'N')
	{
		map->p_rota = (PI / 4);
		map->dirx = -1;
		map->diry = 0;
		map->planex = 0;
		map->planey = 0.66;
	}
	else if (p == 'S')
	{
		map->p_rota = (PI / 4);
		map->dirx = 1;
		map->diry = 0;
		map->planex = 0;
		map->planey = -0.66;
	}
	else if (p == 'E' || p == 'W')
		init_angleplayer2(map, p);
}

void	init_angleplayer2(t_map *map, char p)
{
	if (p == 'E')
	{
		map->p_rota = -(PI / 4);
		map->dirx = 0;
		map->diry = 1;
		map->planex = -0.66;
		map->planey = 0;
	}
	else if (p == 'W')
	{
		map->p_rota = (PI / 4);
		map->dirx = 0;
		map->diry = -1;
		map->planex = 0.66;
		map->planey = 0;
	}
}

int	choose_color(t_img *img, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(unsigned int *)pixel;
	return (color);
}
