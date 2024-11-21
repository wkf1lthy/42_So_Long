/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchel <hbouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:55:32 by hbouchel          #+#    #+#             */
/*   Updated: 2024/11/21 20:55:33 by hbouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	select_key(mlx_key_data_t press, t_all *all)
{
	if (press.key == MLX_KEY_D && press.action == MLX_RELEASE)
		right(all);
	else if (press.key == MLX_KEY_A && press.action == MLX_RELEASE)
		left(all);
	else if (press.key == MLX_KEY_W && press.action == MLX_RELEASE)
		up(all);
	else if (press.key == MLX_KEY_S && press.action == MLX_RELEASE)
		down(all);
}

void	right(t_all *all)
{
	int	x;

	x = all->player.x + 32;
	if (check_move(&all->map, x, all->player.y))
	{
		all->player.x = x;
		all->map.array[0].image->instances[0].x = x;
		all->map.array[0].image->instances[0].y = all->player.y;
		moove_update(all);
	}
}

void	left(t_all *all)
{
	int	x;

	x = all->player.x - 32;
	if (check_move(&all->map, x, all->player.y))
	{
		all->player.x = x;
		all->map.array[0].image->instances[0].x = x;
		all->map.array[0].image->instances[0].y = all->player.y;
		moove_update(all);
	}
}

void	up(t_all *all)
{
	int	y;

	y = all->player.y - 32;
	if (check_move(&all->map, all->player.x, y))
	{
		all->player.y = y;
		all->map.array[0].image->instances[0].x = all->player.x;
		all->map.array[0].image->instances[0].y = y;
		moove_update(all);
	}
}

void	down(t_all *all)
{
	int	y;

	y = all->player.y + 32;
	if (check_move(&all->map, all->player.x, y))
	{
		all->player.y = y;
		all->map.array[0].image->instances[0].x = all->player.x;
		all->map.array[0].image->instances[0].y = y;
		moove_update(all);
	}
}
