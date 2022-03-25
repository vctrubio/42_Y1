NAME = pipex
SRCS = $(wildcard ./srcs/*.c)
OBJS = $(SRCS:.c=.o)
RM = rm -f
FLAGS =-Werror -Wextra -Wall


LIBFT_PATH		=	./lib
LIBFT			=	$(LIBFT_PATH)/libft.a

$(NAME) : $(OBJS)
	@echo "here from makefile"
	$(MAKE) --directory=lib
	gcc -g $(OBJS) $(FLAGS) $(LIBFT) -o $@

all:	$(NAME)

clean:
	$(RM) $(OBJS) $(NAME)
#would be nice to remove lib output

re: clean all


# $(NAME), all, clean, fclean and re.