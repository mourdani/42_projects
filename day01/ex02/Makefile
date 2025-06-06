CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 
NAME = program

SOURCES = main.cpp  

OBJECT = $(SOURCES:.cpp=.o)
all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECT)
	$(CC) $(FLAGS) $(OBJECT) -o $(NAME)

clean:
	rm -rf $(OBJECT)
fclean: clean
	rm -fr $(NAME)
re: fclean all
