/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 05:24:39 by almarti3          #+#    #+#             */
/*   Updated: 2024/12/22 05:24:43 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate_path(t_map *map, int x, int y)
{
	if (map->temp_map[y][x] == 'C')
	{
		map->temp_map[y][x] = '1';
		map->c--;
	}
	else if (map->temp_map[y][x] == 'E')
	{
		map->temp_map[y][x] = '1';
		map->e -= 1;
		return ;
	}
	else if (map->temp_map[y][x] == '0' || map->temp_map[y][x] == 'P')
		map->temp_map[y][x] = '1';
	else
		return ;
	calculate_path(map, x + 1, y);
	calculate_path(map, x - 1, y);
	calculate_path(map, x, y + 1);
	calculate_path(map, x, y - 1);
}

void	check_path(t_data *vars, int x, int y)
{
	calculate_path(&vars->map, x, y);
	if (vars->map.e != 0)
		exit_error(vars, -1, "Error: There is no valid path to the exit.\n");
	else if (vars->map.c > 0)
		exit_error(vars, -1,
			"Error: There is no valid path to all collectibles.\n");
	vars->map.c = vars->map.c_total;
}
