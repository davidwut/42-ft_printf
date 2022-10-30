NAME	:= libftprintf.a

SRCS	:= $(filter-out main.c, $(wildcard *.c))
OBJS	:= $(SRCS:.c=.o)

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
AR		:= ar -rcsv
RM		:= rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJS)
			@$(RM) main.o

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) a.out

re:			fclean all

run:		all
			$(CC) $$(CFLAGS) main.c $(NAME)
			./a.out

.PHONY:		all clean fclean re run
