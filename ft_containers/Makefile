NAME = a.out

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

ifeq ($(f), f)
	CFLAGS += -fsanitize=address -g3
endif

SRCS_FILES = main.cpp
CONTAINERS = RandomIte vector map
CONTAINERS_FILES = base ${CONTAINERS} \
				   ReverseIte mapIte
HEADER_FILES = ${addsuffix .hpp, ${CONTAINERS_FILES}}

OBJS_PATH = ./obj/
OBJS = ${addprefix ${OBJS_PATH}, ${SRCS_FILES:.cpp=.o}}

all:
	@printf "$(BOLD)Make $(RED)$(NAME)$(EOC)"
	@echo " $(BOLD)with$(EOC) $(GREEN)$(CC)$(EOC) $(CYAN)$(CFLAGS)$(EOC): "
	@make ${NAME}

$(NAME): ${OBJS_PATH} ${OBJS} ${HEADER_FILES}
	@echo ""
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS}

${OBJS_PATH}:
	@mkdir -p $@

${OBJS_PATH}%.o: %.cpp ${HEADER_FILES}
	@${CC} ${CFLAGS} -c $< -o $@
	@printf "$(YELLOW)▓$(EOC)"

clean:
	@echo "$(BOLD)$(YELLOW)Remove objs.... |$(GREEN)| done$(EOC)"
	@rm -rf ${OBJS_PATH}

fclean: clean
	@echo "$(BOLD)$(YELLOW)Remove all..... |$(GREEN)| done$(EOC)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re