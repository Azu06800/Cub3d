/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:30:41 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/02 00:29:54 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_text(t_map *map)
{
	init_text2(map);
	map->imgs->img = mlx_new_image(map->mlx, SCREENWIDTH, SCREENHEIGHT);
	map->imgs->addr = mlx_get_data_addr(map->imgs->img, \
	&map->imgs->bits_per_pixel, &map->imgs->line_length, &map->imgs->endian);
	map->so_tex->img = mlx_xpm_file_to_image(map->mlx, map->sostr, \
	&map->so_tex->width, &map->so_tex->height);
	map->so_tex->addr = mlx_get_data_addr(map->so_tex->img, \
	&map->so_tex->bits_per_pixel, \
	&map->so_tex->line_length, &map->so_tex->endian);
	map->no_tex->img = mlx_xpm_file_to_image(map->mlx, \
	map->nostr, &map->no_tex->width, &map->no_tex->height);
	map->no_tex->addr = mlx_get_data_addr \
	(map->no_tex->img, &map->no_tex->bits_per_pixel, \
	&map->no_tex->line_length, &map->no_tex->endian);
	map->we_tex->img = mlx_xpm_file_to_image(map->mlx, map->westr, \
	&map->we_tex->width, &map->we_tex->height);
	map->we_tex->addr = mlx_get_data_addr(map->we_tex->img, \
	&map->we_tex->bits_per_pixel, &map->we_tex->line_length, \
	&map->we_tex->endian);
	map->ea_tex->img = mlx_xpm_file_to_image(map->mlx, map->eastr, \
	&map->ea_tex->width, &map->ea_tex->height);
	map->ea_tex->addr = mlx_get_data_addr(map->ea_tex->img, \
	&map->ea_tex->bits_per_pixel, \
	&map->ea_tex->line_length, &map->ea_tex->endian);
}

void	init_text2(t_map *map)
{
	map->imgs = calloc(1, sizeof(t_img));
	map->so_tex = calloc(1, sizeof(t_img));
	map->no_tex = calloc(1, sizeof(t_img));
	map->we_tex = calloc(1, sizeof(t_img));
	map->ea_tex = calloc(1, sizeof(t_img));
}

void	first_part_function(t_map *mappy, char *av)
{
	check_name_cube(av);
	sizemap(mappy, av);
	cpymap(mappy, av);
	check_all_texture(mappy);
	if (cpy_to_tab_text(mappy) == 1 || check_virgul_color(mappy) == 1
		|| check_number_color_c(mappy) == 1 || check_number_color_f(mappy) == 1)
	{
		free_tab(mappy->mapgnl);
		free(mappy->tab_text);
		ft_error("ERROR TEXTURE");
	}
	allsize(mappy);
	if (check_space_no(mappy) == 1 || check_space_ea(mappy) == 1
		|| check_space_we(mappy) == 1 || check_space_so(mappy) == 1
		|| cparsing(mappy) == 1 || fparsing(mappy) == 1)
	{
		free_tab(mappy->mapgnl);
		free(mappy->tab_text);
		free_str_direct(mappy);
		free(mappy->cfinal);
		free(mappy->ffinal);
		ft_error("ERROR TEXTURE 2");
	}
	free(mappy->tab_text);
}

void	second_part_function(t_map *map)
{
	if (cpy_tab_maps(map) == 1 || caractmap(map) == 1 || manyperso(map) == 1)
	{
		free_text(map);
		free(map->tab_map);
		ft_error("ERROR MAP 1");
	}
	filltab(map);
	if (check_final_map(map) == 1 || check_final_map_player(map) == 1)
	{
		free(map->tab_map);
		free_tab(map->mapfinal);
		free_text(map);
		ft_error("ERROR MAP 2");
	}
}

int	main(int ac, char **av)
{
	t_map	*mappy;

	if (ac != 2)
	{
		write(2, "ERROR: bad arguments\n", 22);
		return (0);
	}
	else
	{
		mappy = malloc(sizeof(t_map));
		first_part_function(mappy, av[1]);
		second_part_function(mappy);
		mlx_start(mappy);
		init_text(mappy);
		initialize_map(mappy);
		raycasting(mappy);
		mlx_hook(mappy->win, 2, 1L << 0, (void *)key_press, mappy);
		mlx_hook(mappy->win, 3, 1L << 1, (void *)key_release, mappy);
		mlx_loop_hook(mappy->mlx, (void *)move_player, mappy);
		mlx_hook(mappy->win, 17, 0, (void *)exit, 0);
		mlx_loop(mappy->mlx);
	}
}
