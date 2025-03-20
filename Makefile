CC		=	CC
CFLAGS	=	-Wall -Wextra -Werror
NAME_1	= client
NAME_2	= server

all: $(NAME_1) $(NAME_2)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
