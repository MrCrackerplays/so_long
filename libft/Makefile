# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pdruart <pdruart@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/01 18:16:09 by pdruart       #+#    #+#                  #
#    Updated: 2020/11/25 11:00:46 by pdruart       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CHAR_CHECKS =  ft_isdigit.o ft_isalpha.o ft_isalnum.o ft_isascii.o ft_isprint.o
MEMS = ft_memset.o ft_memcmp.o ft_memchr.o ft_memmove.o ft_memccpy.o ft_memcpy.o
STR_MOD = ft_strlcpy.o ft_strlcat.o ft_tolower.o ft_toupper.o ft_bzero.o
STR_INFO = ft_strlen.o ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_strchr.o
STR_MAKE = ft_strdup.o ft_calloc.o ft_atoi.o
PART_ONE = $(CHAR_CHECKS) $(MEMS) $(STR_MOD) $(STR_INFO) $(STR_MAKE)
PAGE1 = ft_substr.o ft_strjoin.o ft_strtrim.o
PAGE2 = ft_split.o ft_itoa.o ft_strmapi.o
PUTS = ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o
PART_TWO = $(PAGE1) $(PAGE2) $(PUTS)
BONUS_ONE = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o
BONUS_TWO = ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o
BONUS_THREE = ft_lstiter.o ft_lstmap.o
PART_BONUS = $(BONUS_ONE) $(BONUS_TWO) $(BONUS_THREE)
HEADER_FILES = libft.h
CFLAGS = -Wall -Werror -Wextra

ifdef WITH_BONUS
OBJ_FILES = $(PART_ONE) $(PART_TWO) $(PART_BONUS)
else
OBJ_FILES = $(PART_ONE) $(PART_TWO)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_FILES) $(PART_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	$(MAKE) WITH_BONUS=1 all

so: $(OBJ_FILES)
	$(LINK.c) $(CFLAGS) -o libft.so -shared $(OBJ_FILES) $(PART_BONUS)

.PHONY: all clean fclean re bonus so
