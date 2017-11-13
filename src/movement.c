/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 00:06:01 by sbalcort          #+#    #+#             */
/*   Updated: 2017/11/12 17:30:20 by gaguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		key_hook(int keycode, t_env *env)
{
	(keycode == KEY_LEFTSHIFT) ? run(env) : (0);
	(keycode == KEY_UP || keycode == KEY_W) ? up(env) : (0);
	(keycode == KEY_DOWN || keycode == KEY_S) ? down(env) : (0);
	key_code_cont(keycode, env);
	raycaster(env);
	help_text(env);
	return (0);
}

void	key_code_cont(int keycode, t_env *env)
{
	(keycode == KEY_LEFT || keycode == KEY_A) ? left(env) : (0);
	(keycode == KEY_RIGHT || keycode == KEY_D) ? right(env) : (0);

	if (keycode == 53)
	{
		system("killall afplay");
		exit(0);
	}
}

int		exit_hook(void)
{
	system("killall afplay");
	exit(0);
}
