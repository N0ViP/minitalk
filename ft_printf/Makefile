CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = src/ft_fill_with_padding.c	src/ft_putchar.c	src/ft_putint.c	src/ft_putstr.c	\
	src/ft_printf.c	src/ft_puthex.c	src/ft_putptr.c	src/ft_putuint.c

UTILS = utils/ft_atoi.c	utils/ft_max_min_abs.c	utils/ft_printf_utils.c	utils/ft_strlen.c	\
	utils/ft_length_of_numbers.c	utils/ft_memset.c	utils/ft_strchr.c

SRC_OBJS = $(SRC:.c=.o)

UTILS_OBJS = $(UTILS:.c=.o)

INCLUDE = include

NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(SRC_OBJS) $(UTILS_OBJS)
	ar rcs $(NAME) $(SRC_OBJS) $(UTILS_OBJS)

bonus : all

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDE)

clean :
	rm -f $(SRC_OBJS) $(UTILS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
