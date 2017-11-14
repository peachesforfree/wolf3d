/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 00:38:37 by sbalcort          #+#    #+#             */
/*   Updated: 2017/11/13 22:38:48 by gaguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

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
	int winy;

	winy = (WIN_Y / 2);
	while (winy > 0)
	{
		mlx_put_pixel_to_img(env, env->x, winy, 0x87CEEB);
		winy--;
	}
	winy = (WIN_Y / 2);
	while (winy < WIN_Y)
	{
		mlx_put_pixel_to_img(env, env->x, winy, 0x808080);
		winy++;
	}
	while (env->drawstart < env->drawend)
	{
		mlx_put_pixel_to_img(env, env->x, env->drawstart, env->color);
		env->drawstart += 1;
	}
}
