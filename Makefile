NAME = cub3d

# Libft
LIBFT = libft.a
LIBFT_DIR = libft
LIBFT_PREFX = $(LIBFT_DIR)/$(LIBFT)

# Cube
CUBE_DIR = srcs/cube/
CUBE_SRCS = main.c
CUBE_PREFIX = $(addprefix $(CUBE_DIR), $(CUBE_SRCS))
CUBE_OBJS = $(CUBE_PREFIX:.c=.o)

# Graphics
GRAPHICS_DIR = srcs/graphics/
GRAPHICS_SRCS = raycasting.c \
	img_utils.c \
	render.c \
	texture.c 
GRAPHICS_PREFIX = $(addprefix $(GRAPHICS_DIR), $(GRAPHICS_SRCS))
GRAPHICS_OBJS = $(GRAPHICS_PREFIX:.c=.o)

# Movement

MOVEMENT_DIR = srcs/movement/
MOVEMENT_SRCS = camera_movement.c\
	player_movement.c

MOVEMENT_PREFIX = $(addprefix $(MOVEMENT_DIR), $(MOVEMENT_SRCS))
MOVEMENT_OBJS = $(MOVEMENT_PREFIX:.c=.o)



# Init

INIT_DIR = srcs/init/
INIT_SRCS = hook_utils.c\
	init.c\
	player_location.c

INIT_PREFIX = $(addprefix $(INIT_DIR), $(INIT_SRCS))
INIT_OBJS = $(INIT_PREFIX:.c=.o)




# Flags, includes and compiler
CFLAGS = -Wall -Wextra -Werror -g
MLX_DIR = minilibx-linux/
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
INCLUDES = -I./includes
CC = cc
RM = rm -f

# Colors for Makefile output
RED    = \033[0;31m
GREEN  = \033[0;32m
YELLOW = \033[0;33m
BLUE   = \033[0;34m
RESET  = \033[0m

all: $(NAME)

$(NAME): $(CUBE_OBJS) $(GRAPHICS_OBJS) $(LIBFT_PREFX) $(MOVEMENT_OBJS) $(INIT_OBJS)
	@echo "\n\n$(BLUE)Linking object files and libraries...$(RESET)\n\n"
	$(CC) $(CFLAGS) -o $(NAME) $(CUBE_OBJS) $(GRAPHICS_OBJS) $(MOVEMENT_OBJS) $(INIT_OBJS) $(LIBFT_PREFX) $(MLX_FLAGS)
	@echo "\n\n$(GREEN)Build complete!$(RESET)\n\n"

$(LIBFT_PREFX):
	@echo "\n\n$(YELLOW)Compiling Libft...$(RESET)\n\n"
	@make -C $(LIBFT_DIR)

%.o: %.c
	@echo "\n\n$(BLUE)Compiling $<...$(RESET)\n\n"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "\n\n$(RED)Cleaning object files...$(RESET)\n\n"
	$(RM) $(CUBE_OBJS) $(GRAPHICS_OBJS) $(MOVEMENT_OBJS) $(INIT_OBJS)
	@cd $(LIBFT_DIR) && make clean

fclean: clean
	@echo "\n\n$(RED)Cleaning all...$(RESET)\n\n"
	$(RM) $(NAME)
	@cd $(LIBFT_DIR) && make fclean

re: fclean all

.PHONY: all clean fclean re



