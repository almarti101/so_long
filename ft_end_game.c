/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 02:06:00 by almarti3          #+#    #+#             */
/*   Updated: 2024/12/23 02:06:04 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_data *vars)
{
	mlx_destroy_image(vars->mlx, vars->map.sprites.player_left);
	mlx_destroy_image(vars->mlx, vars->map.sprites.player_right);
	mlx_destroy_image(vars->mlx, vars->map.sprites.wall);
	mlx_destroy_image(vars->mlx, vars->map.sprites.collec);
	mlx_destroy_image(vars->mlx, vars->map.sprites.back);
	mlx_destroy_image(vars->mlx, vars->map.sprites.exit);
	free_split(vars->map.array);
	free_split(vars->map.temp_map);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	win_game(t_data *vars)
{
	ft_printf("\n\n\n\033[0;32mYou win!\033[0m\n");
	ft_printf("It took you %d movements.\n\n\n", vars->map.num_moves);
	ft_exit(vars);
	exit(0);
}

void	clean_map_resources(t_data *vars)
{
	if (vars->map.line != NULL)
	{
		free(vars->map.line);
		vars->map.line = NULL;
	}
	if (vars->map.array != NULL)
	{
		free_split(vars->map.array);
		vars->map.array = NULL;
	}
	if (vars->map.temp_map != NULL)
	{
		free_split(vars->map.temp_map);
		vars->map.temp_map = NULL;
	}
}

void	exit_error(t_data *vars, int fd, char *str)
{
	ft_printf(str);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	if (fd != -1)
		close(fd);
	if (vars->map.y > 0)
		clean_map_resources(vars);
	exit(EXIT_FAILURE);
}
