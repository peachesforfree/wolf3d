/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 00:06:01 by sbalcort          #+#    #+#             */
/*   Updated: 2017/11/10 21:13:49 by gaguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		key_hook(int keycode, t_env *env)
{
	if (keycode == KEY_UP || keycode == KEY_W)
	{
		if (env->worldmap[(int)(env->posx + env->dirx * env->movespeed)]
				[(int)(env->posy)] == 0)
			env->posx += env->dirx * env->movespeed;
		if (env->worldmap[(int)(env->posx)][(int)(env->posy + env->diry *
					env->movespeed)] == 0)
			env->posy += env->diry * env->movespeed;
		raycaster(env);
	}
	if (keycode == KEY_DOWN || keycode == KEY_S)
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
	if (keycode == KEY_RIGHT || keycode == KEY_D)
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
	if (keycode == KEY_LEFT || keycode == KEY_A)
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
	if (keycode == 53){
		system("killall afplay");
		exit(0);
	}
}

int		exit_hook(void)
{
	system("killall afplay");
	exit(0);
}
