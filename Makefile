##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME	=	my_screensaver

CC	=	g++

MAKE	=	/usr/bin/make

SRC_DIR	=	./src_main

SRC_DIR1	=	./src_1

SRC_DIR2	=	./src_2

SRC_DIR3	=	./src_3

SRC_DIR_TOOLS	=	./tools

LIB_DIR	=	./lib/my

SRC	=	$(SRC_DIR)/main.c			\
		$(SRC_DIR)/error.c			\
		$(SRC_DIR)/info.c			\
		$(SRC_DIR)/select.c			\
		$(SRC_DIR1)/screen1.c			\
		$(SRC_DIR1)/random_fractal.c		\
		$(SRC_DIR2)/move_fractal.c		\
		$(SRC_DIR2)/move_fractal2.c		\
		$(SRC_DIR3)/zoom_mande.c		\
		$(SRC_DIR3)/zoom_mande2.c		\
		$(SRC_DIR_TOOLS)/my_put_pixel.c		\
		$(SRC_DIR_TOOLS)/tools_framebuffer.c	\
		$(SRC_DIR_TOOLS)/window.c

SRCLIB	=	$(LIB_DIR)/my_putchar.c	\
		$(LIB_DIR)/my_putstr.c

OBJ2	=	$(SRCLIB:.c=.o)

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

C_FLAG	=	-Werror -Wall -Wextra

INCLUDE	=	-I ./include

all:		$(NAME)

$(NAME):	lib
		$(CC) $(SRC) -o $(NAME) -lcsfml-graphics -lcsfml-system -lcsfml-window $(INCLUDE) -L./lib -lmy

lib:		$(OBJ2)
		ar rc libmy.a $(OBJ2)
		mv ./libmy.a ./lib/

clean:
		$(RM) $(OBJ)
		$(RM) $(OBJ2)

fclean:		clean
		$(RM) $(NAME)
		rm -rf ./lib/libmy.a

re:		fclean all

.PHONY:		re all fclean clean
