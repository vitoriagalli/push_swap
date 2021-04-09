
######### PROGRAMS ##########

NAME	= push_swap
CHECKER = checker

########## HEADER ########

INCLUDES_DIR = includes
HEAD = -I./$(LIBFT_DIR) -I./$(INCLUDES_DIR)

############ FLAGS #############

CC = clang
CFLAGS = -Wall -Werror -Wextra -g -w
LFLAGS = -L ./$(LIBFT_DIR) -lft
RM = /bin/rm -rf

############# LIBFT ##############

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a


############ CHECKER #############

SRCS_CHECKER_FILES = checker.c

SRCS_CHECKER_DIR = srcs_checker
SRCS_CHECKER = $(addprefix $(SRCS_CHECKER_DIR)/,$(SRCS_CHECKER_FILES))

OBJS_CHECKER_DIR = .objs_checker
OBJS_CHECKER = $(patsubst $(SRCS_CHECKER_DIR)%.c, $(OBJS_CHECKER_DIR)%.o, $(SRCS_CHECKER))


########### PUSH SWAP ###############

SRCS_PUSH_SWAP_FILES = push_swap.c

SRCS_PUSH_SWAP_DIR = srcs_push_swap
SRCS_PUSH_SWAP = $(addprefix $(SRCS_PUSH_SWAP_DIR)/,$(SRCS_PUSH_SWAP_FILES))

OBJS_PUSH_SWAP_DIR = .objs_push_swap
OBJS_PUSH_SWAP = $(patsubst $(SRCS_PUSH_SWAP_DIR)%.c, $(OBJS_PUSH_SWAP_DIR)%.o, $(SRCS_PUSH_SWAP))


#######################################

all: $(NAME)

########### PUSH_SWAP COMPILE ###########


$(NAME) : $(OBJS_PUSH_SWAP) $(LIBFT) $(CHECKER)
	$(CC) $(OBJS_PUSH_SWAP) $(HEAD) $(CFLAG) $(LFLAGS) -o $@

$(OBJS_PUSH_SWAP_DIR)/%.o: $(SRCS_PUSH_SWAP_DIR)/%.c
	mkdir -p $(OBJS_PUSH_SWAP_DIR)
	$(CC) $(CFLAGS) $(HEAD) -c $< -o $@


############ CHECKER COMPLILE ##########


$(CHECKER) : $(OBJS_CHECKER) $(LIBFT)
	$(CC) $(OBJS_CHECKER) $(HEAD) $(CFLAG) $(LFLAGS) -o $@

$(OBJS_CHECKER_DIR)/%.o: $(SRCS_CHECKER_DIR)/%.c
	mkdir -p $(OBJS_CHECKER_DIR)
	mkdir -p $(OBJS_CHECKER_DIR)/stack
	$(CC) $(CFLAGS) $(HEAD) -c $< -o $@


############ LIBFT ##########

$(LIBFT):
	make -C $(LIBFT_DIR)

############ OTHER RULES ##########

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS_CHECKER_DIR)
	$(RM) $(OBJS_PUSH_SWAP_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(CHECKER)
	$(RM) $(NAME)

re: fclean all
