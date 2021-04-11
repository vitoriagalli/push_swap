# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                 PROGRAMS                                    #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

NAME	= push_swap
CHECKER = checker

all: $(NAME)

INCLUDES_DIR = includes
HEAD = -I./$(LIBFT_DIR) -I./$(INCLUDES_DIR)

SRCS_DIR = srcs
OBJS_DIR = .objs
CC = clang
CFLAGS = -Wall -Werror -Wextra -w
DFLAGS = -g -fsanitize=address
LFLAGS = -L ./$(LIBFT_DIR) -lft
RM = /bin/rm -rf

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                   LIBFT                                     #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

$(LIBFT):
	@ tput bold
	@echo "Compiling libft ..."
	@make --no-print-directory -C $(LIBFT_DIR)
	@tput sgr0

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                CHECKER                                      #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

SRCS_CHECKER_FILES =	checker.c \
						validate_params.c \
						build_stacks.c \
						operations.c \
						commands.c \
						clear_stacks.c \
						debug.c \
						stack/swap.c \
						stack/push.c \
						stack/rotate.c \
						stack/reverse_rotate.c

SRCS_CHECKER = $(addprefix $(SRCS_DIR)/,$(SRCS_CHECKER_FILES))
OBJS_CHECKER = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS_CHECKER))

$(CHECKER) : $(OBJS_CHECKER) $(LIBFT)
	@$(CC) $(OBJS_CHECKER) $(HEAD) $(DFLAGS) $(CFLAGS) $(LFLAGS) -o $@
	@tput bold
	@echo "Compiling $(CHECKER) ..."
	@tput sgr0

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/stack
	@$(CC) $(DFLAGS) $(CFLAGS) $(HEAD) -c $< -o $@
	@echo -n "$< "
	@tput setaf 28; echo "✔"
	@tput sgr0

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                PUSH SWAP                                    #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

SRCS_PUSH_SWAP_FILES =	push_swap.c \
						build_stacks.c \
						validate_params.c \
						operations.c \
						commands.c \
						clear_stacks.c \
						debug.c \
						stack/swap.c \
						stack/push.c \
						stack/rotate.c \
						stack/reverse_rotate.c


SRCS_PUSH_SWAP = $(addprefix $(SRCS_DIR)/,$(SRCS_PUSH_SWAP_FILES))
OBJS_PUSH_SWAP = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS_PUSH_SWAP))

$(NAME) : $(OBJS_PUSH_SWAP) $(LIBFT) $(CHECKER)
	@$(CC) $(OBJS_PUSH_SWAP) $(HEAD) $(DFLAGS) $(CFLAGS) $(LFLAGS) -o $@
	@tput bold
	@echo "Compiling $(NAME) ..."
	@tput sgr0

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(DFLAGS) $(CFLAGS) $(HEAD) -c $< -o $@
	@ echo -n "$< "
	@tput setaf 28; echo "✔"
	@tput sgr0

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                             CLEAN AND FCLEAN                                #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

clean:
	@make --no-print-directory clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS_CHECKER_DIR)
	@$(RM) $(OBJS_PUSH_SWAP_DIR)
	@tput bold
	@echo "Deleting objects ..."
	@tput sgr0

fclean: clean
	@make --no-print-directory fclean -C $(LIBFT_DIR)
	@$(RM) $(CHECKER)
	@$(RM) $(NAME)
	@tput bold
	@echo "Deleting $(NAME) and $(CHECKER) binarys ..."
	@tput sgr0

re: fclean all

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                    NORM                                     #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

norm:
	@ tput bold; tput rev
	@echo "\n*~*~*~*  NORMINETTE  *~*~*~*"
	@echo ""
	@tput sgr0
	@norminette $(LIBFT_DIR) $(SRCS_DIR) $(INCLUDES_DIR) 2>&1 | grep "Error" | tee norm.txt
	@bash .norm.sh norm.txt
