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

fclean:		clean
			@$(RM) $(name)

re:			fclean all

run:		all
			$(CC) $$(CFLAGS) -lftprintf main.c

.PHONY:		all clean fclean re
