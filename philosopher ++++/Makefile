NAME = philo
SRC = $(wildcard srs/*.c)
OBJ = $(SRS:%.c=%.o)
FLG = -Wall -Werror -Wextra
INC = -lpthread
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@echo "start compile"
	gcc -g $(SRC) $(INC) -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean all
