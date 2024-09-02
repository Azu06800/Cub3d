/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_str_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:11:39 by dravaono          #+#    #+#             */
/*   Updated: 2024/09/01 19:55:18 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sizeea(t_map *mappy)
{
	int	i;
	int	j;

	i = 0;
	mappy->size_ea = 0;
	while (mappy->tab_text[i])
	{
		if (ft_strncmp(mappy->tab_text[i], "EA", 2) == 0)
		{
			j = 2;
			while (mappy->tab_text[i][j] != '\0'
				&& mappy->tab_text[i][j] != '\n')
			{
				if (isword(&mappy->tab_text[i][j]))
					mappy->size_ea++;
				j++;
			}
			break ;
		}
		i++;
	}
	mappy->eastr = ft_calloc(mappy->size_ea + 1, sizeof(char));
}

void	sizec(t_map *mappy)
{
	int	i;
	int	j;

	i = 0;
	mappy->size_c = 0;
	while (mappy->tab_text[i])
	{
		if (ft_strncmp(mappy->tab_text[i], "C", 1) == 0)
		{
			j = 1;
			while (mappy->tab_text[i][j] != '\0'
				&& mappy->tab_text[i][j] != '\n')
			{
				if ((mappy->tab_text[i][j] >= '0'
					&& mappy->tab_text[i][j] <= '9')
					|| mappy->tab_text[i][j] == ',')
					mappy->size_c++;
				j++;
			}
			break ;
		}
		i++;
	}
}

void	sizeso(t_map *mappy)
{
	int	i;
	int	j;

	i = 0;
	mappy->size_so = 0;
	while (mappy->tab_text[i])
	{
		if (ft_strncmp(mappy->tab_text[i], "SO", 2) == 0)
		{
			j = 2;
			while (mappy->tab_text[i][j] != '\0'
				&& mappy->tab_text[i][j] != '\n')
			{
				if (isword(&mappy->tab_text[i][j]))
					mappy->size_so++;
				j++;
			}
			break ;
		}
		i++;
	}
	mappy->sostr = ft_calloc(mappy->size_so + 1, sizeof(char));
}

void	sizeno(t_map *mappy)
{
	int	i;
	int	j;

	i = 0;
	mappy->size_no = 0;
	while (mappy->tab_text[i])
	{
		if (ft_strncmp(mappy->tab_text[i], "NO", 2) == 0)
		{
			j = 2;
			if (mappy->tab_text[i][j] == ' ')
				j++;
			while (mappy->tab_text[i][j] != '\0'
				&& mappy->tab_text[i][j] != '\n')
			{
				if (isword(&mappy->tab_text[i][j]))
					mappy->size_no++;
				j++;
			}
			break ;
		}
		i++;
	}
	mappy->nostr = ft_calloc(mappy->size_no + 1, sizeof(char));
}

void	sizewe(t_map *mappy)
{
	int	i;
	int	j;

	i = 0;
	mappy->size_we = 0;
	while (mappy->tab_text[i])
	{
		if (ft_strncmp(mappy->tab_text[i], "WE", 2) == 0)
		{
			j = 2;
			while (mappy->tab_text[i][j] != '\0'
				&& mappy->tab_text[i][j] != '\n')
			{
				if (isword(&mappy->tab_text[i][j]))
					mappy->size_we++;
				j++;
			}
			break ;
		}
		i++;
	}
	mappy->westr = ft_calloc(mappy->size_we + 1, sizeof(char));
}
