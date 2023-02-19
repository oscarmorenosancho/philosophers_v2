# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 16:36:01 by omoreno-          #+#    #+#              #
#    Updated: 2023/02/16 13:51:01 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo

SRC := philo.c\
forks.c\
print_mutex.c\
done_cntdwn_mutex.c\
threads.c\
ft_swap.c\
ft_init_philo.c\
ft_check_finish.c\
ft_philo_sleeps.c\
ft_philo_thinks.c\
ft_philo_eats.c\
ft_philo_behavior.c\
ft_check_n_get_arg.c\
ft_take_args.c\
ft_atoi.c\
ft_itoa.c\
ft_strlen.c\
ft_strncmp.c\
ft_time_diff.c\
ft_print_event.c\
ft_update_dead.c\
ft_get_timestamp.c

OBJ := $(SRC:.c=.o)
DEPS := $(SRC:.c=.d)
CC	:= 	gcc
CFLAGS := -Wall -Werror -Wextra
LFLAGS := -pthread
CFD := -MMD
RM	:= 	rm -f
HEADER := philo.h

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