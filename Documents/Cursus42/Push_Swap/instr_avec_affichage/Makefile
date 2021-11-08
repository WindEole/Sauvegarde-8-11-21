# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iderighe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 11:35:21 by iderighe          #+#    #+#              #
#    Updated: 2021/08/26 11:41:23 by iderighe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	push_swap

SRCS	=	push_swap.c \
			instr_push.c \
			instr_swap.c \
			instr_rotate.c \
			instr_revrotate.c \
			lib_utils.c \
			lib_utils_split.c \
			algorithme_to5.c \
			algorithme_to500.c \

OBJ		=	$(SRCS:.c=.o)

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

DEPS	=	push_swap.h

#rules :
#targets : prerequisites
#          command
#          command

%.o		:	%.c $(DEPS)
			$(CC) -c -o $@ $< $(CFLAGS)

.c.o	:	
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$NAME	:	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

all		:	$(NAME)

clean	:	
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
