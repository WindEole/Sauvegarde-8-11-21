# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <besellem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 13:46:17 by besellem          #+#    #+#              #
#    Updated: 2021/08/05 11:38:24 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	diamondtrap

SRCS		:=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp \
				DiamondTrap.cpp

OBJS		=	$(SRCS:.cpp=.o)

INCS		:=	ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

CC			:=	clang++
CPPFLAGS	:=	-Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98 -g3

.c.o:
			@echo "Compiling ..."
			@$(CC) $(CPPFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

$(NAME):	$(OBJS)
			@$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			@echo "Deleting objects ..."
			@rm -f $(OBJS)

fclean:		clean
			@echo "Deleting binary ..."
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
