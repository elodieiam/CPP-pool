NAME 	= account

CPP 	= c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRC 	= tests.cpp Account.cpp

OBJ		= $(SRC:.cpp=.o)


all : $(NAME) Account.hpp

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