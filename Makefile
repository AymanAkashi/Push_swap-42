NAME = push_swap
EXEC_BONUS = checker

BONUS_DIR = bonus

SRCS_DIR = srcs
INCLUDE = include
SRCS = push_swap.c \
		 check.c \
		 big_algo.c \
		 short_algo.c \
		 move.c \
		 norm.c \
		 list_sort.c \
		 inst.c \
		get.c \
		ft_lst.c \
		case.c \
		free.c
BONUS = checker.c check.c ft_lst.c inst.c move.c lst_checker.c

LIB_DIR = libft/

OBJS :=$(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
OBJS_BONUS := $(BONUS:.c=.o)
all: $(NAME)

$(NAME): libft $(OBJS)
		gcc $(CFLAGS) $(OBJS) -Lft_libft -lft -o ${NAME}

%.o: ${SRCS_DIR}/%.c
		gcc $(CFLAGS) -c $< -I$(INCLUDE) -o $@
libft:
		cd ft_libft && make && make clean

bonus : libft $(OBJS_BONUS)
		gcc $(CFLAGS) $(OBJS_BONUS) -Lft_libft -lft -o ${EXEC_BONUS} 

%.o: ${BONUS_DIR}/%.c
		gcc $(CFLAGS) -c $< -I$(INCLUDE) -o $@
clean:
		rm -rf $(OBJS) $(OBJS_BONUS)
fclean: clean
		rm -rf $(NAME) $(BONUS) $(OBJS_BONUS)
re: fclean all
.PHONY: all clean fclean re
