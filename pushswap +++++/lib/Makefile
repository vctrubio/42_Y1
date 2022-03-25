NAME = libft.a
SRC_DIR = srcs
SRCS = $(wildcard ./srcs/*.c)
OBJS = $(SRCS:.c=.o)
INCLUDE	= libft.h
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

all:	$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
		ar -rcs $(NAME) $(OBJS)

.c.o:
			$(CC) $(FLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

fclean:
	$(RM) $(OBJS) $(NAME)

clean:
	$(RM) $(OBJS)

re: clean all

help:
	@echo "Makefile - make all"