NAME = build/tracing

FLAGS = -Wall -Wextra -Werror -g 

SRC = main.cc

OBJ	=	$(SRC:.cc=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ $(FLAGS) -c $(SRC)
	g++ $(FLAGS) $(OBJ) -o build/tracing

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all