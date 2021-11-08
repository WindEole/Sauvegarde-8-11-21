# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: humanfou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 10:42:37 by humanfou          #+#    #+#              #
#    Updated: 2021/04/02 13:09:43 by humanfou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

LIB = ar rcs

CC = clang

CCFLAGS = -Wall -Wextra -Werror

SANITIZE = -g3 -fomit-frame-pointer

ASM = nasm

ifeq ($(shell uname),Linux)
	ASMFLAGS = -f elf64
else
	ASMFLAGS = -f macho64
endif

INC = -Iincludes

ASM_SRCS =  srcs/ft_strlen.s \
			srcs/ft_strcpy.s \
			srcs/ft_strcmp.s \
			srcs/ft_write.s \
			srcs/ft_read.s \
			srcs/ft_strdup.s \

ASM_OBJS = $(ASM_SRCS:%.s=%.o)

all: $(NAME)

$(NAME): $(ASM_OBJS)
	$(LIB) $(NAME) $(ASM_OBJS)

test: re
	$(CC) $(CCFLAGS) $(SANITIZE) main.c $(NAME)

%.o: %.s
	$(ASM) $(ASMFLAGS) -o $@ $< $(INC)

clean:
	@rm -rf $(ASM_OBJS)

fclean: clean
	@rm -rf $(NAME) a.out

re: fclean all

.PHONY: all bonus test clean fclean re
