# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 09:40:16 by kaisuzuk          #+#    #+#              #
#    Updated: 2025/04/25 10:14:19 by kaisuzuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc 
FLAG = -Wall -Werror -Wextra -Iincludes
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	rm -rf $(OBJS)
	
%.o: %.c
	$(CC) -c $(FLAG) $< -o $@

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:  clean fclean re