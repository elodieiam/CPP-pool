NAME 	= PhoneBook

CPP 	= c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRC 	= main.cpp Contact.cpp PhoneBook.cpp

OBJ		= $(SRC:.cpp=.o)


all : $(NAME)

$(NAME) : $(OBJ)
	@echo "Compiling..." $(NAME)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "Done !"

%.o : %.cpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean : 
	@rm -rf $(OBJ) $(DEP)

fclean : clean
	@rm -rf $(NAME)

re : fclean all