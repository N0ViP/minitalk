CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
NAME_1		=	client
NAME_2		=	server
NAME_1_SRC	=	client.c
NAME_2_SRC	=	server.c

all: $(NAME_1) $(NAME_2)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_1): client.o
	$(CC) $(CFLAGS) client.o -o $(NAME_1)

$(NAME_2): server.o
	$(CC) $(CFLAGS) server.o -o $(NAME_2)

clean:
	rm -fr client.o server.o client_bonus.o server_bonus.o

fclean:	clean
	rm -fr client server client_bonus server_bonus

re:	fclean all

.PHONY:	clean
