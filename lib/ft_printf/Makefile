# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabferna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 13:17:35 by gabferna          #+#    #+#              #
#    Updated: 2023/10/26 13:17:36 by gabferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
LIBFTNAME = libft.a
LIBFTDIR = ../libft
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c ft_print_int.c ft_print_hex.c \
	ft_print_unsigned.c ft_print_ptr.c ft_print_str.c

OBJS = $(SRCS:.c=.o)
all: $(NAME)
makelibft:
		@make -C $(LIBFTDIR)
		@cp $(LIBFTDIR)/$(LIBFTNAME) .
		@mv $(LIBFTNAME) $(NAME)
$(NAME): makelibft $(OBJS)
		@ar -rc $(NAME) $(OBJS)
clean:
		@rm -f $(OBJS)
		@cd $(LIBFTDIR) && make clean
fclean: clean
		@rm -f $(NAME)
		@cd $(LIBFTDIR) && make fclean
re: fclean all
