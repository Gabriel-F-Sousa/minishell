LIBFT_PATH = lib/libft
LIBFT = $(LIBFT_PATH)/libft.a
PRINTF_PATH = lib/ft_printf
PRINTF = $(PRINTF_PATH)/ft_printf.a

SRC_FILES = src/main.c src/exec/exec.c src/exec/redirections.c

SOURCES = $(SRC_FILES)
OBJECTS = $(SOURCES:.c=.o)

HEADER = src/minishell.h
NAME = minishell

CC = cc
RM = rm -f
CFLAGS = -g -Wall -Wextra -Werror

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