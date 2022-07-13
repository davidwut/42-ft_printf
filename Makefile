RED			:=\033[0;31m
PURPLE		:=\033[0;35m
NC			:=\033[0m

SRC_DIR		:= srcs/
HEAD_DIR	:= includes/

MAIN		:= $(SRC_DIR)/main.c
M_OBJ		:= $(MAIN:%.c=%.o)
SRC			:= ft_printf.c
SRCS		:= $(addprefix $(SRC_DIR),$(SRC))
OBJS		:= $(SRCS:%.c=%.o)
HEAD		:= libft.a
HEADS		:= $(addprefix $(HEAD_DIR),$(HEAD))
ALL_OBS		:= $(OBJS) $(M_OBJ)

NAME		:= libftprintf.a
EXE			:= ft_printf

RM			:= rm -f
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
AR			:= ar -rcs

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $(<:%.c=%.o)

$(NAME):	$(ALL_OBS)
			ar -x $(HEADS) && mv *.o $(HEAD_DIR)
			ar -rcs $(NAME) $(HEAD_DIR)*.o $(OBJS)



clean:
			$(RM) $(ALL_OBS)
			$(RM) $(HEAD_DIR)*.o

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(EXE)

re:			fclean all

run:		all
			$(CC) -o $(EXE) $(M_OBJ) -L. -l ftprintf
			@echo "$(PURPLE)Running$(NC)"
			@./$(EXE)

.PHONY:		all clean fclean re run
