# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erwfonta <erwfonta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 13:20:53 by erwfonta          #+#    #+#              #
#    Updated: 2024/06/10 18:49:11 by erwfonta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# Compilation
CC = cc

CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = 	ft_printf.c \
		ft_printf_utils.c \

# Object files
OBJS = $(SRCS:.c=.o)

# Object bonus 
OBJS_B = $(SRCS_B:.c=.o)

# Archives
AR = ar rc 

# rules
all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

.c.o: 
	$(CC) $(CFLAGS) -c -include ft_printf.h $< -o ${<:.c=.o}

bonus: $(OBJS_B)
	$(AR) $(NAME) $(OBJS_B)
	
clean:
	rm -rf ${OBJS} ${OBJS_B}

fclean: clean
	rm -rf $(NAME)

rebonus : fclean bonus

re: fclean all