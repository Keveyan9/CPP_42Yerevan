NAME = megaphone

COMPILER = c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

RM		= rm -rf

.PHONY: all clean re

all: $(NAME)

$(NAME): 
	@ $(COMPILER) $(FLAGS) megaphone.cpp -o $(NAME)
clean:
	@$(RM) $(NAME)
fclean:
	@$(RM) $(NAME)
re: clean all 