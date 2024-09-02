/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:28:37 by dravaono          #+#    #+#             */
/*   Updated: 2024/07/30 18:39:03 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_str_direct(t_map *map)
{
	free(map->nostr);
	free(map->sostr);
	free(map->eastr);
	free(map->westr);
}

void	free_text(t_map *map)
{
	free_tab(map->mapgnl);
	free_str_direct(map);
	free(map->cfinal);
	free(map->ffinal);
}

void	free_all_parsing(t_map *map)
{
	free_text(map);
	free(map->tab_map);
	free_tab(map->mapfinal);
}
