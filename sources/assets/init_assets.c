/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchel <hbouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:55:50 by hbouchel          #+#    #+#             */
/*   Updated: 2024/11/21 20:55:51 by hbouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_assets(t_map *map)
{
	int	i;

	i = 0;
	map->array[0].texture = mlx_load_png("assets/player.png");
	map->array[1].texture = mlx_load_png("assets/wall.png");
	map->array[2].texture = mlx_load_png("assets/floor.png");
	map->array[3].texture = mlx_load_png("assets/collectible.png");
	map->array[4].texture = mlx_load_png("assets/chest.png");
	while (i < 5)
	{
		map->array[i].image = mlx_texture_to_image(map->mlx,
				map->array[i].texture);
		mlx_delete_texture(map->array[i].texture);
		i++;
	}
}
