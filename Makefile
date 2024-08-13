# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 17:44:42 by pdeson            #+#    #+#              #
#    Updated: 2024/04/25 09:21:26 by pdeson           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo
PRINT_PREFIX	= \033[1m\033[38;5;240m[\033[0m\033[38;5;250m\
					$(NAME)\033[1m\033[38;5;240m] \033[38;5;105m~\033[0m

NAME_BONUS			=	philo_bonus
PRINT_BONUS_PREFIX	= \033[1m\033[38;5;240m[\033[0m\033[38;5;250m\
					$(NAME_BONUS)\033[1m\033[38;5;240m] \033[38;5;105m~\033[0m

CC				= @cc
CFLAGS			= -Wall -Werror -Wextra -g3 -fsanitize=address

SRC_DIR			=	srces/
SRC_BONUS_DIR	=	bonus/
OBJ_DIR 		= .obj/

SRC				=	main.c ft_utils.c ft_launch.c ft_init.c ft_error.c
SRC_BONUS		=	main_bonus.c ft_utils_bonus.c ft_launch_bonus.c \
					ft_init_bonus.c ft_error_bonus.c

SRCES			= $(addprefix $(SRC_DIR), $(SRC))
OBJ				= $(SRC:.c=.o)
OBJS    	    = $(addprefix $(OBJ_DIR), $(OBJ))

SRCES_BONUS		= $(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS))
OBJ_BONUS		= $(SRC_BONUS:.c=.o)
OBJS_BONUS 	    = $(addprefix $(OBJ_BONUS_DIR), $(OBJ_BONUS))

NUM_FILES   = $(words $(SRCES))
BAR_LENGTH  = $(shell echo "$$(($(NUM_FILES)*2))")

NUM_BONUS_FILES   = $(words $(SRCES_BONUS))
BAR_BONUS_LENGTH  = $(shell echo "$$(($(NUM_BONUS_FILES)*2))")

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		@printf "$(PRINT_PREFIX)\033[0;38;5;226m Compiling \033[0m["
		@for i in $(shell seq 1 $(BAR_LENGTH)); do \
			sleep 0.02; \
			printf "\033[38;5;40m▲▼"; \
		done
		@printf "\033[38;5;40m] \033[0m\n"
		$(CC) $(CFLAGS) $(OBJS) -lpthread -o $(NAME)
		@echo "$(PRINT_PREFIX)\033[0;32m Done \033[0;32m\n"

bonus: $(NAME_BONUS)

$(OBJ_BONUS_DIR)%.o: $(SRC_BONUS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_BONUS): $(OBJS_BONUS)
		@printf "$(PRINT_PREFIX)\033[0;38;5;226m Compiling Bonus \033[0m["
		@for i in $(shell seq 1 $(BAR_BONUS_LENGTH)); do \
			sleep 0.1; \
			printf "\033[38;5;40m▲▼"; \
		done
		@printf "\033[38;5;40m] \033[0m\n"
		$(CC) $(CFLAGS) $(OBJS_BONUS) -lpthread -o $(NAME_BONUS)
		@echo "$(PRINT_BONUS_PREFIX)\033[0;32m Done \033[0;32m\n"

clean:
		@echo "$(PRINT_PREFIX)\033[0;38;5;226m Cleaning \033[0m\n"
		@rm -rf $(OBJS) $(OBJ_BONUS)
		@echo "$(PRINT_PREFIX)\033[0;32m Done \033[0;32m\n"

fclean: clean
		@rm -rf $(NAME) $(OBJ_DIR)
		@rm -rf $(NAME_BONUS) $(OBJ_BONUS_DIR)

re: fclean all

run: all clean
	./$(NAME)

run_bonus: bonus clean
	./$(NAME_BONUS)

.PHONY: all clean fclean re bonus run run
