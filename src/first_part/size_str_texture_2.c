/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_str_texture_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:14:14 by dravaono          #+#    #+#             */
/*   Updated: 2024/08/27 16:53:05 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sizef(t_map *mappy)
{
	int	i;
	int	j;

	i = 0;
	mappy->size_f = 0;
	while (mappy->tab_text[i])
	{
		if (ft_strncmp(mappy->tab_text[i], "F", 1) == 0)
		{
			j = 1;
			while (mappy->tab_text[i][j] != '\0'
				&& mappy->tab_text[i][j] != '\n')
			{
				if (isword(&mappy->tab_text[i][j]))
					mappy->size_f++;
				j++;
			}
			break ;
		}
		i++;
	}
}

void	allsize(t_map *mappy)
{
	sizeea(mappy);
	sizeno(mappy);
	sizewe(mappy);
	sizeso(mappy);
	sizec(mappy);
	sizef(mappy);
}

int	isword(char *str)
{
	if (letter(str) == 1 || *str == '.' || *str == '/' || *str == '_')
		return (1);
	return (0);
}
