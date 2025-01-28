NAME		:=	push_swap
SRCS		:=	push_swap.c \
				operations.c 
OBJ_DIR		:=	obj
OBJS		:=	$(SRCS:%.c=$(OBJ_DIR)/%.o)
LIBFT_DIR	:=	libft
LD_FLAGS	:=	-L$(LIBFT_DIR)
LD_LIBS		:=	-lft
INC			:=	-Iincludes -I$(LIBFT_DIR)
CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror


$(NAME) : $(OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(LD_FLAGS) $(LD_LIBS) -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT_DIR)/libft.a: $(LIBFT_DIR)
	$(MAKE) complete -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $@

all:	$(NAME)

clean:
	$(RM) -r $(OBJS) $(OBJ_DIR)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re