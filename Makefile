NAME = libftprintf.a

# Compilation

CC = gcc

# C Flags

CFLAGS = -Wall -Wextra -Werror

# Sources Files

SRCS =	ft_printf_utils.c \
		ft_printf.c \

# Objects Files

OBJS = $(SRCS:.c=.o)

# Archives

AR = ar rc

# rules

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all