# Makefile to compile the project
# and produce the executable file -> cub3D


CC=cc
RM=rm -rf
CFLAGS=-Wall -Werror -Wextra -Ilib/mlx_linux -D DEBUG_MODE=0 -c
LFLAGS=-g3 -L./build -lmlx -lft -lX11 -lXext -lm -lz
NAME=bin/cub3D
TEST_OUT_NAME=bin/test
BUILD_DIR=build
BIN_DIR=bin
MK=mkdir -p
LIBMLX=lib/mlx_linux/libmlx.a
LIBFT=lib/libft/libft.a

all: $(NAME)

$(LIBFT):
	$(MK) $(BUILD_DIR)
	make -C ./lib/libft/

SOURCE_FILES=$(wildcard  src/*.c *.c src/parser/*.c)
OBJ_FILES=$(SOURCE_FILES:%.c=$(BUILD_DIR)/%.o)
TESTS_SOURCE_FILES=$(wildcard tests/*.c)
TESTS_OBJ_FILES=$(TESTS_SOURCE_FILES:%.c=$(BUILD_DIR)/%.o)

$(NAME): $(LIBFT) $(OBJ_FILES)
	$(MK) $(BIN_DIR)
	$(CC) $(BUILD_DIR)/*.o  $(LFLAGS) -o $(NAME)


$(BUILD_DIR)/%.o : %.c
	$(MK) $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $(BUILD_DIR)/$(notdir $@)

$(TEST_OUT_NAME): $(TESTS_OBJ_FILES)
	$(MK) $(BIN_DIR)
	$(CC) $(TESTS_OBJ_FILES)  $(LFLAGS) -o $(TEST_OUT_NAME)

test: $(TEST_OUT_NAME)

clean:
	$(RM) $(BUILD_DIR)/*.o

fclean: clean
	$(RM) $(BIN_DIR)

re: fclean all

.PHONY: all test clean fclean re
