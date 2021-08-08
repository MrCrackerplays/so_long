NAME := so_long
UNAME = $(shell uname -s)

ifdef DEBUG
CFLAGS ?= -g -Wall -Werror -Wextra
else
CFLAGS ?= -Wall -Werror -Wextra
endif
OBJECTS := main.o
OBJECTS := $(addprefix obj/,$(OBJECTS))
HEADER_FILES := 

ifeq ($(UNAME), Linux)
MINILIBX ?= mlx_linux
MLX_FLAGS = -L$(MINILIBX) -lmlx_linux -lXext -lX11 -lm -lz -L/usr/lib -I$(MINILIBX)
OBJ_FLAGS = -I/usr/include -I$(MINILIBX) -O3
else
MINILIBX ?= mlx
MLX_FLAGS = -L$(MINILIBX) -lmlx -framework OpenGL -framework Appkit
OBJ_FLAGS = -I$(MINILIBX)
endif

all: $(NAME)

$(NAME): minilibx $(OBJECTS)
	$(MAKE) bonus -C ./libft
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS) libft/libft.a -o $(NAME)

obj/%.o: src/%.c $(HEADER_FILES)
	$(CC) $(CFLAGS) $(OBJ_FLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./$(MINILIBX)
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f libmlx.dylib
	rm -f $(NAME)

re: fclean all

minilibx:
	$(MAKE) -C ./$(MINILIBX)
	cp $(MINILIBX)/libmlx.dylib libmlx.dylib

bonus: all

debug:
	$(MAKE) DEBUG=1

.PHONY: all clean fclean re minilibx bonus debug
