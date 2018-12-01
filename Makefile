NAME = fractol

SOURCE = main.c 

MINILIBX = minilibx/
LIBS = libft/libft.a
FLAGS = -lmlx -framework OpenGl -framework AppKit

all: $(NAME)

run:
	cc -I $(MINILIBX) $(SOURCE) $(LIBS) -L $(MINILIBX) $(FLAGS) -o $(NAME)

mlibft:
	cd libft && $(MAKE) re && $(MAKE) clean

$(NAME): mlibft
	cc -I $(MINILIBX) $(SOURCE) $(LIBS) -L $(MINILIBX) $(FLAGS) -o $(NAME)

clean:
	cd libft && $(MAKE) clean

fclean: clean
	cd libft && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all