/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 05:25:51 by almarti3          #+#    #+#             */
/*   Updated: 2024/12/22 05:25:53 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hook_input(int keycode, t_data *vars)
{
	if (keycode == XK_Escape)
	{
		ft_exit(vars);
		exit(0);
	}
	else if (keycode == XK_a || keycode == XK_Left)
		move_left(vars);
	else if (keycode == XK_d || keycode == XK_Right)
		move_right(vars);
	else if (keycode == XK_w || keycode == XK_Up)
		move_up(vars);
	else if (keycode == XK_s || keycode == XK_Down)
		move_down(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
	{
		ft_printf("Error: mlx didnt initiate correctly.\n");
		return (1);
	}
	ft_check_args(argc, argv, &vars);
	ft_is_map_valid(argv[1], &vars);
	load_sprites(vars, &vars.map);
	vars.win = mlx_new_window(vars.mlx, PIXEL_SIZE * vars.map.x,
			PIXEL_SIZE * vars.map.y, "My window");
	load_map(&vars);
	mlx_key_hook(vars.win, hook_input, &vars);
	mlx_hook(vars.win, DestroyNotify, ButtonPressMask, ft_exit, &vars);
	mlx_loop(vars.mlx);
}
