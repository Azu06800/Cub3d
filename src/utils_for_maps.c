/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_maps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:56:39 by dravaono          #+#    #+#             */
/*   Updated: 2024/07/30 19:40:01 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	cpy_tab_maps(t_map *map)
// {
// 	if (malloc_map(map) == 1)
// 		return (1);
// 	map->i = map->sizeinfo;
// 	map->c = 0;
// 	while (map->mapgnl[map->i])
// 	{
// 		map->f = 0;
// 		map->j = 0;
// 		map->mapgnl[map->i][ft_strlen(map->mapgnl[map->i]) - 1] = '\0';
// 		// while (map->mapgnl[map->i][map->j])
// 		// 	if (map->mapgnl[map->i][map->j++] != ' ')
// 		// 		map->f++;
// 		// if (map->f != 0)
// 		map->tab_map[map->c++] = map->mapgnl[map->i];
// 		map->i++;
// 	}
// 	map->i = -1;
// 	while (map->tab_map[++map->i])
// 		printf("%s\n", map->tab_map[map->i]);
// 	find_longest_line_length(map);
// 	map->i = -1;
// 	return (0);
// }

int	malloc_map(t_map *map)
{
	map->j = 0;
	map->i = -1;
	while (map->mapgnl[++map->i])
	{
		if (is_direction(map->mapgnl[map->i]))
			map->j++;
		if (map->j == 6)
			break ;
	}
	map->c = 0;
	map->sizeinfo = map->i + 1;
	while (map->mapgnl[++map->i])
		map->c++;
	map->tab_map = ft_calloc((map->c + 1), sizeof(char *));
	map->size_length_map = map->c;
	if (!map->tab_map)
		return (1);
	return (0);
}

void	find_longest_line_length(t_map *mappy)
{
	int	i;
	int	j;
	int	line_length;

	i = 0;
	mappy->longest_line_length = 0;
	while (mappy->tab_map[i])
	{
		j = 0;
		while (mappy->tab_map[i][j] != '\0')
			j++;
		line_length = j;
		if (line_length > mappy->longest_line_length)
			mappy->longest_line_length = line_length;
		i++;
	}
}

int	caractmap(t_map *mp)
{
	int	y;
	int	x;

	y = -1;
	while (mp->tab_map[++y])
	{
		x = -1;
		while (mp->tab_map[y][++x] != '\0')
		{
			if ((mp->tab_map[y][x] != '1') && (mp->tab_map[y][x] != '\n')
				&& (mp->tab_map[y][x] != '0') && (mp->tab_map[y][x] != ' ')
				&& (mp->tab_map[y][x] != 'N') && (mp->tab_map[y][x] != 'S')
				&& (mp->tab_map[y][x] != 'E') && (mp->tab_map[y][x] != 'W'))
				return (1);
		}
	}
	return (0);
}

int	manyperso(t_map *mp)
{
	int	y;
	int	i;
	int	x;

	i = -1;
	x = 1;
	while (mp->tab_map[++i])
	{
		y = -1;
		while (mp->tab_map[i][++y])
			if (mp->tab_map[i][y] == 'S' || mp->tab_map[i][y] == 'W'
				|| mp->tab_map[i][y] == 'E' || mp->tab_map[i][y] == 'N')
				x++;
	}
	if (x != 2)
		return (1);
	return (0);
}
