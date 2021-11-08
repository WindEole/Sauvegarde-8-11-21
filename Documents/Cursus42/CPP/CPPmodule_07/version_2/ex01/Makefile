SRCS		= main.cpp \
			  myClass.cpp

OBJS		= $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

INCLUDE		= -I .

OBJS_DIR	= objs/

CC			= clang++

CPPFLAGS	= -Wall -Werror -Wextra -std=c++98

NAME		= iter

all			: $(NAME)

$(OBJS_DIR)%.o	: ./%.cpp
			  	  $(CC) $(CPPFLAGS) $(INCLUDE) -c $< -o $@

$(NAME)		: $(OBJS_DIR) $(OBJS)
			  $(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)	:
			  @mkdir $(OBJS_DIR)

clean		:
		 	 rm -rf $(OBJS_DIR)

fclean		: clean
		 	 rm -rf $(NAME)

re			: clean all

.PHONY		: all clean re