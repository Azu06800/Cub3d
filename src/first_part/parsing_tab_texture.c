/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tab_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:58:24 by dravaono          #+#    #+#             */
/*   Updated: 2024/08/27 16:53:03 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_virgul_color(t_map *map)
{
	map->c = 0;
	map->i = -1;
	while (map->tab_text[++map->i])
	{
		if (ft_strncmp(map->tab_text[map->i], "F", 1) == 0)
		{
			map->j = 1;
			while (map->tab_text[map->i][++map->j])
				if (map->tab_text[map->i][map->j] == ',')
					map->c++;
		}
		if (ft_strncmp(map->tab_text[map->i], "C", 1) == 0)
		{
			map->j = 1;
			while (map->tab_text[map->i][++map->j])
				if (map->tab_text[map->i][map->j] == ',')
					map->c++;
		}
	}
	if (map->c != 4)
		return (1);
	return (0);
}

int	check_number_color_c(t_map *map)
{
	map->i = -1;
	while (map->tab_text[++map->i])
	{
		if (ft_strncmp(map->tab_text[map->i], "C", 1) == 0)
		{
			if (map->tab_text[map->i][1] != ' ')
				return (1);
			map->j = 2;
			while (map->tab_text[map->i][map->j])
			{
				if (isnumber(&map->tab_text[map->i][map->j]))
					map->j++;
				else
					return (1);
			}
		}
	}
	return (0);
}

int	check_number_color_f(t_map *map)
{
	map->i = -1;
	while (map->tab_text[++map->i])
	{
		if (ft_strncmp(map->tab_text[map->i], "F", 1) == 0)
		{
			if (map->tab_text[map->i][1] != ' ')
				return (1);
			map->j = 2;
			while (map->tab_text[map->i][map->j])
			{
				if (isnumber(&map->tab_text[map->i][map->j]))
					map->j++;
				else
					return (1);
			}
		}
	}
	return (0);
}
