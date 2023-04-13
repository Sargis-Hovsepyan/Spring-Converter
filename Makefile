NAME = spring
SRCS = $(wildcard *.cpp)
OBJS = ${SRCS:.cpp=.o}

CC = clang++

FLAGS = -Wall -Wextra -Werror -I ./includes

.cpp.o:
	$(CC) $(FLAGS) -c $< -o ${<:.cpp=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(FLAGS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
