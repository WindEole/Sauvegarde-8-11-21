# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iderighe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 11:35:21 by iderighe          #+#    #+#              #
#    Updated: 2021/11/04 12:02:28 by iderighe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	push_swap

SRCS	=	push_swap_1.c \
			push_swap_2.c \
			arg_check.c \
			instr_swap_push.c \
			instr_rotate.c \
			instr_revrotate.c \
			lib_utils.c \
			lib_utils_split.c \
			algorithme_to5.c \
			algorithme_to500_1.c \
			algorithme_to500_2.c \
			algorithme_to500_3.c \

OBJ		=	$(SRCS:.c=.o)

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address -g3 -fno-omit-frame-pointer

DEPS	=	push_swap.h

#rules :
#targets : prerequisites
#          command
#          command

all		:	$(NAME)

%.o		:	%.c $(DEPS)
			$(CC) -c -o $@ $< $(CFLAGS)

.c.o	:	
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME)	:	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS)



clean	:	
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
