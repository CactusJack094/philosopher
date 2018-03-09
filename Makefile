
CC		=	gcc

RM		=	rm -rf

NAME	=	philo

SRC		= 	src/main.c \
			src/action.c

CFLAGS	=	-W -Wall -Wextra -Werror

LDFLAGS	=	-lpthread

OBJ		=	$(SRC:.c=.o)

$(NAME)	: $(OBJ)
	$(CC) $(LDFLAGS) $(CFLAGS) libriceferee.so $(OBJ) -o $(NAME)

all		:	$(NAME)

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
