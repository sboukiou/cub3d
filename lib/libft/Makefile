NAME=../libft.a
CC=cc
CFLAGS= -c -Wall -Werror -Wextra
AR=ar -rcs
RM=rm -f
MV=mv
CD=cd
BUILD_DIR=../../build

GNL_SRC=./get_next_line/get_next_line_bonus.c\
		./get_next_line/get_next_line_utils_bonus.c 

MAN_SRCS=ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
		 ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
		 ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		 ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c\
		 ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
		 ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

LLISTS_SRCS=ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstdelone_bonus.c\
		   ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c\
		   ft_lstclear_bonus.c ft_lstmap_bonus.c

MAN_OBJS = $(MAN_SRCS:%.c=%.o)
GNL_OBJS = $(GNL_SRC:%.c=%.o)
LLISTS_OBJS = $(LLISTS_SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@
	$(MV) $@ $(BUILD_DIR)

$(NAME): $(MAN_OBJS) $(LLISTS_OBJS) $(GNL_OBJS)
	$(AR) $(NAME) $(BUILD_DIR)/*.o

clean: 
	$(RM) $(BUILD_DIR)/*.o

fclean: clean
	$(RM) $(NAME)


re: fclean all

.PHONY: all re clean fclean bonus
