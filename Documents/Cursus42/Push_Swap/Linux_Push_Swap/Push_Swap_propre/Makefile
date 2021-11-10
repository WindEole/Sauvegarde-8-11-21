# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iderighe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 11:35:21 by iderighe          #+#    #+#              #
#    Updated: 2021/11/10 11:23:58 by iderighe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	push_swap

SRCS	=	1_main_arg_check.c \
			2_fct_check.c \
			3_stack_parse.c \
			4_algo_to5.c \
			5_algo_500_1_global.c \
			5_algo_500_2_index.c \
			5_algo_500_3_move.c \
			5_algo_500_4_posb.c \
			instr_swap_push.c \
			instr_rotate.c \
			instr_revrotate.c \
			instr_loops.c \
			lib_utils.c \
			lib_utils_split.c \


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
