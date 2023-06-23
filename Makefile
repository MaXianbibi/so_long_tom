# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 15:10:32 by tparadis          #+#    #+#              #
#    Updated: 2023/05/27 20:10:20 by tparadis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror
LIBMLX	:= ./MLX42-master
USERS	:= $(shell whoami)

#HEADERS	:= -I ./include -I $(LIBMLX)/include
#LIBS	:= $(LIBMLX)/build/libmlx42.a -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USERS)/homebrew/Cellar/glfw/3.3.8/lib"
LIBS	:= $(LIBMLX)/build/libmlx42.a -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USERS)/.brew/opt/glfw/lib"
LIBFT   := ./libft
LIBFTA 	:= $(LIBFT)/libft.a

SRCS	:= ./src/main.c ./src/hooks.c ./src/parsing.c ./src/control.c ./src/render.c ./src/entity.c ./src/floodfill.c ./src/exit.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx ${LIBFTA} $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

${LIBFTA} : 
				make -C ${LIBFT}


#%.o: %.c
#	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS) $(LIBFTA)
	@$(CC) $(OBJS) $(LIBFTA) $(LIBS) $(LIBFTA) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -f ./libft/*.o
	@rm -f ./libft/getnextline/*.o
	@rm -f ./libft/memory_manager/*.o
	@rm -f ./libft/printf/*.o
	

fclean: clean
	@rm -f $(NAME)
	@rm -f ./libft/libft.a

re: clean all

bonus: all

.PHONY: all, clean, fclean, re, libmlx