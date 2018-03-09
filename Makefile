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
CFLAGS +=  -W -Wall -Wextra
LDFLAGS += -L. -lriceferee -lpthread

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
