##
## Makefile for make in /home/jean.morize/CPool_infinadd
##
## Made by Jean Morize
## Login   <jean.morize@epitech.net>
##
## Started on  Tue Oct 25 14:41:12 2016 Jean Morize
## Last update Tue Nov  8 15:55:20 2016 Jean Morize
##

CC      = gcc

RM      = rm -f

CFLAGS  += -Wextra -Wall -Werror
CFLAGS	+= -fPIC
CFLAGS  += -I./include/
LDFLAGS += -L. -lriceferee -lpthread

NAME    = philosopher

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
