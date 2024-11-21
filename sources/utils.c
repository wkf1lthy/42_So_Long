/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchel <hbouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:55:15 by hbouchel          #+#    #+#             */
/*   Updated: 2024/11/21 20:55:21 by hbouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *msg, char **tab)
{
	if (tab != NULL)
		free_map(tab);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

void	free_map(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	handler_error(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 2)
		exit_error("Error \nArgs Problem", NULL);
	while (av[1][i])
		i++;
	if (av[1][i - 1] != 'r' || av[1][i - 2] != 'e' || av[1][i - 3] != 'b'
		|| av[1][i - 4] != '.')
		exit_error("Error \nWrong extension for map", NULL);
}

void	event_listener(mlx_key_data_t press, void *param)
{
	t_all	*all;

	all = (t_all *)param;
	select_key(press, all);
	delete_img_collected(all);
}

void	destroy_window(t_map *map)
{
	mlx_terminate(map->mlx);
}
