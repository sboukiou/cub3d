# Makefile to compile the project
# and produce the executable file -> cub3D


CC=cc
CFLAGS=-Wall -Werror -Wextra -Imlx_linux
LFLAGS=-$(CFLAGS) -lX11 -lm -lz
NAME=cub3d

SOURCE_FILES=(wildcard ./*.c)
