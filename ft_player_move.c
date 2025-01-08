/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 05:25:39 by almarti3          #+#    #+#             */
/*   Updated: 2024/12/22 05:25:42 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_data *vars)
{
	int		pos_x;
	int		pos_y;

	pos_x = vars->map.player.x;
	pos_y = vars->map.player.y;
	if (pos_x < 0 || vars->map.array[pos_y][pos_x - 1] == '1')
		return ;
	if (vars->map.array[pos_y][pos_x - 1] == 'C')
		vars->map.c--;
	else if (vars->map.array[pos_y][pos_x - 1] == 'E')
	{
		if (vars->map.c == 0)
			win_game(vars);
		else
			return ;
	}
	vars->map.array[pos_y][pos_x] = '0';
	vars->map.player.x = pos_x - 1;
	vars->map.array[pos_y][pos_x - 1] = 'P';
	vars->map.sprites.curr_player = vars->map.sprites.player_left;
	load_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->map.sprites.curr_player,
		(pos_x - 1) * PIXEL_SIZE, pos_y * PIXEL_SIZE);
	vars->map.num_moves++;
	ft_printf("Number of movements: %d\n", vars->map.num_moves);
}

void	move_right(t_data *vars)
{
	int		pos_x;
	int		pos_y;

	pos_x = vars->map.player.x;
	pos_y = vars->map.player.y;
	if (pos_x >= vars->map.x - 1 || vars->map.array[pos_y][pos_x + 1] == '1')
		return ;
	if (vars->map.array[pos_y][pos_x + 1] == 'C')
		vars->map.c--;
	else if (vars->map.array[pos_y][pos_x + 1] == 'E')
	{
		if (vars->map.c == 0)
			win_game(vars);
		else
			return ;
	}
	vars->map.array[pos_y][pos_x] = '0';
	vars->map.player.x = pos_x + 1;
	vars->map.array[pos_y][pos_x + 1] = 'P';
	vars->map.sprites.curr_player = vars->map.sprites.player_right;
	load_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->map.sprites.curr_player,
		(pos_x + 1) * PIXEL_SIZE, pos_y * PIXEL_SIZE);
	vars->map.num_moves++;
	ft_printf("Number of movements: %d\n", vars->map.num_moves);
}

void	move_up(t_data *vars)
{
	int		pos_x;
	int		pos_y;

	pos_x = vars->map.player.x;
	pos_y = vars->map.player.y;
	if (pos_y < 0 || vars->map.array[pos_y - 1][pos_x] == '1')
		return ;
	if (vars->map.array[pos_y - 1][pos_x] == 'C')
		vars->map.c--;
	else if (vars->map.array[pos_y - 1][pos_x] == 'E')
	{
		if (vars->map.c == 0)
			win_game(vars);
		else
			return ;
	}
	vars->map.array[pos_y][pos_x] = '0';
	vars->map.player.y = pos_y - 1;
	vars->map.array[pos_y - 1][pos_x] = 'P';
	load_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->map.sprites.curr_player,
		pos_x * PIXEL_SIZE, (pos_y - 1) * PIXEL_SIZE);
	vars->map.num_moves++;
	ft_printf("Number of movements: %d\n", vars->map.num_moves);
}

void	move_down(t_data *vars)
{
	int		pos_x;
	int		pos_y;

	pos_x = vars->map.player.x;
	pos_y = vars->map.player.y;
	if (pos_y >= vars->map.y - 1 || vars->map.array[pos_y + 1][pos_x] == '1')
		return ;
	if (vars->map.array[pos_y + 1][pos_x] == 'C')
		vars->map.c--;
	else if (vars->map.array[pos_y + 1][pos_x] == 'E')
	{
		if (vars->map.c == 0)
			win_game(vars);
		else
			return ;
	}
	vars->map.array[pos_y][pos_x] = '0';
	vars->map.player.y = pos_y + 1;
	vars->map.array[pos_y + 1][pos_x] = 'P';
	load_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->map.sprites.curr_player,
		pos_x * PIXEL_SIZE, (pos_y + 1) * PIXEL_SIZE);
	vars->map.num_moves++;
	ft_printf("Number of movements: %d\n", vars->map.num_moves);
}
