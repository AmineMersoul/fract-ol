NAME = fractol

SOURCE = main.c 

MINILIBX = minilibx/
LIBS = libft/libft.a fractals/fractals.a
FLAGS = -lmlx -framework OpenGl -framework AppKit

all: $(NAME)

run:
	cc -I $(MINILIBX) $(SOURCE) $(LIBS) -L $(MINILIBX) $(FLAGS) -o $(NAME)

mlibft:
	cd libft && $(MAKE) re && $(MAKE) clean

mfractals:
	cd fractals && $(MAKE) re && $(MAKE) clean

$(NAME): mlibft mfractals
	cc -I $(MINILIBX) $(SOURCE) $(LIBS) -L $(MINILIBX) $(FLAGS) -o $(NAME)

clean:
	cd libft && $(MAKE) clean
	cd fractals && $(MAKE) clean

fclean: clean
	cd libft && $(MAKE) fclean
	cd fractals && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all