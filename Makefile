NAME := so_long
OBJECTS := main.o
OBJECTS := $(addprefix obj/,$(OBJECTS))
HEADER_FILES := 
ifdef DEBUG
CFLAGS ?= -g -Wall -Werror -Wextra
else
CFLAGS ?= -Wall -Werror -Wextra
endif
ifdef LINUX
MINILIBX ?= mlx_linux
else
MINILIBX ?= mlx
endif

all: $(NAME)

$(NAME): minilibx $(OBJECTS)
	$(MAKE) bonus -C ./libft
	$(CC) $(CFLAGS) -L$(MINILIBX) -lmlx -L/usr/lib -I$(MINILIBX) -lXext -lX11 -lm -lz $(OBJECTS) libft/libft.a -o push_swap

obj/%.o: src/%.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -I/usr/include -I$(MINILIBX) -O3 -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./$(MINILIBX)
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

minilibx:
	$(MAKE) -C ./$(MINILIBX)

bonus: all

debug:
	$(MAKE) DEBUG=1

.PHONY: all clean fclean re minilibx bonus debug
