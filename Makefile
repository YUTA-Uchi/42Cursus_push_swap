PUSH_SWAP		:=	push_swap
CHECKER			:=	checker
NAME			:=	$(PUSH_SWAP)
COMMON_SRCS		:=	operations.c \
					operations_swap_private.c \
					operations_push_private.c \
					operations_rotate_private.c \
					operations_reverse_rotate_private.c \
					stack_private.c \
					stack_private_utils.c \
					stack_public.c \
					stack_public_utils.c \
					doubly_linked_list_public.c \
					doubly_linked_list_public_utils.c \
					validator_private.c \
					validator_private_utils.c \
					validator_public.c \
					sort_solver_public.c \
					sort_strategy_public.c \
					manual_sort_strategy_private.c \
					minimal_sort_strategy_private.c \
					sort_three_strategy_private.c \
					v3_quick_sort_strategy_private.c \
					v3_quick_sort_strategy_private_utils.c \
					v3_quick_sort_strategy_private_position.c

PUSH_SWAP_SRCS	:=	main.c

CHECKER_SRCS	:=	main_bonus.c

OBJ_DIR			:=	./obj
OBJS			:=	$(COMMON_SRCS:%.c=$(OBJ_DIR)/%.o)
PUSH_SWAP_OBJS	:=	$(PUSH_SWAP_SRCS:%.c=$(OBJ_DIR)/%.o)
CHECKER_OBJS	:=	$(CHECKER_SRCS:%.c=$(OBJ_DIR)/%.o)
LIBFT_DIR		:=	libft
LD_FLAGS		:=	-L$(LIBFT_DIR)
LD_LIBS			:=	-lft
INC				:=	-Iincludes -I$(LIBFT_DIR) -MMD -MP
CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror

vpath %.c	./srcs:./srcs/operations:./srcs/stack:./srcs/stack/doubly_linked_list:./srcs/validator:./srcs/sort_solver:./srcs/strategy

$(PUSH_SWAP) : $(OBJS) $(PUSH_SWAP_OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(PUSH_SWAP_OBJS) $(LD_FLAGS) $(LD_LIBS) -o $@

$(CHECKER) : $(OBJS) $(CHECKER_OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(CHECKER_OBJS) $(LD_FLAGS) $(LD_LIBS) -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT_DIR)/libft.a: $(LIBFT_DIR)
	$(MAKE) complete -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all:	$(NAME)

bonus:	$(CHECKER)

clean:
	$(RM) -r $(OBJS) $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean:	clean
	$(RM) $(PUSH_SWAP) $(CHECKER)
	$(MAKE) fclean -C $(LIBFT_DIR)

re:	fclean all

.PHONY:	all clean fclean re