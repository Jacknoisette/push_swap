# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 15:17:46 by jdhallen          #+#    #+#              #
#    Updated: 2024/12/20 17:23:37 by jdhallen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)
LFLAGS = -L$(LIBFT_DIR) -lft

NAME = push_swap.a
executable = push_swap
LIBFT_DIR = Libft

SRCS = main.c swap.c push.c reverse_rotate.c rotate.c analyst.c \
	analyst_utils.c triplet.c quintuplet.c chunks.c\
	turkey.c turkey_utils.c neighbors.c ft_atol.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME) $(executable)

$(NAME):
	@$(MAKE) -C $(LIBFT_DIR)
	echo "make ok"

$(executable): $(NAME) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(executable) $(LFLAGS)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)
	echo "clean ok"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@rm -f $(executable)
	echo "fclean ok"

re: fclean all

.PHONY: all clean fclean re
