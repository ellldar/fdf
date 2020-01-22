NAME = fdf
SRCS = fdf.c
FLGS = -Wall -Werror -Wextra
HDR = -I . -I /minilibx_macos
LIBS = -L ./libft -lft -L ./minilibx_macos/ -lmlx
LIBFT = libft
MLX = -framework OpenGL -framework AppKit

.PHONY: all clean fclean re libft

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	gcc -o $(NAME) $(SRCS) $(HDR) $(LIBS) $(MLX)

$(LIBFT):
	make -C $(LIBFT) re

clean:
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRCS) $(HDR)
