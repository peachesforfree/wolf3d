/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declarations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 23:14:56 by sbalcort          #+#    #+#             */
/*   Updated: 2017/10/02 00:04:29 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		movement(t_env *env)
{
	if (env->raydirx < 0)
	{
		env->stepx = -1;
		env->sidedistx = (env->rayposx - env->mapx) * env->deltadistx;
	}
	else
	{
		env->stepx = 1;
		env->sidedistx = (env->mapx + 1.0 - env->rayposx) * env->deltadistx;
	}
	if (env->raydiry < 0)
	{
		env->stepy = -1;
		env->sidedisty = (env->rayposy - env->mapy) * env->deltadisty;
	}
	else
	{
		env->stepy = 1;
		env->sidedisty = (env->mapy + 1.0 - env->rayposy) * env->deltadisty;
	}
}

void		declarations(t_env *env)
{
	env->camerax = 2 * env->x / (double)(env->w) - 1;
	env->rayposx = env->posx;
	env->rayposy = env->posy;
	env->raydirx = env->dirx + env->planex * env->camerax;
	env->raydiry = env->diry + env->planey * env->camerax;
	env->mapx = (int)(env->rayposx);
	env->mapy = (int)(env->rayposy);
	env->deltadistx = sqrt(1 + (env->raydiry * env->raydiry)
			/ (env->raydirx * env->raydirx));
	env->deltadisty = sqrt(1 + (env->raydirx * env->raydirx)
			/ (env->raydiry * env->raydiry));
	env->hit = 0;
}
