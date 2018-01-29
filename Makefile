# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/09 01:59:12 by ede-sous          #+#    #+#              #
#    Updated: 2018/01/29 03:32:53 by ede-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Deadpool_Bleeds

LIBS_SDL	=	`SDL2-config --cflags --libs` -lSDL2_image -lSDL2_ttf
GCC_FLAGS	=	gcc -Wall -Werror -Wextra -Weverything $(LIBS_SDL)

INCLUDES	=	-I./includes
INC			=	 includes/header.h includes/const_vars.h 

SRCS_DIR	=	sources/

SRCS_FILES	=	main.c \
				deadpoolBleedsConditions.c \
				createAssets.c \
				createObjs.c \
				initObjects.c \
				movements.c \
				putToWindow.c \
				startGame.c \
				minilib/ft_itoa.c \
				minilib/ft_strjoin.c \
				minilib/ft_strdel.c \
				minilib/ft_strlen.c \
				minilib/ft_isval.c \
				minilib/ft_strdup.c \
				minilib/ft_strcmp.c
				
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS		= $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS) $(INC) Makefile
	@$(GCC_FLAGS) -o $(NAME) $(OBJS) $(INCLUDES)
	@echo "\033[92m               Done !\033[0m"

%.o : %.c
	@gcc -c -o $@ $< $(INCLUDES)

clean :
	@rm -rf $(OBJS)
	@echo "           \033[92m Mission completed."
	@echo "      All Objects are ghosts haunting you.\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[31m Ups... My fluffy weapon killed $(NAME) :x\033[0m"

re: fclean
	@make
