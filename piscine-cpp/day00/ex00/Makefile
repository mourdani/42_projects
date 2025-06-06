CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 
NAME = megaphone
SOURCES = megaphone.cpp	\

OBJECT = $(SOURCES:.cpp=.o)
$(NAME): $(OBJECT)
	$(CC) $(FLAGS) $(SOURCES) -o $(NAME)
all: $(NAME)
clean:
	rm -rf $(OBJECT)
fclean: clean
	rm -fr $(NAME)
re: fclean all
