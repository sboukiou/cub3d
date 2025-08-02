# Makefile to compile the project
# and produce the executable file -> cub3D

NAME=$(BINDIR)/cub3d

SRC= parser/fill_map.c parser/parse_map.c parser/parse_colors.c \
	parser/parse_lines.c parser/parse_utils.c parser/track_textures.c\
	main.c parser/creat_node.c

BINDIR= bin/
CC= cc 
CFLAGS= -Wall -Wextra -Werror 
LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJS= $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS)  $^ -o $@ $(LIBFT)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)


re: fclean all