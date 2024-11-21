/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchel <hbouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:55:36 by hbouchel          #+#    #+#             */
/*   Updated: 2024/11/21 20:55:37 by hbouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_content(t_map *map)
{
	if ((map->info.exit > 1 || map->info.exit == 0) || (map->info.player > 1
			|| map->info.player == 0) || map->info.collectibles < 1)
	{
		destroy_window(map);
		exit_error("Error \nWrong number of Hero/Collectible/Exit",
			map->matrix);
	}
	return (1);
}

int	check_shape(t_map *map)
{
	char	**tab;
	int		i;
	int		j;
	int		max;

	tab = map->matrix;
	i = 0;
	j = 0;
	while (tab[i][j])
		j++;
	max = j;
	i++;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] && tab[i][j] != ' ')
			j++;
		if (j != max)
		{
			destroy_window(map);
			exit_error("Error \nShape not compliant", tab);
		}
		i++;
	}
	return (1);
}

int	is_closed(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
	{
		if (map->matrix[i][0] != '1' || map->matrix[i][map->width - 1] != '1')
		{
			destroy_window(map);
			exit_error("Error \nMap isn't close", map->matrix);
		}
	}
	i = -1;
	while (++i < map->width)
	{
		if (map->matrix[0][i] != '1' || map->matrix[map->height - 1][i] != '1')
		{
			destroy_window(map);
			exit_error("Error \nMap isn't close", map->matrix);
		}
	}
	return (1);
}

int	check_map(t_map *map)
{
	if (check_shape(map) && is_closed(map) && check_content(map))
		return (1);
	free_map(map->matrix);
	return (0);
}
