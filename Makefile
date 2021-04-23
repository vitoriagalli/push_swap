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
DFLAGS = -g #-fsanitize=address
LFLAGS = -L . -lstack
RM = /bin/rm -rf

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                   LIBFT                                     #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

$(LIBFT):
	@tput bold
	@echo "Compiling libft ..."
	@tput sgr0
	@make --no-print-directory -C $(LIBFT_DIR)

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                               STACK LIB                                     #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

STACK = libstack.a

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

$(STACK) : $(LIBFT) $(OBJS_STACK)
	@mv $(LIBFT) $(STACK)
	@ar rc $(STACK) $(OBJS_STACK)
	@tput bold
	@echo "Compiling $(STACK) ..."
	@tput sgr0

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/stack
	@$(CC) $(DFLAGS) $(CFLAGS) $(HEAD) -c $< -o $@
	@echo -n "$< "
	@tput setaf 28; echo "✔"
	@tput sgr0

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                CHECKER                                      #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

SRCS_CHECKER_FILES =	checker.c

SRCS_CHECKER = $(addprefix $(SRCS_DIR)/,$(SRCS_CHECKER_FILES))
OBJS_CHECKER = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS_CHECKER))

$(CHECKER) : $(STACK) $(OBJS_CHECKER)
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
						sort_list_of_three.c \
						sort_list_of_five.c \
						sort_algoritm_push_to_b.c \
						sort_algoritm_push_to_a.c \
						sort_algoritm_push_to_a_utils.c \
						median.c \
						utils_nodes.c \
						utils.c \

SRCS_PUSH_SWAP = $(addprefix $(SRCS_DIR)/,$(SRCS_PUSH_SWAP_FILES))
OBJS_PUSH_SWAP = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS_PUSH_SWAP))

$(NAME) : $(CHECKER) $(OBJS_PUSH_SWAP)
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
	@ tput bold; tput rev
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
