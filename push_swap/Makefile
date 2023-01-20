NAME = push_swap

SRC_FILES = main.c list2.c list.c indexing.c ft_atoi.c error.c count.c \
args_list.c args_check.c alignment.c alignment_together.c

BNS = checker.c count.c alignment.c alignment_together.c error.c ft_atoi.c args_check.c

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
		@make all -C ./Libft
		@make all -C ./ft_printf
		$(CC) $(CFLAGS) $(OBJ) Libft/libft.a ft_printf/libftprintf.a -o $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
		@mkdir -p $(OBJ_DIR)
		@echo "$(YELLOW)Compiling [$@]...$(RESET)"
		$(CC) $(CFLAGS) -I. -o $@ -c $<
		@printf "$(UP)$(CUT)"
		@echo "$(GREEN)Finished [$@]$(RESET)"
		@printf "$(UP)$(CUT)"

bonus: $(OBJ_B)
		@make all -C ./ft_printf
		@make all -C ./Libft
		$(CC) $(CFLAGS) $(OBJ_B) Libft/libft.a ft_printf/libftprintf.a gnl/get_next_line.c gnl/get_next_line_utils.c -o checker

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
