# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 16:36:01 by omoreno-          #+#    #+#              #
#    Updated: 2023/02/16 13:19:28 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo_bonus

SRC := philo_bonus.c\
ft_atoi_bonus.c\
ft_itoa_bonus.c\
ft_strncmp_bonus.c\
ft_check_n_get_arg_bonus.c\
ft_take_args_bonus.c\
ft_strlen_bonus.c\
ft_time_diff_bonus.c\
ft_print_event_bonus.c\
ft_get_timestamp_bonus.c\
ft_update_dead_bonus.c\
ft_philo_behavior_bonus.c\
sem_bonus.c

OBJ := $(SRC:.c=.o)
DEPS := $(SRC:.c=.d)
CC	:= 	gcc
CFLAGS := -Wall -Werror -Wextra
LFLAGS := -pthread
CFD := -MMD
RM	:= 	rm -f
HEADER := philo_bonus.h

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} ${CFD} -I ${HEADER} -c $< -o $@

all : $(NAME)

-include $(DEPS)
$(NAME) : ${OBJ} 
	${CC} ${CFLAGS} ${LFLAGS} -I ${HEADER} ${OBJ} -o $@

clean :
	$(RM) $(OBJ)
	$(RM) $(DEPS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY : clean fclean re all bonus