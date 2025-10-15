NAME = cub3d

SRCS = srcs/main.c srcs/parsing.c srcs/raycasting.c srcs/utils.c srcs/movement.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -lXext -lX11 -lm

INCLUDES = -I./includes

CC = gcc

RM = rm -f


all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re



