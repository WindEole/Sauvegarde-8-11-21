SRCS_SUBJECT = main_array.cpp
SRCS = main.cpp

CPP = clang++
CFLAGS = -Wall -Werror -Wextra -std=c++98

OBJS = ${SRCS:.cpp=.o}
OBJS_SUBJECT = ${SRCS_SUBJECT:.cpp=.o}
NAME_SUBJECT = array_subject
NAME = array

.cpp.o:
	${CPP} ${CFLAGS} -c $< -o ${<:.cpp=.o}

all: ${NAME} ${NAME_SUBJECT}

${NAME}: ${OBJS}
	${CPP} ${CFLAGS} ${OBJS} -o ${NAME}

${NAME_SUBJECT}: ${OBJS_SUBJECT}
	${CPP} ${CFLAGS} ${OBJS_SUBJECT} -o ${NAME_SUBJECT}

clean:
	rm -rf ${OBJS} ${OBJS_SUBJECT}

fclean: clean
	rm -rf ${NAME} ${NAME_SUBJECT}

re: fclean all

.PHONY: all re clean fclean
