/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 05:25:00 by almarti3          #+#    #+#             */
/*   Updated: 2024/12/22 05:25:02 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map_lines(t_data *vars, int fd)
{
	char	*temp;

	while (1)
	{
		vars->map.line = get_next_line(fd);
		if (!vars->map.line)
			break ;
		temp = vars->map.file;
		vars->map.file = ft_strjoin(vars->map.file, vars->map.line);
		free(temp);
		free(vars->map.line);
		if (!vars->map.file)
			exit_error(vars, fd, "Error\n");
		vars->map.y++;
	}
}

void	obtain_map(t_data *vars, int fd)
{
	char	buffer[2];
	ssize_t	bytes_read;

	buffer[0] = 0;
	buffer[1] = 0;
	bytes_read = read(fd, buffer, 1);
	if (bytes_read == -1)
		exit_error(vars, fd, "Error\n");
	if (bytes_read == 0)
		exit_error(vars, fd, "Error: empty map.\n");
	vars->map.file = ft_strdup(buffer);
	if (!vars->map.file || vars->map.file[0] == '\n')
		exit_error(vars, fd, "Error reading file, check map.\n");
	vars->map.y = 0;
	read_map_lines(vars, fd);
	vars->map.line = get_next_line(-1);
	vars->map.array = ft_split(vars->map.file, '\n');
	if (!vars->map.array)
		exit_error(vars, fd, "Error\n");
	vars->map.temp_map = ft_split(vars->map.file, '\n');
	free(vars->map.file);
	if (!vars->map.temp_map)
		exit_error(vars, fd, "Error\n");
	close(fd);
}

void	ft_is_map_valid(char *argv, t_data *vars)
{
	int	my_map_fd;

	my_map_fd = open(argv, O_RDONLY);
	if (my_map_fd == -1)
		exit_error(vars, -1, "Error reading the file.\n");
	obtain_map(vars, my_map_fd);
	check_size(vars);
	check_walls(vars);
	check_vals(vars);
	vars->map.c = vars->map.c_total;
	check_path(vars, vars->map.player.x, vars->map.player.y);
}
