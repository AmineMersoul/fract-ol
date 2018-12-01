NAME = fractals

SOURCE = *.c 
OFILES = *.o
INCLUDES = fractals.h
LIB = fractals.a

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SOURCE) $(INCLUDES)
	ar rc $(LIB) $(OFILES)
	ranlib $(LIB)

clean:
	rm -f $(OFILES)
	rm -f fractals.h.gch

fclean: clean
	rm -f $(LIB)

re: fclean all