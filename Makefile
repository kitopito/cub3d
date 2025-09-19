CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = cub3d

SRC_DIR := srcs
SRCS_MAIN := main.c
SRCS_UTILS := $(addprefix $(SRC_DIR)/, init.c parser.c find_player.c utils.c debug.c check.c check_map.c cub3d.c)
SRCS_DDA := $(addprefix $(SRC_DIR)/dda/, dda.c dda_utils.c texture.c)
SRCS_HOOKS := $(addprefix $(SRC_DIR)/hooks/, hooks.c key_hook.c)

SRCS := $(SRCS_MAIN) $(SRCS_UTILS) $(SRCS_DDA) $(SRCS_HOOKS)
OBJS := $(SRCS:.c=.o)

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

MLX_DIR := minilibx-linux
MINILIBX := $(MLX_DIR)/libmlx.a

CFLAGS += -I$(MLX_DIR)
LDFLAGS += -L$(MLX_DIR)
LIBS := -lmlx -lXext -lX11 -lm -lz

ifeq ($(shell uname -s),Darwin)
X11_DIR := /opt/X11
CFLAGS += -I$(X11_DIR)/include
LDFLAGS += -L$(X11_DIR)/lib
endif

MAKE_LIBFT = $(MAKE) -C $(LIBFT_DIR)

.PHONY: all clean fclean re test test-valid test-invalid

all: $(NAME)

$(NAME): $(MINILIBX) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) $(LIBS) -o $@

$(LIBFT):
	$(MAKE_LIBFT)

$(MINILIBX):
	@if [ ! -d $(MLX_DIR) ]; then git clone https://github.com/42Paris/minilibx-linux.git; fi
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE_LIBFT) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean:
	rm -f $(OBJS) $(NAME)
	$(MAKE_LIBFT) fclean
	-$(MAKE) -C $(MLX_DIR) fclean || $(MAKE) -C $(MLX_DIR) clean

re: fclean all

debug:
	$(MAKE) DEBUG="-g" re

test: $(NAME) test-valid test-invalid

test-valid: $(NAME)
	@bash -lc 'shopt -s nullglob; failed=0; \
	for f in map/valid/*.cub; do \
	  if ./$(NAME) "$$f" >/dev/null 2>&1; then \
	    echo "OK(valid): $$f"; \
	  else \
	    echo "NG(valid): $$f"; failed=1; \
	  fi; \
	done; \
	exit $$failed'

test-invalid: $(NAME)
	@bash -lc 'shopt -s nullglob; failed=0; \
	for f in map/invalid/*.cub; do \
	  if ./$(NAME) "$$f" >/dev/null 2>&1; then \
	    echo "NG(invalid passed): $$f"; failed=1; \
	  else \
	    echo "OK(invalid): $$f"; \
	  fi; \
	done; \
	exit $$failed'
