CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror
LDFLAGS = -Lutils/libft -lft -L. -Lminilibx-linux-master -lmlx -L/usr/lib -lXext -lX11 -lm -lz

EXEC = so_long

SRCS = so_long.c ft_is_valid.c ft_check_path.c ft_load_graphics.c ft_player_move.c ft_end_game.c ft_check_map.c

OBJECTS = $(SRCS:.c=.o)

MLX_PATH = minilibx-linux-master/
MLX_LIB = $(MLX_PATH)/libmlx.a

all: $(MLX_LIB) $(EXEC)

$(MLX_LIB):
	@make -C $(MLX_PATH)

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	@make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
