NAME = MutantStack

TMP = objs

CXX = c++

CXXFLAGS =  -Wall -Wextra -Werror

SRCS = $(wildcard *.cpp)

OBJS = $(patsubst %.cpp, ./$(TMP)/%.o, $(SRCS))

RM = rm -fr

HEADER = $(wildcard *.hpp)

./$(TMP)/%.o: %.cpp $(HEADER) Makefile
	$(CXX) $(CXXFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(TMP) $(OBJS) $(LIBFT) $(FT_FPRINTF)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LINKER) -o $(NAME)

$(TMP):
	@mkdir $(TMP)

clean:
	$(RM) $(OBJS_DIR)
	$(RM) $(TMP)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
