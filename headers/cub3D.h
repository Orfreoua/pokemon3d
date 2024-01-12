/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:21:44 by orfreoua          #+#    #+#             */
/*   Updated: 2023/09/29 00:58:21 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "headers.h"

# define R_WIDTH 			640
# define R_HEIGHT 			480

# define FOV 60
# define PRECISION 128
# define WALL_GAP 0.2
# define ROT_SP 1
# define RUN_SP 20
# define SIDE_SP 50

typedef struct s_p
{
	int			x;
	int			y;
}	t_p;

typedef struct s_point
{
	double		x;
	double		y;
}			t_point;

typedef struct s_wall
{
	int		*pixel_addr;
	int		row_index;
	float	wall_height;
	float	texture_y;
	float	y_increment;
	float	texture_x;
}			t_wall;

typedef struct s_player
{
	t_point		pos;
	double		angle;
}			t_player;

typedef struct s_color
{
	int			color;
	int			t;
	int			r;
	int			g;
	int			b;
}			t_color;

typedef struct s_file
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	t_color		floor;
	t_color		ceiling;
	char		**map;
	t_point		size;
}				t_file;

typedef struct s_ray
{
	double		dx;
	double		dy;
	double		last_x;
	double		last_y;
	double		ray_cos;
	double		ray_sin;
	double		angle;
}				t_ray;

typedef struct s_key
{
	bool		arrow_left;
	bool		arrow_right;
	bool		up;
	bool		down;
	bool		left;
	bool		right;
}			t_key;

typedef struct s_img
{
	void		*img;
	void		*data;
	int			bpp;
	int			size_line;
	int			endian;
	int			height;
	int			width;
	char		*addr;
}	t_img;

typedef struct s_texture
{
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
}	t_texture;

typedef struct map
{
	char		**grid;
	t_p			size;
}	t_map;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}	t_textures;

typedef struct s_drago
{
	t_img	textures[47];
	char	**paths;
	t_img	textures_b[51];
	char	**paths_b;
}	t_drago;

typedef struct s_fole
{
	t_point		pos_player;
	t_textures	textures;
	t_color		ceiling;
	t_color		floor;
	double		rotate;
	char		**mapy;
	int			**taby;
	int			**map;
	int			**tab;
	char		*map_sep;
	char		*map_error;
	char		*parsing_map_msg;
	char		*p_map_msg;
	char		*src;
	int			ret_cei;
	int			ret_flo;
	int			ret;
	int			gnl;
	int			item;
	int			fd;
	int			parsing_map;
	int			pos;
	int			zone;
	int			free;
	int			x;
	int			n;
	int			len_y;
	int			y;
	int			stack;
	int			sep;
	int			big;
	int			two;
	int			fin;
}	t_fole;

typedef struct s_data
{
	t_drago		drago;
	short		bonus;
	short		menu;
	t_texture	tab_textures[6];
	t_fole		fole;
	t_file		file;
	t_key		key;
	t_player	player;
	t_ray		ray;
	t_img		img;
	t_texture	texture;
	void		*mlx;
	void		*win;
	t_map		map;
	t_img		text;
	int			zone;
}			t_data;

#endif
