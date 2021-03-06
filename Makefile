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

ifeq (,$(shell command -v SDL2-config 2> /dev/null))
	SDL_EXEC := SDL2-config
else
	SDL_EXEC := sdl2-config
endif

LIBS_SDL	=	`$(SDL_EXEC) --libs` -lSDL2_image -lSDL2_ttf
GCC_FLAGS	=	gcc -Wall -Werror -Wextra

INCLUDES	=	-I./includes `$(SDL_EXEC) --cflags`
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

all : checkup $(NAME)

$(NAME): $(OBJS) $(INC) Makefile
	@$(GCC_FLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBS_SDL)
	@echo "\033[92m               Done !\033[0m"

%.o : %.c
	@gcc $(INCLUDES) -c -o $@ $<

checkup:
	@if [ "$(shell command -v brew 2> /dev/null)" = "" ]; then echo "brew is not installed - WARNING"; fi
	@if [ "$(shell command -v $(SDL_EXEC) 2> /dev/null)" = "" ]; then echo "SDL2 is not installed - ABORT" && exit 1; fi


clean :
	@rm -rf $(OBJS)
	@echo "           \033[92m Mission completed."
	@echo "      All Objects are ghosts haunting you.\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[31m Ups... My fluffy weapon killed $(NAME) :x\033[0m"

re: fclean
	@make

.PHONY: re fclean clean checkup %.o %.c $(NAME) all 