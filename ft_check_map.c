/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 03:53:05 by almarti3          #+#    #+#             */
/*   Updated: 2024/12/23 03:53:07 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_args(int argc, char **argv, t_data *vars)
{
	int	i;

	i = 0;
	if (argc > 2)
		exit_error(vars, -1, "Error: Too many args.\n");
	if (argc < 2)
		exit_error(vars, -1, "Error: Map is missing.\n");
	if (!argv[1])
		exit_error(vars, -1, "Error: Map is NULL.\n");
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] != 'r')
		exit_error(vars, -1, "Error: map must be in '.ber' format.\n");
	if (argv[1][i - 2] != 'e')
		exit_error(vars, -1, "Error: map must be in '.ber' format.\n");
	if (argv[1][i - 3] != 'b')
		exit_error(vars, -1, "Error: map must be in '.ber' format.\n");
	if (argv[1][i - 4] != '.')
		exit_error(vars, -1, "Error: map must be in '.ber' format.\n");
	vars->map.y = -1;
}

void	check_size(t_data *vars)
{
	int	y;
	int	x;
	int	max;

	y = 0;
	x = 0;
	max = ft_strlen(vars->map.array[y]);
	while (y < vars->map.y)
	{
		x = ft_strlen(vars->map.array[y]);
		if (max != x)
			exit_error(vars, -1, "Error: All sizes must have the same size.\n");
		y++;
	}
	vars->map.e = 0;
	vars->map.c = 0;
	vars->map.c_total = 0;
	vars->map.x = max;
}

void	check_walls(t_data *vars)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (vars->map.array[y] != NULL)
		y++;
	vars->map.y = y;
	y = 0;
	while (x < vars->map.x)
	{
		if (vars->map.array[0][x] != '1' ||
				vars->map.array[vars->map.y - 1][x] != '1')
			exit_error(vars, -1, "Error: All limit squares must be walls.\n");
		x++;
	}
	y = 0;
	while (y < vars->map.y)
	{
		if (vars->map.array[y][0] != '1' ||
				vars->map.array[y][vars->map.x - 1] != '1')
			exit_error(vars, -1, "Error: All limit squares must be walls.\n");
		y++;
	}
}

void	process_cell(t_data *vars, int x, int y, int *p_counter)
{
	char	c;

	c = vars->map.array[y][x];
	if (c == 'C')
		vars->map.c_total++;
	else if (c == 'P')
	{
		vars->map.player.x = x;
		vars->map.player.y = y;
		(*p_counter)++;
	}
	else if (c == 'E')
		vars->map.e++;
	else if (c != '1' && c != '0')
		exit_error(vars, -1, "Map has a not allowed char.\n");
}

void	check_vals(t_data *vars)
{
	int	x;
	int	y;
	int	p_counter;

	y = 0;
	p_counter = 0;
	vars->map.c_total = 0;
	vars->map.e = 0;
	while (y < vars->map.y)
	{
		x = 0;
		while (x < vars->map.x)
		{
			process_cell(vars, x, y, &p_counter);
			x++;
		}
		y++;
	}
	if (vars->map.c_total < 1)
		exit_error(vars, -1,
			"Error: There must be at least one <Collectible>\n");
	if (p_counter != 1)
		exit_error(vars, -1, "Error: One starting position is needed (P)\n");
	if (vars->map.e != 1)
		exit_error(vars, -1, "Error: One exit is needed (E)\n");
}
