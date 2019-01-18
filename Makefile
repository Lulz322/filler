NAME = iruban.filler


CC = gcc
@CFLAGS = -Wall -Wextra -Werror

SRC = srcs/get_next_line.c srcs/main.c srcs/create_array.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
LMAKE = make -C libft

WHITE=\033[0m
GREEN=\033[32m
RED=\033[31m

DEL = rm -rf

all: $(NAME)

$(OBJ): %.o: %.c
	@echo -n '+'
	@$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT):
	@$(LMAKE)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ)  $(LIBFT) -o $(NAME)
	@echo "> $(GREEN)filler$(WHITE)"

dfd:
	@$(DEL) $(OBJ)

clean:
	@$(DEL) $(OBJ)
	@$(LMAKE) clean

fclean: clean
	@$(LMAKE) fclean
	@$(DEL) $(NAME)
	@echo "$(RED)deleted$(WHITE): ./filler"

re: fclean all

test: all
	 ./resources/filler_vm -f ./resources/maps/map00 -p1 ./iruban.filler


.PHONY: all fclean clean re test
