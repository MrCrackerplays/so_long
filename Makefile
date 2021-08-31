NAME := so_long
UNAME := $(shell uname -s)
SPRITE_WIDTH ?= 16
SPRITE_HEIGHT ?= 16

ifdef DEBUG
CFLAGS ?= -g -Wall -Werror -Wextra -D SPRITE_WIDTH=$(SPRITE_WIDTH) \
	-D SPRITE_HEIGHT=$(SPRITE_HEIGHT)
else
CFLAGS ?= -Wall -Werror -Wextra -D SPRITE_WIDTH=$(SPRITE_WIDTH) \
	-D SPRITE_HEIGHT=$(SPRITE_HEIGHT)
endif
OBJECTS := so_long.o game.o shutdown.o map.o game_setup.o controls.o assets.o \
	canvas_management.o scaling.o sl_rendering.o sl_rendering_map.o \
	sl_random.o get_next_line_bonus.o get_next_line_utils_bonus.o
OBJECTS := $(addprefix obj/,$(OBJECTS))
HEADER_FILES := so_long.h game.h shutdown.h map.h player.h controls.h assets.h \
	canvas_management.h scaling.h sl_rendering.h sl_random.h \
	get_next_line_bonus.h
HEADER_FILES := $(addprefix headers/,$(HEADER_FILES))

ifeq ($(UNAME), Linux)
MINILIBX_FOLDER ?= mlx_linux
MINILIBX_FILE ?= libmlx.a
MLX_FLAGS = -L$(MINILIBX_FOLDER) -lmlx -lXext -lX11 -L/usr/lib \
	-I$(MINILIBX_FOLDER) -lm -lz
OBJ_FLAGS = -I$(MINILIBX_FOLDER) -I/usr/include -O3 -D LINUX=1
else
MINILIBX_FOLDER ?= mlx
MINILIBX_FILE ?= libmlx.dylib
MLX_FLAGS = -L$(MINILIBX_FOLDER) -lmlx -framework OpenGL -framework Appkit
OBJ_FLAGS = -I$(MINILIBX_FOLDER)
endif
CC = clang

all: $(NAME)

$(NAME): minilibx_file $(OBJECTS)
	$(MAKE) bonus -C ./libft
	@echo "[so_long] compiling so_long"
	@$(CC) $(CFLAGS) $(OBJECTS) libft/libft.a -o $(NAME) $(MLX_FLAGS)

obj/%.o: src/%.c $(HEADER_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FLAGS) -c $< -o $@

minilibx_file:
	@echo "[so_long] compiling mlx"
	$(MAKE) -C ./$(MINILIBX_FOLDER)
	@cp $(MINILIBX_FOLDER)/$(MINILIBX_FILE) $(MINILIBX_FILE)
	@cp $(MINILIBX_FOLDER)/$(MINILIBX_FILE) minilibx_file

clean:
	@echo "[so_long] cleaning so_long"
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./$(MINILIBX_FOLDER)
	@rm -f minilibx_file
	@rm -f $(OBJECTS)

fclean: clean
	@echo "[so_long] fully cleaning so_long"
	$(MAKE) fclean -C ./libft
	@rm -f $(MINILIBX_FILE)
	@rm -f $(NAME)

re: fclean all

bonus: all

run: all
	@echo "[so_long] running so_long"
	./$(NAME) maps/normal.ber

debug:
	$(MAKE) DEBUG=1

.PHONY: all clean fclean re bonus run debug
