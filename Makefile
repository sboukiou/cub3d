# Makefile to compile the project
# and produce the executable file -> cub3D


CC=cc
RM=rm -rf
CFLAGS=-Wall -Werror -Wextra -Ilib/mlx_linux -c
LFLAGS=-lX11 -lXext -lm -lz -L./lib/mlx_linux -lmlx
NAME=bin/cub3d
TEST_OUT_NAME=bin/test
BUILD_DIR=build
BIN_DIR=bin
MK=mkdir -p

SOURCE_FILES=$(wildcard *.c)
TESTS_SOURCE_FILES=$(wildcard tests/*.c)
TESTS_OBJ_FILES=$(TESTS_SOURCE_FILES:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(BUILD_DIR)/%.o : %.c
	$(MK) $(BUILD_DIR)/tests
	$(CC) $(CFLAGS) $< -o $@

$(TEST_OUT_NAME): $(TESTS_OBJ_FILES)
	$(MK) $(BIN_DIR)
	$(CC) $(TESTS_OBJ_FILES)  $(LFLAGS) -o $(TEST_OUT_NAME)

test: $(TEST_OUT_NAME)

clean:
	$(RM) $(BUILD_DIR)
	$(RM) $(BIN_DIR)

fclean: clean
	$(RM) $(NAME) $(TEST_OUT_NAME)

re: fclean all

.PHONY: all test clean fclean re
