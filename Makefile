# Makefile to compile the project
# and produce the executable file -> cub3D


CC=cc
RM=rm -rf
CFLAGS=-Wall -Werror -Wextra -Ilib/mlx_linux -D DEBUG_MODE=0 -c
LFLAGS=-g3 -L./build -lmlx -lft -lX11 -lXext -lm -lz
NAME=bin/cub3D
BUILD_DIR=build
BIN_DIR=bin
MK=mkdir -p
LIBFT=lib/libft/libft.a

$(BIN_DIR):
	$(MK) $@

$(BUILD_DIR):
	$(MK) $@

SOURCE_FILES=$(wildcard  src/*.c *.c src/parser/*.c)
OBJ_FILES=$(SOURCE_FILES:%.c=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	@$(MK) $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT):
	$(MK) $(BUILD_DIR)
	make -C ./lib/libft/


$(NAME): $(LIBFT) $(OBJ_FILES) | $(BIN_DIR)
	@$(CC) $(OBJ_FILES)  $(LFLAGS) -o $(NAME)



clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(BIN_DIR)

bonus: all

re: fclean all

.PHONY: all test clean fclean re bonus
