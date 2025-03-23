CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
NAME_1		=	client
NAME_2		=	server
NAME_1_SRC	=	mandatory/client.c
NAME_2_SRC	=	mandatory/server.c	mandatory/diplay_banner.c
UTILS		=	mandatory/utils.c
OBJS		=	$(NAME_1_SRC:.c=.o) $(NAME_2_SRC:.c=.o) $(UTILS:.c=.o)

all: $(NAME_1) $(NAME_2)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_1): $(NAME_1_SRC:.c=.o) $(UTILS:.c=.o)
	$(CC) $(CFLAGS) $^ -o $(NAME_1)

$(NAME_2): $(NAME_2_SRC:.c=.o) $(UTILS:.c=.o)
	$(CC) $(CFLAGS) $^ -o $(NAME_2)

clean:
	rm -fr $(OBJS)

fclean:	clean
	rm -fr $(NAME_1) $(NAME_2)

re:	fclean all

.PHONY:	clean
