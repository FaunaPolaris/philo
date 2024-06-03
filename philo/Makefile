NAME		=	philo
CC			=	gcc -Wall -Wextra -Werror
DEBUG_F		=	-g3 -ggdb

LIB_LINK	=	-pthread

MAIN		=	main.c

INCLUDES	=	-I includes/

SOURCES		=	mem_calloc environment_init put_philo environment_end philo_brain panopticon_tower pick_fork
SOURCES		+=	say_state_change
SOURCES		:=	$(addprefix sources/, $(SOURCES))
SOURCES		:=	$(addsuffix .c, $(SOURCES))


all: $(NAME)

$(NAME):
	@$(CC) $(DEBUG_F) $(LIB_LINK) $(SOURCES) $(MAIN) $(INCLUDES) -o $@

fclean:
	@rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re
