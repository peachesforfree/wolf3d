/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 00:37:06 by sbalcort          #+#    #+#             */
/*   Updated: 2017/11/11 00:46:34 by gaguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void		start_mlx(t_env *env)
{
	if (!(env->mlx = mlx_init()))
	{
		ft_putendl("\nSTART UP ERROR: FAILED TO INITIALIZE MLX");
		exit(0);
	}
	else if (!(env->win = mlx_new_window(env->mlx, WIN_X, WIN_Y, "Wolf3d")))
	{
		ft_putendl("\nSTART UP ERROR: FAILED TO INITIALIZE WINDOW");
		exit(0);
	}
	else if (!(env->img_ptr = mlx_new_image(env->mlx, WIN_X, WIN_Y)))
	{
		ft_putendl("\nSTART UP ERROR: FAILD TO INIZIALIZE IMAGE");
		exit(0);
	}
	else if (!(env->img = mlx_get_data_addr(env->img_ptr, &env->bpp,
					&env->size_line, &env->endian)))
	{
		ft_putendl("\nSTART UP ERROR: FAILED TO INIZIALIZE IMG PTR");
		exit(0);
	}
}

void		help_text(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 10, 10, 0xFFFFFF ,"W A S D or Arrows to Move");
	mlx_string_put(env->mlx, env->win, 10, 30, 0xFFFFFF ,"Hold Left Shift to Run");
	mlx_string_put(env->mlx, env->win, 10, 50, 0xFFFFFF ,"ESC to Quit");
}

void		clear_window(t_env *env)
{
	ft_memset(env->img, 0, (WIN_Y * WIN_X * 4));
}
