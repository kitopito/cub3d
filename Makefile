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
LIBS := -lreadline -lm -lXext -lX11 -lz

MINILIBX = minilibx-linux/libmlx.a

# macOS向けreadline対応
ifeq ($(shell uname), Darwin)
	READLINE_DIR := $(shell brew --prefix readline)
	CFLAGS += -I$(READLINE_DIR)/include
	LDFLAGS += -L$(READLINE_DIR)/lib
endif

MAKE_LIBFT = $(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(MINILIBX) $(LIBFT)
	$(CC) -v $(CFLAGS) $(DEBUG) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME) 

$(LIBFT):
	$(MAKE_LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)
	$(MAKE_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
