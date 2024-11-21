/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchel <hbouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:57:00 by hbouchel          #+#    #+#             */
/*   Updated: 2024/11/21 20:57:38 by hbouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 32

typedef struct s_assets
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
}					t_assets;

typedef struct s_info
{
	int				collectibles;
	int				wall;
	int				exit;
	int				floor;
	int				player;
}					t_info;

typedef struct s_player
{
	int				nb_moove;
	int				x;
	int				y;
}					t_player;

typedef struct s_map
{
	int				fd;
	char			**matrix;
	int				height;
	int				width;
	int				items_collected;
	t_info			info;

	t_assets		array[5];
	mlx_t			*mlx;
}					t_map;

typedef struct s_all
{
	t_map			map;
	t_player		player;
}					t_all;

// MAIN
void				init_var(t_all *all);
void				check_key(void *param);

// UTILS
void				exit_error(char *msg, char **tab);
void				handler_error(int ac, char **av);
void				free_map(char **tab);
void				destroy_window(t_map *map);
void				event_listener(mlx_key_data_t press, void *param);

// MAP
void				init_map(t_map *map);
void				init_assets(t_map *map);
void				display_assets(t_all *all);
void				display_perso(t_all *all, int x, int y);
void				display_wall(t_map *map, int x, int y);
void				display_floor(t_map *map, int x, int y);
void				display_collectibles(t_map *map, int x, int y);
void				display_chest(t_map *map, int x, int y);
void				delete_img_collected(t_all *all);
int					check_map(t_map *map);
int					check_path(t_all *all);

// PLAYER
void				select_key(mlx_key_data_t press, t_all *all);
void				moove_update(t_all *all);
void				right(t_all *all);
void				left(t_all *all);
void				up(t_all *all);
void				down(t_all *all);
int					check_move(t_map *map, int new_x, int new_y);

#endif
