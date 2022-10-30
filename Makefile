name	:= libftprintf.a

SRCS	:= $(filter-out main.c, $(wildcard *.c))
OBJS	:= $(SRCS:.c=.o)

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
AR		:= ar -rcsv
RM		:= rm -f

all:		$(name)

$(name):	$(OBJS)
			@$(AR) $(name) $(OBJS)

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJS)
			@$(RM) main.o

fclean:		clean
			@$(RM) $(name)
			@$(RM) a.out

re:			fclean all

run:		all
			$(CC) $$(CFLAGS) main.c $(name)
			./a.out

.PHONY:		all clean fclean re run
