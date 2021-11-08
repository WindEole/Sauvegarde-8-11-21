# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iderighe <iderighe@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/12 12:04:34 by iderighe          #+#    #+#              #
#    Updated: 2021/03/29 11:21:07 by iderighe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	ft_printf.c \
			ft_printf_utils1.c \
			ft_printf_utils2.c \
			ft_printf_utils3.c \
			ft_flags.c ft_flagstreat.c \
			ft_printf_typeschar.c \
			ft_printf_typesint1.c \
			ft_printf_typesint2.c \
			ft_printf_typesint3.c \
			ft_printf_typesuix.c \
			ft_printf_typesptr.c \

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

RM		=	rm -f

FLAGS	=	-Wall -Wextra -Werror -c

.c.o	:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME)	:	$(OBJ)
			ar rcs $(NAME) $(OBJ)

$(OBJ)	:	$(SRC)
			$(CC) $(FLAGS) $(SRC)

all		:	$(NAME)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
