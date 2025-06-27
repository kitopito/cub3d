NAME := libft.a

# 通常関数
MANSRC := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
          ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
          ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
          ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
          ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
          ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
          ft_putendl_fd.c ft_striteri.c ft_putnbr_fd.c ft_putstr_fd.c
MANOBJ := $(MANSRC:.c=.o)

# bonus 関数
BONSRC := ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
          ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
          ft_lstmap.c
BONOBJ := $(BONSRC:.c=.o)

# get_next_line 関連
GNLDIR := get_next_line
GNLSRC := $(addprefix $(GNLDIR)/, get_next_line.c )
GNLOBJ := $(GNLSRC:.c=.o)

# 全オブジェクト
OBJECT := $(MANOBJ) $(BONOBJ) $(GNLOBJ)

# コンパイルフラグ
CFLAGS := -Wall -Wextra -Werror -I.

# マーカー用ファイル名
BONUS_MARKER := .bonus
GETNL_MARKER := .getnl

# デフォルトターゲット
all: $(NAME) bonus getnl

# ライブラリ作成（標準関数のみ）
$(NAME): $(MANOBJ)
	ar rcs $(NAME) $(MANOBJ)

# bonus のビルド
bonus: $(NAME) $(BONUS_MARKER)

$(BONUS_MARKER): $(BONOBJ)
	ar rcs $(NAME) $(BONOBJ)
	touch $(BONUS_MARKER)

# get_next_line のビルド
getnl: $(NAME) $(GETNL_MARKER)

$(GETNL_MARKER): $(GNLOBJ)
	ar rcs $(NAME) $(GNLOBJ)
	touch $(GETNL_MARKER)

clean:
	$(RM) $(OBJECT) $(BONUS_MARKER) $(GETNL_MARKER)

fclean: clean
	$(RM) $(NAME)

re: fclean all
