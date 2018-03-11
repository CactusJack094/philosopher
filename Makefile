##
## EPITECH PROJECT, 2018
## philosopher
## File description:
## makefile
##

CC      = gcc

RM      = rm -f

CFLAGS  += -Wextra -Wall -Werror
CFLAGS	+= -fPIC
CFLAGS  += -I./include/
LDFLAGS += -L. -lriceferee -lpthread

NAME    = philo

SRC     = sources/start_programm.c \
	sources/init_list.c \
	sources/main.c

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
