NAME = test
SRC_DIR = src/
SRC_FILES = main.c images.c get_next_line.c get_next_line_utils.c map.c mapp.c actions.c map_check.c map_check_sec.c map_check_third.c ft_utils.c
CC = cc
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# Updated pattern rule to match source files in SRC_DIR
$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -Imlx -Iincludes -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
