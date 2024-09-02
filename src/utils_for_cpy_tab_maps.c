/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_cpy_tab_maps.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:39:37 by dravaono          #+#    #+#             */
/*   Updated: 2024/09/01 21:25:22 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_map_start(t_map *map)
{
	int	i;

	i = map->sizeinfo;
	while (map->mapgnl[i] && (ft_strlen(map->mapgnl[i]) == 0
			|| is_whitespace(map->mapgnl[i])))
		i++;
	return (i);
}

int	find_map_end(t_map *map, int start)
{
	int	end;

	end = start;
	while (map->mapgnl[end])
	{
		if (ft_strlen(map->mapgnl[end]) > 0 && !is_whitespace(map->mapgnl[end]))
			map->c++;
		end++;
	}
	end--;
	while (end >= start && (ft_strlen(map->mapgnl[end]) == 0
			|| is_whitespace(map->mapgnl[end])))
		end--;
	return (end);
}

void	copy_map_lines(t_map *map, int start, int end)
{
	size_t	len;

	map->c = 0;
	while (start <= end)
	{
		len = ft_strlen(map->mapgnl[start]);
		if (len > 0 && map->mapgnl[start][len - 1] == '\n')
			map->mapgnl[start][len - 1] = '\0';
		map->tab_map[map->c++] = map->mapgnl[start++];
	}
	map->tab_map[map->c] = NULL;
}

void	print_map(t_map *map)
{
	map->i = -1;
	while (map->tab_map[++map->i])
		printf("%s\n", map->tab_map[map->i]);
}

int	cpy_tab_maps(t_map *map)
{
	int	start;
	int	end;

	if (malloc_map(map) == 1)
		return (1);
	start = find_map_start(map);
	end = find_map_end(map, start);
	copy_map_lines(map, start, end);
	find_longest_line_length(map);
	return (0);
}
