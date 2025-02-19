# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 17:47:40 by jaacosta          #+#    #+#              #
#    Updated: 2025/02/13 21:47:31 by jaacosta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC	= gcc
#CFLAGS	= -g
CFLAGS	= -Wall -Wextra -Werror -g
AR	= ar -rcs
RM	= rm -rf

SRCS 	=  fractol.c fractal_inits.c process.c utils.c actions.c
	  
SRC_PATH = ./src/
OBJ_PATH = ./tmp/
H_PATH	 = ./headers

HEADERS  = -I$(H_PATH)

DIRSRC	 = $(addprefix $(SRC_PATH), $(SRCS))
OBJS 	 = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

all	:	makelib makeminilib $(OBJ_PATH) $(NAME)

makelib	:	
		$(MAKE) -C libft 
		
makeminilib :	
		$(MAKE) -C minilibx-linux

$(OBJ_PATH):
		mkdir -p $(OBJ_PATH)
		echo "Directorio $(OBJ_PATH) creado."

$(NAME)	:	$(OBJS) 
		$(CC) $(CFLAGS) $(OBJS) libft/libft.a minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a -lX11 -lXext -o $(NAME)
		#$(CC) $(CFLAGS) $(OBJS) libft/libft.a -Lminilibx-linux -lmlx_linux -lX11 -lXext -o $(NAME)

$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c Makefile libft/libft.a 
			mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@


clean	:
		$(RM) $(OBJ_PATH)
		$(MAKE) -C libft clean
		$(MAKE) -C minilibx-linux clean

fclean	:
		$(RM) $(NAME) $(OBJ_PATH)
		$(MAKE) -C libft fclean
		$(MAKE) -C minilibx-linux clean

re	:
		make fclean 
		make all 
		
.PHONY	:	makelib makeminilib all clean fclean re
