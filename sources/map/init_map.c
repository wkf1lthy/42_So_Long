/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchel <hbouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:55:42 by hbouchel          #+#    #+#             */
/*   Updated: 2024/11/21 20:55:42 by hbouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

void	init_map(t_map *map)
{
	char	*gnl;
	int		i;

	i = 0;
	gnl = get_next_line(map->fd);
	if (!gnl)
		exit_error("Error \nMap is empty", NULL);
	map->matrix = ft_calloc(1, sizeof(char *) * 9999);
	map->width = len_map(gnl);
	while (gnl)
	{
		map->matrix[i] = gnl;
		gnl = get_next_line(map->fd);
		i++;
	}
	map->matrix[i] = NULL;
	map->height = i;
}
