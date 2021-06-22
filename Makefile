# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                 PROGRAMS                                    #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

NAME = push_swap
CHECKER = checker
INCLUDES_DIR = includes
HEAD = -I./$(LIBFT_DIR) -I./$(INCLUDES_DIR)
SRCS_DIR = srcs
OBJS_DIR = .objs
CC = clang
CFLAGS = -Wall -Werror -Wextra
DFLAGS = -g -fsanitize=address
LFLAGS = -L./libft -lft
RM = /bin/rm -rf

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS_STACK_FILES =		stack/unify_args.c \
						stack/validate_params.c \
						stack/build_stacks.c \
						stack/operations.c \
						stack/is_sorted.c \
						stack/clear_stacks.c \
						stack/debug.c \
						stack/op_swap.c \
						stack/op_push.c \
						stack/op_rotate.c \
						stack/op_reverse_rotate.c

SRCS_STACK = $(addprefix $(SRCS_DIR)/,$(SRCS_STACK_FILES))
OBJS_STACK = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS_STACK))

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                PUSH SWAP                                    #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

SRCS_PUSH_SWAP_FILES =	push_swap.c \
						sort_small_list.c \
						index_elements.c \
						markup_head.c \
						smallest_action.c \
						align_stack_a.c \
						atribute_and_operate.c \
						utils.c

SRCS_PUSH_SWAP = $(addprefix $(SRCS_DIR)/,$(SRCS_PUSH_SWAP_FILES))
OBJS_PUSH_SWAP = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS_PUSH_SWAP))

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJS_STACK) $(OBJS_PUSH_SWAP)
	@$(CC) $(OBJS_PUSH_SWAP) $(OBJS_STACK) $(HEAD) $(DFLAGS) $(CFLAGS) $(LFLAGS) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)/stack
	@$(CC) $(DFLAGS) $(CFLAGS) $(HEAD) -c $< -o $@
	@echo -n "$< "
	@tput setaf 28; echo "✔"
	@tput sgr0

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# #                                CHECKER                                      #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

SRCS_CHECKER_FILES = checker.c

SRCS_CHECKER = $(addprefix $(SRCS_DIR)/,$(SRCS_CHECKER_FILES))
OBJS_CHECKER = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS_CHECKER))

bonus: $(CHECKER)

$(CHECKER) : $(LIBFT) $(OBJS_STACK) $(OBJS_CHECKER)
	@$(CC) $(OBJS_CHECKER) $(OBJS_STACK) $(HEAD) $(DFLAGS) $(CFLAGS) $(LFLAGS) -o $@

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                   LIBFT                                     #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                             CLEAN AND FCLEAN                                #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

clean:
	@make --no-print-directory clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS_DIR)
	@tput bold
	@echo "Deleting objects ..."
	@tput sgr0

fclean: clean
	@make --no-print-directory fclean -C $(LIBFT_DIR)
	@$(RM) $(STACK)
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
	@tput bold; tput rev
	@echo "\n*~*~*~*  NORMINETTE  *~*~*~*"
	@echo ""
	@tput sgr0
	@norminette $(LIBFT_DIR) $(SRCS_DIR) $(INCLUDES_DIR) 2>&1 | grep "Error" | tee norm.txt
	@bash .norm.sh norm.txt

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                   TEST                                      #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

test:
	@ ./test.sh
