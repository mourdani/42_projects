CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98 
NAME = phonebook

HEADERS = phonebook.hpp \
	  Contact.class.hpp \
	  Phonebook.class.hpp \

SOURCES = phonebook.cpp	\
	  Contact.class.cpp \
	  Phonebook.class.cpp \
	  main.cpp

OBJECT = $(SOURCES:.cpp=.o)
all: $(NAME)

%.o: %.cpp %.hpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECT) $(HEADERS)
	$(CC) $(FLAGS) $(OBJECT) -o $(NAME)

clean:
	rm -rf $(OBJECT)
fclean: clean
	rm -fr $(NAME)
re: fclean all
