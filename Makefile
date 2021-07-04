NAME = so_long
OBJECTS = 
HEADER_FILES = 
ifdef DEBUG
CFLAGS = -g -Wall -Werror -Wextra
else
CFLAGS = -Wall -Werror -Wextra
endif

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) bonus -C ./libft
	$(CC) $(CFLAGS) $(OBJECTS) libft/libft.a -o push_swap

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

bonus: all

debug:
	$(MAKE) DEBUG=1 push_swap

.PHONY: all clean fclean re bonus debug
