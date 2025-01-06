SRCS	=	push_swap.c \
			operations.c \
			
OBJ	=	$(SRCS:.c=.o)
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDES	=	-I.
RM	=	rm -f
NAME	=	push_swap

NAME : SRCS
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
