/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_final_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:00:02 by dravaono          #+#    #+#             */
/*   Updated: 2024/09/01 19:19:16 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	filltab(t_map *mp)
{
	int	sizemapmax;

	sizemapmax = mp->size_length_map;
	mp->mapfinal = ft_calloc((sizemapmax + 3), sizeof(char *));
	if (!mp->mapfinal)
		ft_error("Error allocating memory for mapfinal");
	mp->mapfinal[0] = fill_line_space(mp);
	mp->i = 0;
	mp->j = 1;
	while (mp->tab_map[mp->i])
	{
		mp->mapfinal[mp->j] = send_treated_line(mp->tab_map[mp->i], mp);
		mp->j++;
		mp->i++;
	}
	mp->mapfinal[mp->j] = fill_line_space(mp);
	mp->mapfinal[mp->j + 1] = NULL;
}

char	*fill_line_space(t_map *map)
{
	int		i;
	int		lenght;
	char	*str;

	lenght = map->longest_line_length + 3;
	str = ft_calloc(lenght, sizeof(char));
	if (!str)
		ft_error("Error allocating memory for mapfinal");
	i = 0;
	while (i < lenght)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*send_treated_line(char *str, t_map *mp)
{
	int		i;
	int		j;
	int		lenght;
	char	*str_to_send;

	lenght = mp->longest_line_length + 3;
	str_to_send = malloc(sizeof(char) * lenght);
	if (!str_to_send)
		ft_error("Error allocating memory for str_to_send");
	i = 0;
	j = 1;
	str_to_send[0] = ' ';
	while (j < lenght)
	{
		if (str[i] != '\0')
			while (str[i])
				str_to_send[j++] = str[i++];
		else
		{
			str_to_send[j] = ' ';
			j++;
		}
	}
	str_to_send[j] = '\0';
	return (str_to_send);
}

int	check_final_map(t_map *mp)
{
	mp->i = 0;
	while (mp->mapfinal[mp->i])
	{
		mp->j = 0;
		while (mp->mapfinal[mp->i][mp->j])
		{
			if ((mp->mapfinal[mp->i][mp->j] == '0') && ((mp->mapfinal[mp->i
						+ 1][mp->j] == ' ') || (mp->mapfinal[mp->i
						- 1][mp->j] == ' ') || (mp->mapfinal[mp->i][mp->j
						+ 1] == ' ') || (mp->mapfinal[mp->i - 1][mp->j
						- 1] == ' ')))
				return (1);
			mp->j++;
		}
		mp->i++;
	}
	return (0);
}

int	check_final_map_player(t_map *mp)
{
	mp->i = 0;
	while (mp->mapfinal[mp->i])
	{
		mp->j = 0;
		while (mp->mapfinal[mp->i][mp->j])
		{
			if (((mp->mapfinal[mp->i][mp->j] == 'N')
				|| (mp->mapfinal[mp->i][mp->j] == 'S')
				|| (mp->mapfinal[mp->i][mp->j] == 'E')
				|| (mp->mapfinal[mp->i][mp->j] == 'W'))
				&& ((mp->mapfinal[mp->i + 1][mp->j] == ' ')
				|| (mp->mapfinal[mp->i - 1][mp->j] == ' ')
				|| (mp->mapfinal[mp->i][mp->j + 1] == ' ')
				|| (mp->mapfinal[mp->i - 1][mp->j - 1] == ' ')))
				return (1);
			mp->j++;
		}
		mp->i++;
	}
	return (0);
}
