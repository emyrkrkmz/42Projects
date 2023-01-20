
NAME = push_swap

SRC_FILES = main.c bs_p1.c big_sorting.c indexing.c ft_atoix.c errors.c preparing_to_array.c \
small_sorts.c check_input.c single_operators.c multiple_operators.c

BNS = checker.c preparing_to_array.c single_operators.c multiple_operators.c errors.c ft_atoix.c check_input.c

RESET	=	\033[0m
UP		=	\033[A
CUT		=	\033[K
GREEN	=	\033[0;92m
YELLOW	=	\033[33m

SRC_DIR = ./

OBJ_DIR = Object/

OBJ_SRC = $(SRC_FILES:.c=.o)

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_SRC))

OBJ_BNS = $(BNS:.c=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_B = $(addprefix $(OBJ_DIR), $(OBJ_BNS))

CC = @gcc

CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ)
		@make all -C ./libft
		@make all -C ./ft_printf
		$(CC) $(CFLAGS) $(OBJ) libft/libft.a ft_printf/libftprintf.a -o $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
		@mkdir -p $(OBJ_DIR)
		@echo "$(YELLOW)Compiling [$@]...$(RESET)"
		$(CC) $(CFLAGS) -I. -o $@ -c $<
		@printf "$(UP)$(CUT)"
		@echo "$(GREEN)Finished [$@]$(RESET)"
		@printf "$(UP)$(CUT)"

bonus: $(OBJ_B)
		@make all -C ./ft_printf
		@make all -C ./libft
		$(CC) $(CFLAGS) $(OBJ_B) libft/libft.a ft_printf/libftprintf.a gnl/get_next_line.c gnl/get_next_line_utils.c -o checker

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_B)
	rm -rf main.o
	make -C ./ft_printf clean

fclean: clean
	rm -rf $(OBJ_DIR) $(NAME)
	make -C ./ft_printf fclean
	rm -rf checker

re: fclean all

.PHONY: all re clean fclean