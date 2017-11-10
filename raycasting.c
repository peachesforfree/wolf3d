/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 00:38:37 by sbalcort          #+#    #+#             */
/*   Updated: 2017/10/02 14:21:13 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		raycaster(t_env *env)
{
	env->x = 0;
	while (env->x < WIN_X)
	{
		declarations(env);
		movement(env);
		dda_algorithm(env);
		projection(env);
		color_selection(env);
		draw_line_to_image(env);
		env->x++;
	}
	expose_hook(env);
	clear_window(env);
}

void		mlx_put_pixel_to_img(t_env *e, int x, int y, int color)
{
	ft_memcpy(&e->img[(x * 4) + (y * e->size_line)], &color, 4);
}

int			expose_hook(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img_ptr, 0, 0);
	return (0);
}

void		draw_line_to_image(t_env *env)
{
	while (env->drawstart < env->drawend)
	{
		mlx_put_pixel_to_img(env, env->x, env->drawstart, env->color);
		env->drawstart += 1;
	}
}
