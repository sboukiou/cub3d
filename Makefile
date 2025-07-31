NAME=cub3d

SRC= get_next_line/get_next_line.c \
get_next_line/get_next_line_utils.c \
parser/pars_map.c \
parser/pars_utils1.c \
main.c \
parser/pars_utils2.c \
parser/pars_utils3.c \
parser/pars_utils4.c \
parser/pars_utils5.c \
parser/pars_utils6.c \
parser/creat_node.c \

CC= cc 
CFLAGS= -Wall -Wextra -Werror -g3 -fsanitize=address
LIBFT_DIR = libft
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 
LIBFT = $(LIBFT_DIR)/libft.a

OBJS= $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS)  $^ $(MLXFLAGS) -o $@ $(LIBFT)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)


re: fclean all
