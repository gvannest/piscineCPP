#executable
NAME 		= megaphone

#compiler and flags
CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror

# PATHS
SRC_PATH = ./
OBJ_PATH = ./

#sources and objects
SRC_NAMES 	= megaphone.cpp
OBJ_NAMES 	= $(SRCS:.cpp=.o)

# PREFIXES
SRCS = $(addprefix $(SRC_PATH),$(SRC_NAMES))
OBJS = $(addprefix $(OBJ_PATH),$(OBJ_NAMES))

# Compile and create everything
all: $(NAME)
	@echo "[INFO] Compilation done"

# Compile the program with the objects
$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

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