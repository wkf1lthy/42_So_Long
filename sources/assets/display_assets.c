/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchel <hbouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:55:47 by hbouchel          #+#    #+#             */
/*   Updated: 2024/11/21 20:55:48 by hbouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_select(t_map *map, int x, int y)
{
	if (map->matrix[y][x] != '\0')
	{
		if (map->matrix[y][x] == '1')
			display_wall(map, x, y);
		if (map->matrix[y][x] == '0')
			display_floor(map, x, y);
		if (map->matrix[y][x] == 'C')
			display_collectibles(map, x, y);
		if (map->matrix[y][x] == 'E')
			display_chest(map, x, y);
	}
}

void	display_assets(t_all *all)
{
	int	x;
	int	y;
	int	check_x;
	int	check_y;

	check_x = -1;
	check_y = -1;
	y = -1;
	while (++y < all->map.height)
	{
		x = 0;
		while (all->map.matrix[y][x])
		{
			image_select(&all->map, x, y);
			if (all->map.matrix[y][x] == 'P')
			{
				check_x = x;
				check_y = y;
				all->map.info.player++;
			}
			x++;
		}
	}
	if (check_x != -1 && check_y != -1)
		display_perso(all, check_x, check_y);
}

void	delete_img_collected(t_all *all)
{
	int	i;
	int	x;
	int	y;

	x = all->player.x;
	y = all->player.y;
	i = 0;
	while (i < all->map.info.collectibles)
	{
		if (all->map.array[3].image->instances[i].x == x)
		{
			if (all->map.array[3].image->instances[i].y == y)
				all->map.array[3].image->instances[i].enabled = false;
		}
		i++;
	}
}
