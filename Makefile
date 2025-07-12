NAMESV		= server
NAMECL		= client
NAMESVB		= serverbonus
NAMECLB		= clientbonus

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= src/
INC_DIR		= include/
LIBFT_DIR	= libft/
OBJ_DIR		= obj/

SRCSV		= $(SRC_DIR)server.c
SRCCL		= $(SRC_DIR)client.c
SRCSVB		= $(SRC_DIR)server_bonus.c
SRCCLB		= $(SRC_DIR)client_bonus.c

HEADERS		= $(INC_DIR)minitalk.h

OBJSSV		= $(SRCSV:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
OBJSCL		= $(SRCCL:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
OBJSSVB		= $(SRCSVB:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
OBJSCLB		= $(SRCCLB:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all:		$(NAMESV) $(NAMECL)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAMESV):	$(OBJSSV)
			make -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(OBJSSV) -L$(LIBFT_DIR) -lft -o $(NAMESV)

$(NAMECL):	$(OBJSCL)
			make -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(OBJSCL) -L$(LIBFT_DIR) -lft -o $(NAMECL)

$(NAMESVB): $(OBJSSVB)
			make -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(OBJSSVB) -L$(LIBFT_DIR) -lft -o $(NAMESVB)

$(NAMECLB): $(OBJSCLB)
			make -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(OBJSCLB) -L$(LIBFT_DIR) -lft -o $(NAMECLB)

clean:
			rm -rf $(OBJ_DIR)
			make -C $(LIBFT_DIR) clean

fclean:		clean
			rm -f $(NAMESV) $(NAMECL) $(NAMESVB) $(NAMECLB)
			make -C $(LIBFT_DIR) fclean

re:			fclean all

bonus : $(NAMESVB) $(NAMECLB)

.PHONY:		all clean fclean re 