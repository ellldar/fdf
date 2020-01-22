NAME = fdf
SRCS = fdf.c
FLGS = -Wall -Werror -Wextra
HDR = -I.
LIBFT_DIR = libft
LIBX_DIR = minilibx_macos
LIBS = -L ./$(LIBFT_DIR) -lft -L ./$(LIBX_DIR) -lmlx
LIBFT = $(LIBFT_DIR)/libft.a
LIBX = $(LIBX_DIR)/libmlx.a
MLX = -framework OpenGL -framework AppKit
INPUT = empty.fdf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(LIBX) $(INPUT)
	gcc -o $(NAME) $(SRCS) $(HDR) $(LIBS) $(MLX)
	./$(NAME) $(INPUT)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(LIBX):
	@make -C $(LIBX_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(LIBX_DIR) clean

fclean: clean
	rm -f $(LIBFT)
	rm -f $(LIBX)
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRCS) $(HDR)
