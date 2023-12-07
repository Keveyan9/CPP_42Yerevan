# NAME      = phonebook

# CC        = g++ 

# FLAGS     = -Wextra -Werror -Wall -std=c++98

# SRC_FILES = $(wildcard *.cpp)

# OBJ_FILES = $(SRC_FILES:.cpp=.o)

# # %o: %.cpp
# # 		$(CC) $(FLAGS) -c $< -o $@

# all: $(NAME)

# $(NAME): $(OBJ_FILES)
# 		$(CC) $(FLAGS) -o $(NAME) $^

# clean:
# 	rm -rf $(OBJ_FILES)

# fclean: clean
# 	rm -rf $(NAME)

# re: fclean all

# .PHONY: all fclean clean re

NAME = phonebook
CC = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror
RM = rm -rf

SRC = ${wildcard *.cpp}
OBJ = ${patsubst %.cpp, %.o, ${SRC}}

all : ${NAME}

${NAME} : ${OBJ} Makefile *.hpp
	${CC} ${CPPFLAGS} ${OBJ} -o ${NAME}

clean : 
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all bonus clean fclean re