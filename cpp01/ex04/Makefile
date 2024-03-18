NAME 	= Sed

CPP 	= c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -MMD

SRC 	= main.cpp

OBJ		= $(SRC:.cpp=.o)

DEP		= $(SRC:.cpp=.d)


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

.PHONY: all clean fclean re

-include $(DEP)