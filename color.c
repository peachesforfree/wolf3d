/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 23:09:21 by sbalcort          #+#    #+#             */
/*   Updated: 2017/10/01 23:09:27 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	color_selection(t_env *env)
{
	if (env->side == 1 && env->raydiry > 0)
		env->color = 0xFF0000;
	if (env->side == 1 && env->raydiry <= 0)
		env->color = 0xFF00FF;
	if (env->side == 0 && env->raydirx > 0)
		env->color = 0x00FF00;
	if (env->side == 0 && env->raydirx <= 0)
		env->color = 0x0000FF;
}
