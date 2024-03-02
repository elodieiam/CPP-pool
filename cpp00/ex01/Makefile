NAME 	= PhoneBook

CPP 	= c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRC 	= main.cpp Contact.cpp PhoneBook.cpp

OBJ		= $(SRC:.cpp=.o)


all : $(NAME) Contact.hpp PhoneBook.hpp

$(NAME) : $(OBJ)
	@echo "Compiling..." $(NAME)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "Done !"

%.o : %.cpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean : 
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all