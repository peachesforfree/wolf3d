/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:59:39 by sbalcort          #+#    #+#             */
/*   Updated: 2017/10/02 14:29:50 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			create_map_cont(char **map)
{
	map[17] = ft_strdup("10000000000000000000001");
	map[18] = ft_strdup("10000000000000000000001");
	map[19] = ft_strdup("10000000000000000000001");
	map[20] = ft_strdup("10000000000000000000001");
	map[21] = ft_strdup("10000000000000000000001");
	map[22] = ft_strdup("10000000000000000000001");
	map[23] = ft_strdup("11111111111111111111111");
}

char			**create_map(void)
{
	char		**map;

	map = malloc(sizeof(char **) * 24);
	map[0] = ft_strdup("111111111111111111111111");
	map[1] = ft_strdup("100000000000000000000001");
	map[2] = ft_strdup("100000000000000000000001");
	map[3] = ft_strdup("100000000000000000000001");
	map[4] = ft_strdup("100000000000000000000001");
	map[5] = ft_strdup("100011111000021111000001");
	map[6] = ft_strdup("100010000000000001000001");
	map[7] = ft_strdup("100010000000000001000001");
	map[8] = ft_strdup("100010011111111001000001");
	map[9] = ft_strdup("100010010000001000000001");
	map[10] = ft_strdup("10001001000000100100001");
	map[11] = ft_strdup("10001001000000100100001");
	map[12] = ft_strdup("10001001000000100100001");
	map[13] = ft_strdup("10001001110011100100001");
	map[14] = ft_strdup("10001000000000000100001");
	map[15] = ft_strdup("10001000000000000100001");
	map[16] = ft_strdup("10001111111111111100001");
	map[17] = ft_strdup("10000000000000000000001");
	create_map_cont(map);
	return (map);
}

void			map(t_env *env)
{
	int			w;
	int			h;
	char		**test;
	int			i;

	test = create_map();
	h = 0;
	while (h < MAPWIDTH)
	{
		w = 0;
		while (w < MAPHEIGHT)
		{
			env->worldmap[h][w] = (test[h][w] - '0');
			w++;
		}
		h++;
	}
	i = -1;
	while (++i < 24)
		free(test[i]);
}

int				main(void)
{
	t_env	env;

	env.posx = 3;
	env.posy = 3;
	env.dirx = -1;
	env.diry = 0;
	env.planex = 0;
	env.planey = 0.66;
	env.w = WIN_X;
	env.h = WIN_Y;
	env.rotspeed = .08;
	env.movespeed = .5;
	map(&env);
	start_mlx(&env);
	mlx_key_hook(env.win, &key_hook, &env);
	mlx_do_key_autorepeaton(env.mlx);
	mlx_hook(env.win, 1, 0, &key_hook, &env);
	mlx_hook(env.win, 2, 0, &key_hook, &env);
	mlx_hook(env.win, 17, 0, &exit_hook, &env);
	raycaster(&env);
	mlx_loop(env.mlx);
	return (0);
}
