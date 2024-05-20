NAME = templates

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -MMD -g3

SRC = main.cpp Span.cpp

SRC_DIR = ./
SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.cpp=.o)))
DEPS = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.cpp=.d)))

all: $(NAME)

$(NAME): $(OBJS) 
	@echo "Compiling..." $(NAME)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "Done !"

-include $(DEPS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
