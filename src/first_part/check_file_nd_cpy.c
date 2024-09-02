/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_nd_cpy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:11:51 by dravaono          #+#    #+#             */
/*   Updated: 2024/09/01 19:54:59 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_name_cube(char *av)
{
	int	i;

	if (open(av, __O_DIRECTORY) != -1)
		ft_error("Error\n Sorry it's a folder");
	if (open(av, O_RDONLY) == -1)
		ft_error("Error\n Check your File");
	i = ft_strlen(av);
	i -= 4;
	if (i < 1)
		ft_error("Error\n Check your File");
	if ((ft_strncmp(&av[i], ".cub", 4) != 0))
		ft_error("Error\n Check your .cub");
}

void	cpymap(t_map *mappy, char *av)
{
	int	fd;
	int	y;
	int	i;

	fd = open(av, O_RDONLY);
	mappy->mapgnl = malloc((sizeof(char *) + 1) * mappy->linemap);
	y = 0;
	mappy->mapgnl[y] = get_next_line(fd);
	while (++y < mappy->linemap)
		mappy->mapgnl[y] = get_next_line(fd);
	mappy->mapgnl[y] = NULL;
	y = -1;
	while (mappy->mapgnl[++y])
	{
		i = -1;
		while (mappy->mapgnl[y][++i])
		{
			if (mappy->mapgnl[y][i] == '\t')
			{
				free_tab(mappy->mapgnl);
				ft_error("TAB");
			}
		}
	}
	close(fd);
}

void	sizemap(t_map *mappy, char *av)
{
	int		fd;
	char	*mapline;

	fd = open(av, O_RDONLY);
	mapline = get_next_line(fd);
	mappy->linemap = 0;
	while (mapline)
	{
		free(mapline);
		mappy->linemap++;
		mapline = get_next_line(fd);
	}
	close(fd);
}

void	check_all_texture(t_map *map)
{
	int	i;

	map->no = 0;
	map->so = 0;
	map->we = 0;
	map->ea = 0;
	map->c = 0;
	map->f = 0;
	i = -1;
	while (map->mapgnl[++i])
		checkdoubles(map, map->mapgnl[i]);
	if (map->no != 1 || map->so != 1 || map->we != 1 || map->ea != 1
		|| map->c != 1 || map->f != 1)
	{
		free_tab(map->mapgnl);
		ft_error("Error Texture\n");
	}
}

void	checkdoubles(t_map *map, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		map->no++;
	else if (ft_strncmp(line, "SO", 2) == 0)
		map->so++;
	else if (ft_strncmp(line, "WE", 2) == 0)
		map->we++;
	else if (ft_strncmp(line, "F", 1) == 0)
		map->f++;
	else if (ft_strncmp(line, "C", 1) == 0)
		map->c++;
	else if (ft_strncmp(line, "EA", 2) == 0)
		map->ea++;
}
