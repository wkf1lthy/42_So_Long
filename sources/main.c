/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchel <hbouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:55:12 by hbouchel          #+#    #+#             */
/*   Updated: 2024/11/21 20:55:13 by hbouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_all	all;

	handler_error(ac, av);
	init_var(&all);
	all.map.fd = open(av[1], O_RDONLY);
	if (all.map.fd < 0)
		exit_error("Error \nFichier inexistant", NULL);
	init_map(&all.map);
	all.map.mlx = mlx_init((all.map.width * TILE_SIZE), (all.map.height
				* TILE_SIZE), "so_long", true);
	init_assets(&all.map);
	display_assets(&all);
	check_map(&all.map);
	check_path(&all);
	mlx_loop_hook(all.map.mlx, check_key, &all);
	mlx_key_hook(all.map.mlx, event_listener, &all);
	mlx_loop(all.map.mlx);
	destroy_window(&all.map);
	free_map(all.map.matrix);
	return (0);
}

void	init_var(t_all *all)
{
	all->map.fd = 0;
	all->map.matrix = NULL;
	all->map.height = 0;
	all->map.width = 0;
	all->map.items_collected = 0;
	all->map.info.collectibles = 0;
	all->map.info.wall = 0;
	all->map.info.player = 0;
	all->map.info.floor = 0;
	all->map.info.exit = 0;
	all->player.nb_moove = 0;
	all->player.x = 0;
	all->player.y = 0;
}

void	check_key(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
}
