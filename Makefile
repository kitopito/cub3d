CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = cub3d

PARSE_DIR = parse/
PARSE_SRCS = 

SRCS = main.c \
	$(addprefix $(PARSE_DIR), $(PARSE_SRCS)) \

OBJS := $(SRCS:.c=.o)

#LIBFT = libft/libft.a 

#LIBS = -lreadline
#INCLUDES = -Ilibft

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) #$(LIBFT)
	$(CC) -v $(CFLAGS) $(DEBUG) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME) 

$(LIBFT):
	make -C libft bonus

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS) $(B_OBJS)
#	make -C libft clean

fclean: clean
	rm -f $(NAME)
#	make -C libft fclean

re: fclean all

bonus: all

debug: 
	make re DEBUG=-g

.PHONY: all clean fclean re bonus debug