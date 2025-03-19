NAME = so_long

SRC = so_long.c ft_check.c ft_checkmap2.c ft_checkmap3.c ft_startgame.c ft_freemap.c ft_checkmove.c
	
CC = cc -g
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L ./minilibx-linux -lmlx -lX11 -lXext -lm

OBJ = $(SRC:%.c=%.o)
BONUS = $(BNS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C ./libft
		$(MAKE) -C ./minilibx-linux
		@$(CC) $(CFLAGS) $(OBJ) ./libft/libft.a $(MLXFLAGS) -o $(NAME)
		
clean:
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./minilibx-linux
		@$(RM) $(OBJ)
		
fclean: clean
		$(MAKE) fclean -C ./libft
		@$(RM) $(NAME) 
		
re: fclean all
		$(MAKE) re -C ./libft
		$(MAKE) re -C ./minilibx-linux

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	cc -nostartfiles -shared -o libft.so $(OBJ)
