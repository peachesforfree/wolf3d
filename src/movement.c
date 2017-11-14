/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 00:06:01 by sbalcort          #+#    #+#             */
/*   Updated: 2017/11/13 20:13:12 by gaguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

/*
**	Control Calls and Exit
*/

int		key_hook(int keycode, t_env *env)
{
	(keycode == KEY_LEFTSHIFT) ? run(env) : (0);
	(keycode == KEY_UP || keycode == KEY_W) ? up(env) : (0);
	(keycode == KEY_DOWN || keycode == KEY_S) ? down(env) : (0);
	(keycode == KEY_LEFT || keycode == KEY_A) ? left(env) : (0);
	(keycode == KEY_RIGHT || keycode == KEY_D) ? right(env) : (0);
	if (keycode == 53)
	{
		system("killall afplay");
		exit(0);
	}
	raycaster(env);
	help_text(env);
	return (0);
}

int		exit_hook(void)
{
	system("killall afplay");
	exit(0);
}
