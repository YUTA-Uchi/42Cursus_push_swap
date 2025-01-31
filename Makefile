NAME		:=	push_swap
SRCS		:=	main.c \
				operations.c \
				operations_swap_private.c \
				operations_push_private.c \
				operations_rotate_private.c \
				operations_reverse_rotate_private.c \
				stack_private.c \
				stack_private_utils.c \
				stack_public.c \
				validator_private.c \
				validator_private_utils.c \
				validator_public.c \
				sort_solver_public.c \
				sort_strategy_public.c \
				selection_sort_strategy_private.c \

OBJ_DIR		:=	./obj
OBJS		:=	$(SRCS:%.c=$(OBJ_DIR)/%.o)
LIBFT_DIR	:=	libft
LD_FLAGS	:=	-L$(LIBFT_DIR)
LD_LIBS		:=	-lft
INC			:=	-Iincludes -I$(LIBFT_DIR) -MMD -MP
CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror

vpath %.c	./srcs:./srcs/operations:./srcs/stack:./srcs/validator:./srcs/sort_solver:./srcs/strategy

$(NAME) : $(OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(LD_FLAGS) $(LD_LIBS) -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT_DIR)/libft.a: $(LIBFT_DIR)
	$(MAKE) complete -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all:	$(NAME)

clean:
	$(RM) -r $(OBJS) $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re:	fclean all

.PHONY:	all clean fclean re