NAME      = Hi_This_Is_Brain

CC = c++

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror
RM = rm -rf

SRC = ${wildcard *.cpp}
OBJ = ${patsubst %.cpp, %.o, ${SRC}}

all : ${NAME}

${NAME} : ${OBJ} Makefile 
	${CC} ${CPPFLAGS} ${OBJ} -o ${NAME}

clean : 
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all bonus clean fclean re