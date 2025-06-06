## Executables name
SERVER		= server
CLIENT		= client

## Sources
SRC_SERVER	= src/server.c
SRC_CLIENT	= src/client.c

## Objects (patsubst = path substitute)
OBJ_SERVER	= ${patsubst src/%, obj/%, $(SRC_SERVER:.c=.o)}
OBJ_CLIENT	= ${patsubst src/%, obj/%, $(SRC_CLIENT:.c=.o)}

## LIBFT config
LIBFT		= $(LIBFT_DIR)libft.a
LIBFT_DIR	= ./libft/
LIB_FLAGS	= -L $(LIBFT_DIR) -lft
INC		= -I ./inc/ -I $(LIBFT_DIR)

## Compiling config
CC		= gcc
RM		= rm -rf
CFLAGS		= -Wall -Werror -Wextra

## Output messages
DONE = @echo "libft compiled successfully!"
CLEAN_O = @echo "Object files removed!"
CLEAN_A = @echo "Executables removed!"
DONE_C = @echo "CLIENT ready to use!"
DONE_S = @echo "SERVER ready to use!"

all:	obj $(CLIENT) $(SERVER)


$(CLIENT): $(OBJ_CLIENT) $(LIBFT)
	@$(CC)  $(CFLAGS) $(OBJ_CLIENT) $(LIB_FLAGS) -o $(CLIENT)
	$(DONE_C)

$(SERVER): $(OBJ_SERVER) $(LIBFT)
	@$(CC)  $(CFLAGS) $(OBJ_SERVER) $(LIB_FLAGS) -o $(SERVER)
	$(DONE_S)

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)

obj:
	@mkdir -p obj

obj/%.o: src/%.c
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@make clean --no-print-directory -C $(LIBFT_DIR)
	@${RM} obj ${OBJ_CLIENT} ${OBJ_SERVER}
	$(CLEAN_O)

fclean:	clean
	@make fclean --no-print-directory -C $(LIBFT_DIR)
	@${RM} ${CLIENT} ${SERVER}
	$(CLEAN_A)

re: fclean all

norm:
	norminette libft/sources libft/includes src inc > norm.log

.PHONY:	all clean fclean re obj 
