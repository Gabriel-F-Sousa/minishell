LIBFT_PATH = lib/libft
LIBFT = $(LIBFT_PATH)/libft.a
PRINTF_PATH = lib/ft_printf
PRINTF = $(PRINTF_PATH)/ft_printf.a

SRC_FILES = src/main.c src/exec/exec.c src/exec/exec_utils.c \
			src/exec/redirections.c src/exec/redirections_utils.c src/exec/redirections_utils_2.c \
			src/exec/pipe_utils.c src/exec/pipe_utils_2.c src/exec/pipe_exec.c \
			src/exec/command_utils.c src/exec/command_args.c src/exec/path_utils.c \
			src/pars/space_prompt.c src/pars/tokens_func.c src/pars/tokens_type.c src/pars/minishell.c \
			src/pars/token_expander.c src/pars/token_utils.c

SOURCES = $(SRC_FILES)
OBJECTS = $(SOURCES:.c=.o)

HEADER = src/minishell.h
NAME = minishell

CC = cc
RM = rm -f
CFLAGS = -g -Wall -Wextra -Werror
# CFLAGS = -g 

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJECTS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(PRINTF) -o $(NAME)
	
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(PRINTF):
	$(MAKE) -C $(PRINTF_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean
	$(RM) $(OBJECTS) 

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(PRINTF_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft printf