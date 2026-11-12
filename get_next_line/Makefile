NAME = get_next_line.a
BONUS_NAME = get_next_line_bonus.a
CC = cc
AR = ar
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE = 42

SRCS = get_next_line.c get_next_line_utils.c
BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

$(BONUS_NAME): $(BONUS_OBJS)
	$(AR) rcs $(BONUS_NAME) $(BONUS_OBJS)

bonus: $(BONUS_NAME)

get_next_line.o get_next_line_utils.o: get_next_line.h
get_next_line_bonus.o get_next_line_utils_bonus.o: get_next_line_bonus.h

%.o: %.c
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@


clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
