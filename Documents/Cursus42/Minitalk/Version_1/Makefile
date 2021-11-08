# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rballage <rballage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 14:34:42 by rballage          #+#    #+#              #
#    Updated: 2021/09/09 14:02:52 by rballage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME2 = client

SRC_NAME =	main_server.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			s_add_bit.c \
			s_bufferise.c \
			s_clean.c \
			s_handler.c \
			s_parse_string.c \
			s_setlen.c \
			ft_memset.c


SRC2_NAME =	c_finished.c \
			main_client.c \
			c_quit.c \
			c_send_bit.c \
			c_send_len.c \
			c_send.c \
			c_stopclean.c \
			ft_atoi.c \
			ft_strlen.c

SRC_PATH = src_server
OBJ_PATH = obj_server

SRC2_PATH = src_client
OBJ2_PATH = obj_client

INCLUDES = includes
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I $(INCLUDES) -MMD

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ2_NAME = $(SRC2_NAME:.c=.o)
SRC2 = $(addprefix $(SRC2_PATH)/,$(SRC2_NAME))
OBJ2 = $(addprefix $(OBJ2_PATH)/,$(OBJ2_NAME))

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(CPPFLAGS) -o $@ $^

$(NAME2): $(OBJ2)
	$(CC) $(CCFLAGS) $(CPPFLAGS) -o $@ $^

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CCFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ2_PATH)/%.o: $(SRC2_PATH)/%.c | $(OBJ2_PATH)
	$(CC) $(CCFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

$(OBJ2_PATH):
	@mkdir $(OBJ2_PATH) 2> /dev/null || true

clean:
	rm -f $(OBJ) $(OBJ2) $(OBJ:.o=.d) $(OBJ2:.o=.d)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@rmdir $(OBJ2_PATH) 2> /dev/null || true

fclean:	clean
	@rm -f $(NAME) $(NAME2)

re: fclean
	$(MAKE)

bonus: $(NAME) $(NAME2)

norme:
	norminette $(SRC_PATH)
	norminette $(SRC2_PATH)
	norminette $(INCLUDES)

.PHONY: make clean fclean re

-include $(OBJ:.o=.d) $(OBJ2:.o=.d)
