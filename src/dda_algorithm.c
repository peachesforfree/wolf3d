/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 23:11:24 by sbalcort          #+#    #+#             */
/*   Updated: 2017/11/12 17:46:42 by gaguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void		dda_algorithm(t_env *env)
{
	while (env->hit == 0)
	{
		if (env->sidedistx < env->sidedisty)
		{
			env->sidedistx += env->deltadistx;
			env->mapx += env->stepx;
			env->side = 0;
		}
		else
		{
			env->sidedisty += env->deltadisty;
			env->mapy += env->stepy;
			env->side = 1;
		}
		if (env->worldmap[env->mapx][env->mapy] > 0)
			env->hit = 1;
	}
}

void		projection(t_env *env)
{
	if (env->side == 0)
		env->perpwalldist = fabs((env->mapx - env->rayposx +
					(1 - env->stepx) / 2) / env->raydirx);
	else
		env->perpwalldist = fabs((env->mapy - env->rayposy +
					(1 - env->stepy) / 2) / env->raydiry);
	env->lineheight = abs((int)(env->h / env->perpwalldist));
	env->drawstart = -(env->lineheight) / 2 + env->h / 2;
	env->drawend = env->lineheight / 2 + env->h / 2;
	if (env->drawstart < 0)
		env->drawstart = 0;
	if (env->drawend >= env->h)
		env->drawend = env->h - 1;
}
