/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:14:59 by dravaono          #+#    #+#             */
/*   Updated: 2024/09/01 20:12:46 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line_bonus.h"
# include "../libft/inc/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <time.h>
# include <stddef.h>
# include <string.h>
# include <signal.h>
# include <errno.h>
# include <pthread.h>

# define SCREENHEIGHT 600
# define SCREENWIDTH 1000

# define MOVEMENT 0.02
# define ROTATION 0.008
# define PI 3.1415926535

# define KEY_Z 119
# define KEY_Q 97
# define KEY_S 115
# define KEY_D 100
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_ESC 65307

typedef struct s_img
{
	void	*img;
	char	*addr;
	char	*file;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_map
{
	void	*mlx;
	void	*win;

	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	wall_x;
	double	p_old_dir;
	double	p_old_fov;
	double	p_rota;
	double	lineheight;

	t_img	*imgs;
	t_img	*so_tex;
	t_img	*no_tex;
	t_img	*we_tex;
	t_img	*ea_tex;

	char	*sostr;
	char	*nostr;
	char	*eastr;
	char	*westr;
	char	**mapgnl;
	char	**mapfinal;
	char	**fstrsplit;
	char	**cstrsplit;
	char	**tab_text;
	char	**tab_map;
	char	player_pos;

	int		key_states[65536];
	int		*ffinal;
	int		*cfinal;
	int		linemap;
	int		x;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		drawend;
	int		drawstart;
	int		size_so;
	int		size_no;
	int		size_we;
	int		size_ea;
	int		size_c;
	int		size_f;
	int		sizeinfo;
	int		longest_line_length;
	int		size_length_map;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		c;
	int		f;
	int		count;
	int		i;
	int		j;
}			t_map;

void		check_name_cube(char *av);
void		allsize(t_map *mappy);
void		sizeno(t_map *mappy);
void		sizeso(t_map *mappy);
void		sizec(t_map *mappy);
void		sizef(t_map *mappy);
void		sizewe(t_map *mappy);
void		sizeea(t_map *mappy);
void		second_part_function(t_map *map);
void		free_all_parsing(t_map *map);
void		mlx_start(t_map *map);
void		sizemap(t_map *mappy, char *av);
void		cpymap(t_map *mappy, char *av);
void		check_all_texture(t_map *map);
void		checkdoubles(t_map *map, char *line);
void		initialize_map(t_map *map);
void		initialize_map2(t_map *map);
void		init_text(t_map *map);
void		init_text2(t_map *map);
void		calculate_ray_position_direction(t_map *map);
void		initialize_side_distances(t_map *map);
void		perform_dda(t_map *map);
void		calculate_wall_distance(t_map *map);
void		raycasting(t_map *map);
void		forward_backward(t_map *map);
void		right_left(t_map *map);
void		turn_right(t_map *map);
void		turn_left(t_map *map);
void		move_player(t_map *map);
void		init_player(t_map *map);
void		init_angleplayer(t_map *map, char p);
void		init_angleplayer2(t_map *map, char p);
void		free_str_direct(t_map *map);
void		first_part_function(t_map *mappy, char *av);
void		find_longest_line_length(t_map *mappy);
void		free_text(t_map *map);
void		filltab(t_map *mp);
void		start_draw(t_map *map);
void		mlx_start(t_map *map);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		make_floor(t_map *map);
void		wall(t_map *map);
void		make_sky(t_map *map);

int			key_press(int keycode, t_map *map);
int			key_release(int keycode, t_map *map);
int			cpy_to_tab_text(t_map *map);
int			is_direction(char *mapgnl);
int			isnumber(char *str);
int			check_letter_texture_f(t_map *map);
int			check_letter_texture_c(t_map *map);
int			check_space_no(t_map *map);
int			check_space_so(t_map *map);
int			check_space_ea(t_map *map);
int			check_space_we(t_map *map);
int			isword(char *str);
int			check_virgul_color(t_map *map);
int			check_number_color_c(t_map *map);
int			check_number_color_f(t_map *map);
int			cpy_tab_maps(t_map *map);
int			malloc_map(t_map *map);
int			cparsing(t_map *mappy);
int			fparsing(t_map *mappy);
int			caractmap(t_map *mp);
int			manyperso(t_map *mp);
int			check_final_map(t_map *mp);
int			check_final_map_player(t_map *mp);
int			create_trgb(int t, int r, int g, int b);
int			choose_color(t_img *img, int x, int y);

char		*fill_line_space(t_map *map);
char		*send_treated_line(char *str, t_map *mp);

t_img		*get_wall(t_map *map);

#endif