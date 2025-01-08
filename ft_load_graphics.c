/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 05:25:22 by almarti3          #+#    #+#             */
/*   Updated: 2024/12/22 05:25:24 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprite_error(void)
{
	ft_printf("Unable to load sprites.\n");
	exit(1);
}

void	load_sprites(t_data vars, t_map *map)
{
	int	x;
	int	y;

	x = PIXEL_SIZE;
	y = PIXEL_SIZE;
	map->sprites.player_left = mlx_xpm_file_to_image(vars.mlx, P_LEFT, &x, &y);
	if (map->sprites.player_left == NULL)
		sprite_error();
	map->sprites.player_right = mlx_xpm_file_to_image(vars.mlx, P_RIGH, &x, &y);
	if (map->sprites.player_right == NULL)
		sprite_error();
	map->sprites.curr_player = map->sprites.player_right;
	map->sprites.back = mlx_xpm_file_to_image(vars.mlx, BACK, &x, &y);
	if (map->sprites.back == NULL)
		sprite_error();
	map->sprites.exit = mlx_xpm_file_to_image(vars.mlx, EXIT, &x, &y);
	if (map->sprites.exit == NULL)
		sprite_error();
	map->sprites.wall = mlx_xpm_file_to_image(vars.mlx, WALL, &x, &y);
	if (map->sprites.wall == NULL)
		sprite_error();
	map->sprites.collec = mlx_xpm_file_to_image(vars.mlx, COLLEC, &x, &y);
	if (map->sprites.collec == NULL)
		sprite_error();
}

void	identify_sprites(t_data *vars, t_map *map, int x, int y)
{
	if (map->array[y][x] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, map->sprites.back,
			x * PIXEL_SIZE, y * PIXEL_SIZE);
	else if (map->array[y][x] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, map->sprites.wall,
			x * PIXEL_SIZE, y * PIXEL_SIZE);
	else if (map->array[y][x] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, map->sprites.collec,
			x * PIXEL_SIZE, y * PIXEL_SIZE);
	else if (map->array[y][x] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, map->sprites.curr_player,
			x * PIXEL_SIZE, y * PIXEL_SIZE);
	else if (map->array[y][x] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, map->sprites.exit,
			x * PIXEL_SIZE, y * PIXEL_SIZE);
}

void	load_map(t_data *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < vars->map.y)
	{
		while (x < vars->map.x)
		{
			identify_sprites(vars, &vars->map, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
