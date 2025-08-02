CC=cc
CFLAGS= -c -Wall -Werror -Wextra
AR=ar -rcs
RM=rm -f
BUILD_DIR=../../build
NAME=$(BUILD_DIR)/libft.a

GNL_SRC=get_next_line.c get_next_line_utils.c 

MAN_SRCS=ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
		 ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
		 ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		 ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c\
		 ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
		 ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strcmp.c

LLISTS_SRCS=ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstdelone_bonus.c\
		   ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c\
		   ft_lstclear_bonus.c ft_lstmap_bonus.c

MAN_OBJS = $(MAN_SRCS:%.c=$(BUILD_DIR)/%.o)
GNL_OBJS = $(GNL_SRC:%.c=$(BUILD_DIR)/%.o)
LLISTS_OBJS = $(LLISTS_SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(MAN_OBJS) $(LLISTS_OBJS) $(GNL_OBJS)
	$(AR) $(NAME) $(MAN_OBJS) $(LLISTS_OBJS) $(GNL_OBJS)

clean: 
	$(RM) $(MAN_OBJS) $(GNL_OBJS) $(LLISTS_OBJS)

fclean: clean
	$(RM) $(NAME)


re: fclean all

.PHONY: all re clean fclean bonus
