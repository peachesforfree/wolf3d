/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movefun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguirre <gaguirre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 22:30:14 by gaguirre          #+#    #+#             */
/*   Updated: 2017/11/13 19:41:36 by gaguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

/*
**	Controls
*/

void     up(t_env *env)
{
  if (env->worldmap[(int)(env->posx + env->dirx * env->movespeed)]
      [(int)(env->posy)] == 0)
    env->posx += env->dirx * env->movespeed;
  if (env->worldmap[(int)(env->posx)][(int)(env->posy + env->diry *
        env->movespeed)] == 0)
    env->posy += env->diry * env->movespeed;
  raycaster(env);
}

void     down(t_env *env)
{
  if (env->worldmap[(int)(env->posx - env->dirx * env->movespeed)]
      [(int)(env->posy)] == 0)
    env->posx -= env->dirx * env->movespeed;
  if (env->worldmap[(int)(env->posx)][(int)(env->posy - env->diry *
    env->movespeed)] == 0)
    env->posy -= env->diry * env->movespeed;
  raycaster(env);
}

void     right(t_env *env)
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

void     left(t_env *env)
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

void    run(t_env *env)
{
  if (env->run == 1)
  {
    env->run = 0;
    env->movespeed = 1.0;
  }
  else if (env->run == 0)
  {
    env->run = 1;
    env->movespeed = 0.5;
  }
}
