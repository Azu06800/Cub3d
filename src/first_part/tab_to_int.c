/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:25:24 by dravaono          #+#    #+#             */
/*   Updated: 2024/08/27 16:53:09 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fparsing(t_map *mappy)
{
	char	*str;

	mappy->i = -1;
	while (mappy->tab_text[++mappy->i])
		if (ft_strncmp(mappy->tab_text[mappy->i], "F", 1) == 0)
			break ;
	str = ft_strdup(mappy->tab_text[mappy->i] + 2);
	mappy->fstrsplit = ft_split(str, ',');
	free(str);
	mappy->count = 0;
	mappy->i = -1;
	while (mappy->fstrsplit[++mappy->i])
		mappy->count++;
	mappy->ffinal = malloc(sizeof(int) * mappy->count);
	mappy->i = -1;
	while (++mappy->i < mappy->count)
		mappy->ffinal[mappy->i] = ft_atoi(mappy->fstrsplit[mappy->i]);
	free_tab(mappy->fstrsplit);
	mappy->i = -1;
	while (++mappy->i < mappy->count)
		if (mappy->ffinal[mappy->i] < 0 || mappy->ffinal[mappy->i] > 255)
			return (1);
	return (0);
}

int	cparsing(t_map *mappy)
{
	char	*str;

	mappy->i = -1;
	while (mappy->tab_text[++mappy->i])
		if (ft_strncmp(mappy->tab_text[mappy->i], "C", 1) == 0)
			break ;
	str = ft_strdup(mappy->tab_text[mappy->i] + 2);
	mappy->cstrsplit = ft_split(str, ',');
	free(str);
	mappy->count = 0;
	mappy->i = -1;
	while (mappy->cstrsplit[++mappy->i])
		mappy->count++;
	mappy->cfinal = malloc(sizeof(int) * mappy->count);
	mappy->i = -1;
	while (++mappy->i < mappy->count)
		mappy->cfinal[mappy->i] = ft_atoi(mappy->cstrsplit[mappy->i]);
	free_tab(mappy->cstrsplit);
	mappy->i = -1;
	while (++mappy->i < mappy->count)
		if (mappy->cfinal[mappy->i] < 0 || mappy->cfinal[mappy->i] > 255)
			return (1);
	return (0);
}
