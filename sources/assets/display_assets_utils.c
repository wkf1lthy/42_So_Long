/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_assets_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchel <hbouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:55:45 by hbouchel          #+#    #+#             */
/*   Updated: 2024/11/21 20:55:45 by hbouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_perso(t_all *all, int x, int y)
{
	int			image_x;
	int			image_y;
	mlx_image_t	*img;
	mlx_image_t	*img2;

	img = all->map.array[0].image;
	img2 = all->map.array[2].image;
	image_x = x * TILE_SIZE;
	image_y = y * TILE_SIZE;
	all->player.x = image_x;
	all->player.y = image_y;
	mlx_image_to_window(all->map.mlx, img2, image_x, image_y);
	mlx_image_to_window(all->map.mlx, img, image_x, image_y);
}

void	display_chest(t_map *map, int x, int y)
{
	int			image_x;
	int			image_y;
	mlx_image_t	*img;
	mlx_image_t	*img2;

	img = map->array[4].image;
	img2 = map->array[2].image;
	image_x = x * TILE_SIZE;
	image_y = y * TILE_SIZE;
	mlx_image_to_window(map->mlx, img2, image_x, image_y);
	mlx_image_to_window(map->mlx, img, image_x, image_y);
	map->info.exit++;
}

void	display_collectibles(t_map *map, int x, int y)
{
	int			image_x;
	int			image_y;
	mlx_image_t	*img;
	mlx_image_t	*img2;

	img = map->array[3].image;
	img2 = map->array[2].image;
	image_x = x * TILE_SIZE;
	image_y = y * TILE_SIZE;
	mlx_image_to_window(map->mlx, img2, image_x, image_y);
	mlx_image_to_window(map->mlx, img, image_x, image_y);
	map->info.collectibles++;
}

void	display_wall(t_map *map, int x, int y)
{
	int			image_x;
	int			image_y;
	mlx_image_t	*img;

	img = map->array[1].image;
	image_x = x * TILE_SIZE;
	image_y = y * TILE_SIZE;
	mlx_image_to_window(map->mlx, img, image_x, image_y);
	map->info.wall++;
}

void	display_floor(t_map *map, int x, int y)
{
	int			image_x;
	int			image_y;
	mlx_image_t	*img;

	img = map->array[2].image;
	image_x = x * TILE_SIZE;
	image_y = y * TILE_SIZE;
	mlx_image_to_window(map->mlx, img, image_x, image_y);
	map->info.floor++;
}
