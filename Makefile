### COLORS ###
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

### VARIABLES ###

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -ggdb3
INCLUDE = include/push_swap.h
OBJF = .cache_exists
NBR = 1000		# Change the number of elements to sort in 'make test'

# Directories
MAIN_DIR = src/
UTILS_DIR = src/utils/
INST_DIR = src/instructions/
ALGO_DIR = src/algo/
OBJ_DIR = obj/

# Source Files
MAIN_FILE = main.c
UTILS_FILES = check_args.c utils.c
INST_FILES = swap.c push.c rotate.c
ALGO_FILES = sort.c sort_utils.c chunks.c small_stack.c small_stack_utils.c
MAIN = $(addprefix $(MAIN_DIR), $(MAIN_FILE))
UTILS = $(addprefix $(UTILS_DIR), $(UTILS_FILES))
INST = $(addprefix $(INST_DIR), $(INST_FILES))
ALGO = $(addprefix $(ALGO_DIR), $(ALGO_FILES))

# Object Files
MAIN_OBJ = $(addprefix $(OBJ_DIR), $(MAIN_FILE:.c=.o))
UTILS_OBJ = $(addprefix $(OBJ_DIR), $(UTILS_FILES:.c=.o))
INST_OBJ = $(addprefix $(OBJ_DIR), $(INST_FILES:.c=.o))
ALGO_OBJ = $(addprefix $(OBJ_DIR), $(ALGO_FILES:.c=.o))

### COMPILATION ###

$(OBJF):
	@mkdir -p $(OBJ_DIR)

# Creating object files (.o) from source files (.c) inside the OBJ_DIR directory.
# The option -o indicates the name of the outpout, the option -c indicates the source that is used.

$(OBJ_DIR)%.o : $(MAIN_DIR)%.c $(INCLUDE) | $(OBJF)
	@echo "$(YELLOW)Compiling $<...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o : $(UTILS_DIR)%.c $(INCLUDE) | $(OBJF)
	@echo "$(YELLOW)Compiling $<...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o : $(INST_DIR)%.c $(INCLUDE) | $(OBJF)
	@echo "$(YELLOW)Compiling $<...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o : $(ALGO_DIR)%.c $(INCLUDE) | $(OBJF)
	@echo "$(YELLOW)Compiling $<...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Compiling all objets files (.o) to a file "NAME" :
$(NAME) : $(MAIN_OBJ) $(UTILS_OBJ) $(INST_OBJ) $(ALGO_OBJ)
	@$(MAKE) -C ./src/libft
	@echo "$(CYAN)libft compiled!$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $^ ./src/libft/libft.a -o $@
	@echo "$(GREEN)-> push_swap compiled!$(DEF_COLOR)"

### RULES ###

all : $(NAME)

clean :
	@echo "$(YELLOW)Cleaning libft... $(DEF_COLOR)"
	@$(MAKE) -C ./src/libft fclean
	@echo "$(BLUE)libft files cleaned!$(DEF_COLOR)"
	@rm -rf $(OBJ_DIR)
	@rm -rf $(MAIN:.c=.o)
	@echo "$(BLUE)push_swap object files cleaned!$(DEF_COLOR)"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(BLUE)push_swap executable files cleaned!$(DEF_COLOR)"

re : fclean all
	@echo "$(CYAN)Cleaned and rebuilt everything for push_swap!$(DEF_COLOR)"

test: $(NAME)	
	$(eval ARG = $(shell shuf -i 0-5000 -n $(NBR) | tr '\n' ' '))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re test
