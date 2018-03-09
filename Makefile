##
## EPITECH PROJECT, 2018
## philosopher
## File description:
## makefile - philo
##

NAME	= philo

CC	= gcc

RM	= rm -f

SRCS	= ./src/action.c \
	  ./src/main.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -lpthread -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC)  $(LDFLAGS) $(OBJS) libriceferee.so -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
