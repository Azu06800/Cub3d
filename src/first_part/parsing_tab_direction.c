/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tab_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:09:14 by dravaono          #+#    #+#             */
/*   Updated: 2024/08/27 16:53:01 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_space_no(t_map *map)
{
	map->i = -1;
	while (map->tab_text[++map->i])
	{
		if (ft_strncmp(map->tab_text[map->i], "NO", 2) == 0)
		{
			map->c = 0;
			map->j = 2;
			if (map->tab_text[map->i][2] != ' ')
				return (1);
			while (map->tab_text[map->i][++map->j] != '\0'
				&& map->tab_text[map->i][map->j] != '\n')
			{
				if (isword(&map->tab_text[map->i][map->j]))
					map->nostr[map->c++] = map->tab_text[map->i][map->j];
				else
					return (1);
			}
			map->nostr[map->c] = '\0';
			break ;
		}
	}
	return (0);
}

int	check_space_we(t_map *map)
{
	map->i = -1;
	while (map->tab_text[++map->i])
	{
		if (ft_strncmp(map->tab_text[map->i], "WE", 2) == 0)
		{
			map->c = 0;
			map->j = 2;
			if (map->tab_text[map->i][2] != ' ')
				return (1);
			while (map->tab_text[map->i][++map->j] != '\0'
				&& map->tab_text[map->i][map->j] != '\n')
			{
				if (isword(&map->tab_text[map->i][map->j]))
					map->westr[map->c++] = map->tab_text[map->i][map->j];
				else
					return (1);
			}
			map->westr[map->c] = '\0';
			break ;
		}
	}
	return (0);
}

int	check_space_ea(t_map *map)
{
	map->i = -1;
	while (map->tab_text[++map->i])
	{
		if (ft_strncmp(map->tab_text[map->i], "EA", 2) == 0)
		{
			map->c = 0;
			map->j = 2;
			if (map->tab_text[map->i][2] != ' ')
				return (1);
			while (map->tab_text[map->i][++map->j] != '\0'
				&& map->tab_text[map->i][map->j] != '\n')
			{
				if (isword(&map->tab_text[map->i][map->j]))
					map->eastr[map->c++] = map->tab_text[map->i][map->j];
				else
					return (1);
			}
			map->eastr[map->c] = '\0';
			break ;
		}
	}
	return (0);
}

int	check_space_so(t_map *map)
{
	map->i = -1;
	while (map->tab_text[++map->i])
	{
		if (ft_strncmp(map->tab_text[map->i], "SO", 2) == 0)
		{
			map->c = 0;
			map->j = 2;
			if (map->tab_text[map->i][2] != ' ')
				return (1);
			while (map->tab_text[map->i][++map->j] != '\0'
				&& map->tab_text[map->i][map->j] != '\n')
			{
				if (isword(&map->tab_text[map->i][map->j]))
					map->sostr[map->c++] = map->tab_text[map->i][map->j];
				else
					return (1);
			}
			map->sostr[map->c] = '\0';
			break ;
		}
	}
	return (0);
}
