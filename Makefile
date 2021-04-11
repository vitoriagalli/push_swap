######### PROGRAMS ##########

NAME	= push_swap
CHECKER = checker

all: $(NAME)

INCLUDES_DIR = includes
HEAD = -I./$(LIBFT_DIR) -I./$(INCLUDES_DIR)

SRCS_DIR = srcs
OBJS_DIR = .objs
CC = clang
CFLAGS = -Wall -Werror -Wextra #-w
DFLAGS = -g -fsanitize=address
LFLAGS = -L ./$(LIBFT_DIR) -lft
RM = /bin/rm -rf


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                   LIBFT                                     #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

$(LIBFT):
	@echo "Compiling libft ..."
	@make --no-print-directory -C $(LIBFT_DIR)


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                CHECKER                                      #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

SRCS_CHECKER_FILES =	checker.c \
						validate_params.c \
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
	@tput sgr0; tput bold
	@echo "Compiling $(CHECKER) ..."

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/stack
	@$(CC) $(DFLAGS) $(CFLAGS) $(HEAD) -c $< -o $@
	@tput sgr0; echo -n "$< "
	@tput setaf 28; echo "✔"

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                PUSH SWAP                                    #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

SRCS_PUSH_SWAP_FILES = push_swap.c

SRCS_PUSH_SWAP = $(addprefix $(SRCS_DIR)/,$(SRCS_PUSH_SWAP_FILES))
OBJS_PUSH_SWAP = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS_PUSH_SWAP))

$(NAME) : $(OBJS_PUSH_SWAP) $(LIBFT) $(CHECKER)
	@$(CC) $(OBJS_PUSH_SWAP) $(HEAD) $(DFLAGS) $(CFLAGS) $(LFLAGS) -o $@
	@tput sgr0; tput bold
	@echo "Compiling $(NAME) ..."

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(DFLAGS) $(CFLAGS) $(HEAD) -c $< -o $@
	@tput sgr0; echo -n "$< "
	@tput setaf 28; echo "✔"

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                             CLEAN AND FCLEAN                                #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

clean:
	@make --no-print-directory clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS_CHECKER_DIR)
	@$(RM) $(OBJS_PUSH_SWAP_DIR)
	@tput sgr0; tput bold
	@echo "Deleting objects ..."

fclean: clean
	@make --no-print-directory fclean -C $(LIBFT_DIR)
	@$(RM) $(CHECKER)
	@$(RM) $(NAME)
	@tput sgr0; tput bold
	@echo "Deleting $(NAME) and $(CHECKER) binarys ..."

re: fclean all


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                    NORM                                     #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

norm:
	@norminette $(LIBFT_DIR)
	@norminette $(SRCS_DIR)




# @tput setab 57; tput setaf 39
# @tput setaf 39; tput bold; tput smul; tput rev; tput blink

# @tput setaf 39; tput bold; tput rev
