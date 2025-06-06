NAME = push_swap
SRCS =			sources/main.c\
					actions/push.c\
					actions/rotate_a.c\
					actions/rotate.c\
					actions/rotate_b.c\
					actions/swap.c\
					sources/chunk.c\
					sources/arrange_a_b.c\
					sources/get_big_small.c\
					sources/get_h_first_sec.c\
					sources/init.c\
					sources/sort_others.c\
					sources/sort_five.c\
					sources/quicksort.c\
					sources/sort.c\
					sources/errors.c\
					sources/libft_utils.c\
					sources/utils.c

INCLUDES = includes

OBJS = ${SRCS:.c=.o}
CC		= gcc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror
.c.o:
		${CC} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJS}
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
