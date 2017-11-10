/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 00:06:01 by sbalcort          #+#    #+#             */
/*   Updated: 2017/10/02 14:32:40 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_hook(int keycode, t_env *env)
{
	if (keycode == 126 || keycode == 13)
	{
		if (env->worldmap[(int)(env->posx + env->dirx * env->movespeed)]
				[(int)(env->posy)] == 0)
			env->posx += env->dirx * env->movespeed;
		if (env->worldmap[(int)(env->posx)][(int)(env->posy + env->diry *
					env->movespeed)] == 0)
			env->posy += env->diry * env->movespeed;
		raycaster(env);
	}
	if (keycode == 125 || keycode == 1)
	{
		if (env->worldmap[(int)(env->posx - env->dirx * env->movespeed)]
				[(int)(env->posy)] == 0)
			env->posx -= env->dirx * env->movespeed;
		if (env->worldmap[(int)(env->posx)][(int)(env->posy - env->diry *
			env->movespeed)] == 0)
			env->posy -= env->diry * env->movespeed;
		raycaster(env);
	}
	keycode_cont_cont(keycode, env);
	key_code_cont(keycode, env);
	raycaster(env);
	return (0);
}

void	keycode_cont_cont(int keycode, t_env *env)
{
	if (keycode == 124 || keycode == 2)
	{
		env->olddirx = env->dirx;
		env->dirx = env->dirx * cos(-(env->rotspeed)) -
			env->diry * sin(-(env->rotspeed));
		env->diry = env->olddirx * sin(-(env->rotspeed)) +
			env->diry * cos(-(env->rotspeed));
		env->oldplanex = env->planex;
		env->planex = env->planex * cos(-(env->rotspeed)) -
			env->planey * sin(-env->rotspeed);
		env->planey = env->oldplanex * sin(-(env->rotspeed)) +
			env->planey * cos(-env->rotspeed);
		raycaster(env);
	}
}

void	key_code_cont(int keycode, t_env *env)
{
	if (keycode == 123 || keycode == 0)
	{
		env->olddirx = env->dirx;
		env->dirx = env->dirx * cos(env->rotspeed) -
			env->diry * sin(env->rotspeed);
		env->diry = env->olddirx * sin(env->rotspeed) +
			env->diry * cos(env->rotspeed);
		env->oldplanex = env->planex;
		env->planex = env->planex * cos(env->rotspeed) -
			env->planey * sin(env->rotspeed);
		env->planey = env->oldplanex * sin(env->rotspeed) +
			env->planey * cos(env->rotspeed);
		raycaster(env);
	}
	if (keycode == 53)
		exit(0);
}

int		exit_hook(t_env *env)
{
	(void)env;
	exit(0);
}
