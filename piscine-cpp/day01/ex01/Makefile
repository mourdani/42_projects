CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 
NAME = zombie 

HEADERS = Zombie.hpp
SOURCES = newZombie.cpp \
	  randomChump.cpp \
	  zombieHorde.cpp \
	  Zombie.cpp \
	  main.cpp  

OBJECT = $(SOURCES:.cpp=.o)
all: $(NAME)

%.o: %.cpp %.hpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECT)
	$(CC) $(FLAGS) $(OBJECT) -o $(NAME)

clean:
	rm -rf $(OBJECT)
fclean: clean
	rm -fr $(NAME)
re: fclean all
