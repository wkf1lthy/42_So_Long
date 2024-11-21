/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchel <hbouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:55:39 by hbouchel          #+#    #+#             */
/*   Updated: 2024/11/21 20:56:46 by hbouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_free_tab(char **tab, int index)
{
	if (index == -1)
	{
		while (tab[++index])
			free(tab[index]);
		index = -1;
	}
	while (index >= 0)
	{
		if (tab[index])
			free(tab[index]);
		index--;
	}
	if (tab)
		free(tab);
	return (NULL);
}

char	**duplicate_map(char **map)
{
	int		size;
	char	**new;
	int		i;

	size = 0;
	while (map[size])
		size++;
	new = ft_calloc(size + 1, sizeof(char *));
	if (!new)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		new[i] = ft_strdup(map[i]);
		if (!new[i])
			return (ft_free_tab(new, -1));
	}
	return (new);
}

int	flood_fill(char **map, int x, int y, int *requirements)
{
	if (map[y][x] == '1' || map[y][x] == 'M' || map[y][x] == 'D')
		return (0);
	else if (map[y][x] == 'C')
		requirements[1]++;
	else if (map[y][x] == 'E')
		requirements[0] = 1;
	map[y][x] = '1';
	flood_fill(map, x + 1, y, requirements);
	flood_fill(map, x - 1, y, requirements);
	flood_fill(map, x, y + 1, requirements);
	flood_fill(map, x, y - 1, requirements);
	return (0);
}

int	check_path(t_all *all)
{
	char	**flood_map;
	int		x;
	int		y;
	int		requirements[2];

	flood_map = duplicate_map(all->map.matrix);
	if (!flood_map)
		exit_error("Error \nCloning map error", NULL);
	x = all->player.x / TILE_SIZE;
	y = all->player.y / TILE_SIZE;
	requirements[0] = 0;
	requirements[1] = 0;
	flood_fill(flood_map, x, y, requirements);
	ft_free_tab(flood_map, -1);
	if (!requirements[0])
	{
		destroy_window(&all->map);
		exit_error("Error \nNo game issue found", all->map.matrix);
	}
	if (requirements[1] != all->map.info.collectibles)
	{
		destroy_window(&all->map);
		exit_error("Error\nNo path to all collectibles", all->map.matrix);
	}
	return (0);
}
