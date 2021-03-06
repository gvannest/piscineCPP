#executable
NAME 		= ex04

#compiler and flags
CXX			= clang++
CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror -g
CPPFLAGS		= -I$(INC_PATH) # -I is a preprocessor flag, not a compiler flag

# PATHS
SRC_PATH = ./
OBJ_PATH = ./
INC_PATH = ./

#sources and objects
SRC_NAMES 	= main.cpp FragTrap.cpp ScavTrap.cpp ClapTrap.cpp NinjaTrap.cpp SuperTrap.cpp
OBJ_NAMES 	= $(SRCS:.cpp=.o)
HDRS		= FragTrap.hpp ScavTrap.hpp ClapTrap.hpp NinjaTrap.hpp Supertrap.hpp

# PREFIXES
SRCS = $(addprefix $(SRC_PATH),$(SRC_NAMES))
OBJS = $(addprefix $(OBJ_PATH),$(OBJ_NAMES))
DEPS = $(addprefix $(INC_PATH),$(HDRS))

# Compile and create everything
all: $(NAME) $(DEPS)
	@echo "[INFO] Compilation done"

# Compile the program with the objects
$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS)-o $@ -c $<

# Rule to remove all the object files
clean:
	@rm -f $(OBJS)
	@echo "[INFO] Objects removed"

# Rule to remove everything that has been created with the Makefile
fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] $(NAME) removed"

# Rule to remake everything
re:	fclean all

# Makes sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: all clean fclean re