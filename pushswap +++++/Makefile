NAME = push_swap
SRCS = $(wildcard ./srcs/*.c)
OBJS = $(SRCS:.c=.o)
RM = rm -f
FLAGS =-Werror -Wextra -Wall

LIBFT_PATH		=	./lib
LIBFT			=	$(LIBFT_PATH)/libft.a
MAKELIB = make -C ./lib

all:	$(NAME)
$(NAME) : $(OBJS)
	@echo "here from makefile"
	$(MAKELIB)
	gcc -g $(OBJS) $(FLAGS) $(LIBFT) -o $@ 


fclean:
	$(RM) $(OBJS) $(NAME)
	$(MAKELIB) fclean

clean:
	$(RM) $(OBJS)

re: clean all
