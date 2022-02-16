NAME = cub3D
GCC = cc
LIBFT = ./libft/libft.a
LIB_BINARY = -L ./libft -lft 
CFLAGS = -Wall -Werror -Wextra -Os

SRCS = main.c \
		_init.c \
		_malloc_manager.c \
		start_game.c \
		hooks.c \
		_read_map.c \
		errors.c \
		_check_map1.c \
		_check_sides.c \
		_parse_utils1.c \
		_parse_utils2.c \
		raycast.c \
		_get_floor_ceiling.c \
		events.c \
		_raycasting.c \
		_get_oriented.c \
		_check_map2.c \

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) cub3d.h Makefile
	$(CC) $(OBJS) $(LIB_BINARY) -lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	make -C ./libft/

clean:
	$(RM) $(OBJS)
	make -C ./minilibx_opengl/ clean
	make -C ./libft/ clean

fclean: clean
	$(RM) $(NAME)
	make -C ./libft/ fclean

re: fclean all

.PHONY: all clean fclean re