NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=leak -fsanitize=address

LXFLAGS = -L minilibx-linux -lmlx -lm -lX11 -lXext -lpthread

HEADER = cub3d.h

SRC = cub3d.c \
cube3dutils.c \
get_next_line.c \
get_next_line_utils.c \
parse.c \
error.c \
move.c \
raycasting.c \
raycastingutils.c \
textures.c \
save.c \
sprites.c \
parseutils.c \
mapcheck.c \
parsemap.c \
tools.c \
tools2.c \
mapcheckutils.c \
structinit.c \
tools3.c \
tools4.c \



FIL = $(addprefix files/, $(SRC))

OBJ = $(FIL:.c=.o)

all: $(NAME)

$(NAME): ${OBJ}
	@echo "\n\e[32mCompiling MLX..."
	$(MAKE) -C minilibx-linux all
	@echo "\n\033[0;33mCompiling..."
	$(CC) ${CFLAGS} $(OBJ) $(LXFLAGS) -o $(NAME)
	@echo "\n\e[1;92mDONE \e[0m"

clean:
	@echo "\033[0;31mWipeout..."
	rm -rf $(OBJ)
	rm -f cub.bmp
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31mRemoving executable..."
	rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

.PHONY: all clean fclean re

norm:
	norminette $(FIL) inc/${HEADER}
