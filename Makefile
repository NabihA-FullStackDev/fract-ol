#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naali <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 14:27:18 by naali             #+#    #+#              #
#    Updated: 2019/05/03 14:58:39 by naali            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fractol

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

IFLAGS		=	-Iincludes -Ilibft

SRC			=	main.c				\
				event.c				\
				init_struct.c		\
				color_and_pixel.c	\
				init_julia.c		\
				init_mandel.c		\
				mandeltest.c		\
				julia.c				\
				mandelbrot.c		\
				multibrot.c			\
				convert.c			\
				matrice_init.c		\
				matrice_rot.c		\
				matrice_scal.c		\
				matrice_trans.c		\
				mult_matrice.c		\
				multiply.c			\
				t_vect.c			\
				t_vertex.c


OBJ			=	$(SRC:.c=.o)

OBJ_PATH	=	./obj

OBJS		=	$(addprefix $(OBJ_PATH)/, $(OBJ))

vpath %.c ./srcs/:./srcs/draw:./srcs/fractal:./srcs/matrice

LIBPATH		=	./libft

LDFLAGS		=	-L$(LIBPATH)

LFLAGS		=	-lmlx	\
				-lm		\
				-lft

LDLIBS		=	$(LDFLAGS) $(LFLAGS)

FFLAGS 		=	-framework OpenGL -framework Appkit

$(OBJ_PATH)/%.o:	%.c
			@mkdir $(OBJ_PATH) 2> /dev/null || true
			@echo "Compiling $< ...\c"
			@$(CC) $(CFLAGS) -o $@ -c $^ $(CFLAGS) $(IFLAGS)
			@echo " DONE"

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(MAKE) -C $(LIBPATH)
			@echo "Compiling $(NAME) ...\c"
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(IFLAGS) $(LDLIBS) $(FFLAGS)
			@echo " DONE"

clean:
			@$(MAKE) clean -C $(LIBPATH)
			@echo "cleaning the obj file ...\c"
			@rm -rf $(OBJS)
			@echo " DONE"

fclean:		clean
			@$(MAKE) fclean -C $(LIBPATH)
			@echo "cleaning the executable ...\c"
			@rm -rf $(OBJ_PATH)
			@rm -rf $(NAME)
			@echo " DONE"

re:			fclean all
