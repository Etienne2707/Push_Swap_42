NAME = push_swap

SRC_DIR = src

INCLUDES = ./includes

BIN_DIR = bin/

SRC =	$(SRC_DIR)/main.c      \
		$(SRC_DIR)/checker2.c		\
		$(SRC_DIR)/cmd1.c	\
		$(SRC_DIR)/cmd2.c 	\
		$(SRC_DIR)/free.c 	\
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/sort_check.c 		\
		$(SRC_DIR)/sort_x100_x500.c \
		$(SRC_DIR)/utils.c		\
		$(SRC_DIR)/utils2.c    \
		$(SRC_DIR)/tiny_sort.c  \


OBJ = $(SRC:$(SRC_DIR)/%.c=$(BIN_DIR)%.o)

CC = cc

CFLAGS =	-I$(INCLUDES) -Wall -Wextra -Werror

all :	$(NAME)

$(BIN_DIR)%.o : $(SRC_DIR)/%.c
		@ $(CC) -I$(INCLUDES) -c $< -o $@

$(NAME) :	$(BIN_DIR) $(OBJ)
			@ $(CC) $(CFLAGS) $(OBJ) -o $(NAME)
			@ echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mDone ! ✅"

$(BIN_DIR) :
		@ mkdir -p $(BIN_DIR)

clean :
		@ rm -f $(OBJ)
		@ rm -rf $(BIN_DIR)
		@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRemove binary files .. 🧹"

fclean : clean
		@ rm -f $(NAME)
		@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRemove executable .. 🗑️"

re :
	@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRecompile .. 🔄"
	@ $(MAKE) -s fclean all

.PHONY: all clean fclean re