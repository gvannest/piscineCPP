#executable
NAME 		= mindopen

#compiler and flags
CXX			= clang++
CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror -g
CPPFLAGS		= -I$(INC_PATH) # -I is a preprocessor flag, not a compiler flag

# PATHS
SRC_PATH = ./cppFiles/
OBJ_PATH = ./objs/
INC_PATH = ./includes/

#sources and objects
SRC_NAMES 	= main.cpp AInstructions.cpp Dec.cpp Inc.cpp Input.cpp MoveLeft.cpp MoveRight.cpp Output.cpp OpenBracket.cpp CloseBracket.cpp
OBJ_NAMES 	= $(SRC_NAMES:.cpp=.o)
HDRS		= AInstructions.hpp Dec.hpp Inc.hpp Input.hpp MoveLeft.hpp MoveRight.hpp Output.hpp OpenBracket.hpp CloseBracket.hpp

# PREFIXES
SRCS = $(addprefix $(SRC_PATH),$(SRC_NAMES))
OBJS = $(addprefix $(OBJ_PATH),$(OBJ_NAMES))
DEPS = $(addprefix $(INC_PATH),$(HDRS))

# Compile and create everything
all: $(OBJ_PATH) $(NAME) $(DEPS) Makefile
	@echo "[INFO] Compilation done"

# Compile the program with the objects
$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	
$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH) 2> /dev/null || true

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS)-o $@ -c $<

# Rule to remove all the object files
clean:
	@rm -f $(OBJS)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
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