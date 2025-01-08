/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:04:20 by almarti3          #+#    #+#             */
/*   Updated: 2024/12/23 00:04:22 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux-master/mlx.h"
# include "utils/libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define PIXEL_SIZE 64

# define P_LEFT "textures/Player_left.xpm"
# define P_RIGH "textures/Player_right.xpm"
# define BACK "textures/Empty.xpm"
# define EXIT "textures/Exit.xpm"
# define WALL "textures/Wall.xpm"
# define COLLEC "textures/Collec.xpm"

typedef struct player
{
	int	x;
	int	y;
}	t_player;

typedef struct sprites
{
	void	*curr_player;
	void	*player_left;
	void	*player_right;
	void	*collec;
	void	*exit;
	void	*wall;
	void	*back;
}	t_sprites;

typedef struct map
{
	int			x;
	int			y;
	int			c;
	int			c_total;
	int			e;
	int			p;
	int			num_moves;
	char		*line;
	char		*file;
	char		**array;
	char		**temp_map;
	t_player	player;
	t_sprites	sprites;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	map;
}	t_data;

void	ft_is_map_valid(char *argv, t_data *vars);
void	ft_check_args(int argc, char **argv, t_data *vars);
void	check_path(t_data *vars, int x, int y);
void	load_sprites(t_data vars, t_map *map);
void	load_map(t_data *vars);
void	win_game(t_data *vars);

void	move_left(t_data *vars);
void	move_right(t_data *vars);
void	move_up(t_data *vars);
void	move_down(t_data *vars);

int		ft_exit(t_data *vars);
void	free_split(char **split);
void	exit_error(t_data *vars, int fd, char *str);
void	clean_map_resources(t_data *vars);
void	check_vals(t_data *vars);
void	check_walls(t_data *vars);
void	check_size(t_data *vars);

#endif
