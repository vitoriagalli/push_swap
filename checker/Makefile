NAME = checker

SRCS_DIR =	srcs
OBJS_DIR =	.objs
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_FILES =	checker.c

SRCS = $(addprefix $(SRCS_DIR)/,$(SRC_FILES))
OBJS = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

HEAD = -I./$(LIBFT_DIR) -I.
CC = clang
CFLAGS = -Wall -Werror -Wextra -g -w
LFLAGS = -L ./$(LIBFT_DIR) -lft
RM = /bin/rm -rf

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(HEAD) $(CFLAG) $(LFLAGS) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
		mkdir -p $(OBJS_DIR)
		$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all


