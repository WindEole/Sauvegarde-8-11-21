SRCS = main2.cpp

CPP = clang++
CFLAGS = -Wall -Werror -Wextra -std=c++98

OBJS = ${SRCS:.cpp=.o}
NAME = Iter

.cpp.o:
	${CPP} ${CFLAGS} -c $< -o ${<:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CPP} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all re clean fclean
