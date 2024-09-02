/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_tab_textur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:19:19 by dravaono          #+#    #+#             */
/*   Updated: 2024/09/01 19:55:38 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cpy_to_tab_text(t_map *map)
{
	map->i = 0;
	map->j = 0;
	map->tab_text = malloc(sizeof(char *) * 7);
	while (map->mapgnl[map->i])
	{
		if (is_direction(map->mapgnl[map->i]))
			map->tab_text[map->j++] = map->mapgnl[map->i++];
		else if (!is_whitespace(map->mapgnl[map->i]))
			return (1);
		else
			map->i++;
		if (map->j == 6)
			break ;
	}
	if (map->j != 6)
		return (1);
	map->tab_text[map->j] = NULL;
	if ((check_letter_texture_f(map) == 1)
		|| (check_letter_texture_c(map) == 1))
		return (1);
	return (0);
}

int	check_letter_texture_c(t_map *map)
{
	map->i = 0;
	map->j = 0;
	while (map->tab_text[map->i])
	{
		if (ft_strncmp(map->tab_text[map->i], "C", 1) == 0)
		{
			map->j = 1;
			while (map->tab_text[map->i][map->j] != '\n'
				&& map->tab_text[map->i][map->j] != '\0')
			{
				if (!(isnumber(&map->tab_text[map->i][map->j]))
					&& map->tab_text[map->i][map->j] != ' ')
					return (1);
				map->j++;
			}
			break ;
		}
		map->i++;
	}
	return (0);
}

int	check_letter_texture_f(t_map *map)
{
	map->i = 0;
	map->j = 0;
	while (map->tab_text[map->i])
	{
		if (ft_strncmp(map->tab_text[map->i], "F", 1) == 0)
		{
			map->j = 1;
			while (map->tab_text[map->i][map->j] != '\n'
				&& map->tab_text[map->i][map->j] != '\0')
			{
				if (!(isnumber(&map->tab_text[map->i][map->j]))
					&& map->tab_text[map->i][map->j] != ' ')
					return (1);
				map->j++;
			}
			break ;
		}
		map->i++;
	}
	return (0);
}

int	is_direction(char *mapgnl)
{
	if (ft_strncmp(mapgnl, "NO", 2) == 0 || ft_strncmp(mapgnl, "SO", 2) == 0
		|| ft_strncmp(mapgnl, "WE", 2) == 0 || ft_strncmp(mapgnl, "F", 1) == 0
		|| ft_strncmp(mapgnl, "C", 1) == 0 || ft_strncmp(mapgnl, "EA", 2) == 0)
		return (1);
	return (0);
}

int	isnumber(char *str)
{
	if ((*str >= '0' && *str <= '9') || *str == ',' || *str == '\n')
		return (1);
	return (0);
}
