/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 00:52:10 by sbalcort          #+#    #+#             */
/*   Updated: 2017/11/10 21:20:03 by gaguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdlib.h>
# include <unistd.h>
# include "../libs/minilibx/mlx.h"
# include <math.h>
# include "../libs/libft/libft.h"
# include "keys.h"
# define WIN_X 1080
# define WIN_Y 900
# define MAPWIDTH 24
# define MAPHEIGHT 20
# define RGB_WHITE 0xFFFFFF
# define RGB_RED 0xFF0000
# define RGB_GREEN 0x00FF00
# define RGB_BLUE 0x0000FF
# define RGB_YELLOW 0xFFFF00

typedef struct	s_env
{
	int			color;
	float		movespeed;
	int			minimap;
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			bpp;
	int			size_line;
	int			endian;
	void		*tmp_map;
	int			worldmap[MAPWIDTH][MAPHEIGHT];
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		olddirx;
	double		oldplanex;
	double		planey;
	double		camerax;
	double		cameray;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	double		rotspeed;
	char		**map;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			mapx;
	int			mapy;
	int			x;
	int			y;
	int			w;
	int			h;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			xx;
}				t_env;

void			keycode_cont_cont(int keycode, t_env *env);
void			key_code_cont(int keycode, t_env *env);
int				exit_hook(void);
void			map(t_env *env);
char			**create_map(void);
void			start_mlx(t_env *env);
int				key_hook(int keycode, t_env *env);
void			raycaster(t_env *env);
void			clear_window(t_env *env);
void			draw_line_to_image(t_env *env);
void			mlx_put_pixel_to_image(t_env *env, int x, int y, int color);
void			color_selection(t_env *env);
void			projection(t_env *env);
void			movement(t_env *env);
void			declarations(t_env *env);
void			dda_algorithm(t_env *env);
int				expose_hook(t_env *env);

#endif
