# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 16:36:01 by omoreno-          #+#    #+#              #
#    Updated: 2023/01/30 14:49:19 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo
NAMEB := ${addsuffix _bonus, $(NAME)}

all : $(NAME)
bonus : $(NAMEB)

$(NAME) :
	make -C philo

$(NAMEB):
	make -C philo_bonus

clean :
	make -C philo clean
	make -C philo_bonus clean

fclean : clean
	make -C philo fclean
	make -C philo_bonus fclean

re: fclean all

.PHONY : $(NAME) $(NAMEB) clean fclean re all bonus