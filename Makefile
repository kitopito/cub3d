CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = cub3d

SRC_DIR := srcs
SRCS_MAIN := main.c

SRCS_UTILS := $(addprefix $(SRC_DIR)/, \
	init.c parser.c utils.c debug.c)

SRCS := $(SRCS_MAIN) $(SRCS_UTILS)
OBJS := $(SRCS:.c=.o)

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

MLX_DIR   = minilibx-linux
MINILIBX  = $(MLX_DIR)/libmlx.a

CFLAGS  += -I$(MLX_DIR)
LDFLAGS += -L$(MLX_DIR)
LIBS    := -lmlx -lXext -lX11 -lm -lz

ifeq ($(shell uname -s),Darwin)
X11_DIR := /opt/X11
CFLAGS  += -I$(X11_DIR)/include
LDFLAGS += -L$(X11_DIR)/lib
endif

MAKE_LIBFT = $(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(MINILIBX) $(LIBFT)
	$(CC) -v $(CFLAGS) $(DEBUG) $(OBJS) $(LIBFT) $(LDFLAGS) $(LIBS) -o $(NAME)

$(LIBFT):
	$(MAKE_LIBFT)

$(MINILIBX):
	@if [ ! -d $(MLX_DIR) ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git; \
	fi
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)
	$(MAKE_LIBFT) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE_LIBFT) fclean
	$(MAKE) -C $(MLX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
