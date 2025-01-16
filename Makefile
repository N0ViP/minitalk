CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = minitalk
CLIENT = client
SERVER = server
EXIT_MESSAGE = exit_messages
BANNER = banner
SRC = src
UTILS = utils
SRC_BONUS = src_bonus
UTILS_BONUS = utils_bonus
INCLUDE = include
FT_PRINTF_INCLUDE = ft_printf/include
INCLUDE_BONUS = include_bonus
FT_PRINTF = ft_printf/libftprintf.a
OBJECTS = objects

vpath %.c $(UTILS) $(SRC)
vpath %_bonus.c $(UTILS_BONUS) $(SRC_BONUS)
vpath %.o $(OBJECTS)

all : $(NAME)

$(NAME) : $(FT_PRINTF) $(addsuffix .o, $(CLIENT) $(SERVER) $(EXIT_MESSAGE) $(BANNER))
	$(CC) $(FLAGS) $(addsuffix .o, $(addprefix $(OBJECTS)/, $(CLIENT) $(EXIT_MESSAGE))) $(FT_PRINTF) -o $(CLIENT)
	$(CC) $(FLAGS) $(addsuffix .o, $(addprefix $(OBJECTS)/, $(SERVER) $(BANNER) $(EXIT_MESSAGE))) $(FT_PRINTF) -o $(SERVER)
	touch $(NAME)

bonus : $(FT_PRINTF) $(addsuffix _bonus.o, $(CLIENT) $(SERVER) $(EXIT_MESSAGE) $(BANNER))
	$(CC) $(FLAGS) $(addsuffix _bonus.o, $(addprefix $(OBJECTS)/, $(CLIENT) $(EXIT_MESSAGE) $(FT_ATOI))) $(FT_PRINTF) -o $(CLIENT)_bonus
	$(CC) $(FLAGS) $(addsuffix _bonus.o, $(addprefix $(OBJECTS)/, $(SERVER) $(BANNER) $(EXIT_MESSAGE))) $(FT_PRINTF) -o $(SERVER)_bonus
	touch bonus

%.o : %.c | objects
	$(CC) $(FLAGS) -c $< -o $(OBJECTS)/$@ -I $(INCLUDE) -I $(INCLUDE_BONUS) -I $(FT_PRINTF_INCLUDE)

objects :
	mkdir -p objects

$(FT_PRINTF) :
	make -C ft_printf

clean :
	rm -rf $(OBJECTS)
	make clean -C ft_printf

fclean : clean
	rm -f minitalk bonus $(SERVER) $(CLIENT) $(CLIENT)_bonus $(SERVER)_bonus
	make fclean -C ft_printf

re : fclean all
