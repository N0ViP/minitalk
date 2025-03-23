CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
NAME_1		=	client
NAME_2		=	server
NAME_3		=	client_bonus
NAME_4		=	server_bonus
NAME_1_SRC	=	mandatory/client.c
NAME_2_SRC	=	mandatory/server.c	mandatory/display_banner.c
NAME_3_SRC	=	bonus/client_bonus.c
NAME_4_SRC	=	bonus/server_bonus.c	bonus/display_banner_bonus.c
UTILS		=	mandatory/utils.c mandatory/utils_1.c
UTILS_BONUS	=	bonus/utils_bonus.c bonus/utils_1_bonus.c
OBJS		=	$(NAME_1_SRC:.c=.o) $(NAME_2_SRC:.c=.o) $(UTILS:.c=.o)
OBJS_BONUS	=	$(NAME_3_SRC:.c=.o) $(NAME_4_SRC:.c=.o) $(UTILS_BONUS:.c=.o)

all: $(NAME_1) $(NAME_2)

bonus: $(NAME_3) $(NAME_4)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_1): $(NAME_1_SRC:.c=.o) $(UTILS:.c=.o)
	$(CC) $(CFLAGS) $^ -o $(NAME_1)

$(NAME_2): $(NAME_2_SRC:.c=.o) $(UTILS:.c=.o)
	$(CC) $(CFLAGS) $^ -o $(NAME_2)

$(NAME_3): $(NAME_3_SRC:.c=.o) $(UTILS_BONUS:.c=.o)
	$(CC) $(CFLAGS) $^ -o $(NAME_3)

$(NAME_4): $(NAME_4_SRC:.c=.o) $(UTILS_BONUS:.c=.o)
	$(CC) $(CFLAGS) $^ -o $(NAME_4)

clean:
	rm -fr $(OBJS) $(OBJS_BONUS)

fclean:	clean
	rm -fr $(NAME_1) $(NAME_2) $(NAME_3) $(NAME_4)

re:	fclean all

.PHONY:	all clean fclean re
