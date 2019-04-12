# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 11:46:21 by jchardin          #+#    #+#              #
#    Updated: 2019/04/12 13:47:19 by naali            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

CC			=	gcc

CFLAGS		=	-Wall -Wextra
#-Werror

SRC			=	main.c						\
				init_struct.c				\
				init_julia.c				\
				init_mandel.c				\
				julia.c						\
				mandelbrot.c				\
				multibrot.c					\
				color_and_pixel.c			\
				convert.c					\
				matrice_init.c				\
				matrice_rot.c				\
				matrice_scal.c				\
				matrice_trans.c				\
				multiply.c					\
				mult_matrice.c				\
				t_vertex.c

OBJ			=	$(SRC:.c=.o)

OBJ_DIR		=	./objs

INCLUDE_P	=	includes/							\
				srcs/libft/

IFLAGS		=	$(addprefix -I./, $(INCLUDE_P))

OBJS		=	$(addprefix $(OBJ_DIR)/, $(OBJ))

LDFLAGS		=	-L./srcs/libft		\
				-L/usr/local/lib

LFLAGS		=	-lft				\
				-lm					\
				-lmlx				\
				-lXext				\
				-lX11


LDLIBS		=	$(LDFLAGS) $(LFLAGS)

vpath %.c ./srcs/:./srcs/matrice:./srcs/draw:./srcs/fractal

$(OBJ_DIR)/%.o:	%.c
				@mkdir $(OBJ_DIR) 2> /dev/null || true
				@echo -n "\033[0;32mCompiling $< ...\c"
				@$(CC) $(CFLAGS) -o $@ -c $^ $(IFLAGS)
				@echo -n " Done                    \r\033[0m"

.PHONY: 		all libft clean fclean re

all:			clearscreen $(NAME)

lib:			libft

$(NAME):		lib $(OBJS)
				@echo -n "\033[0;32mCreation de l'executable...\c"
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(IFLAGS) $(LDLIBS)
				@echo " Done                       \033[0m"

libft:
				@$(MAKE) --no-print-directory -sC ./srcs/libft;

clearscreen:
				clear

clean:
				@$(MAKE) clean --no-print-directory -sC ./srcs/libft
				@echo "\033[0;31mSuppression des fichiers objets...\c"
				@rm -rf $(OBJS)
				@rm -rf $(OBJ_DIR)
				@echo " Done\033[0m"

fclean:			clean
				@$(MAKE) fclean --no-print-directory -sC ./srcs/libft
				@echo "\033[0;31mSuppression de l'executable...\c"
				@rm -rf $(NAME)
				@echo " Done\033[0m"

re:				fclean all
