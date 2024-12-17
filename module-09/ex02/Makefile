####

NAME = PmergeMe

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -O2
DEBUGFLAGS = -DDEBUG=1 -g -fsanitize=address

CXX = c++

SRCS = main.cpp PmergeMe.cpp

OBJS_DIR = .objs/

####

OBJ = $(SRCS:.cpp=.o)

OBJS = $(addprefix $(OBJS_DIR), $(OBJ))

DEPS = $(OBJS:.o=.d)

####

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

debug : CXXFLAGS += $(DEBUGFLAGS)
debug : clean $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

all : $(NAME)

$(OBJS_DIR)%.o : %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJS_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re debug

