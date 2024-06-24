# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erwfonta <erwfonta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 13:20:53 by erwfonta          #+#    #+#              #
#    Updated: 2024/06/24 15:12:33 by erwfonta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# Compilation
CC = cc

CFLAGS = -Wall -Wextra -Werror -Iincludes

#Directories
SRCDIR = srcs
INCDIR = includes

# Source files
SRCS = 	ft_printf.c \
		ft_printf_utils.c \

# Object files
OBJS = $(addprefix $(SRCDIR)/,$(SRCS:.c=.o))

# Archives
AR = ar rc 

# rules
all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -rf ${OBJS} ${OBJS_B}

fclean: clean
	rm -rf $(NAME)

re: fclean all