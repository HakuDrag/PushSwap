NAME = libftprintf.a
LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -f
CP = cp

OBJ_DIR = objs

SRCS = ft_printf.c ft_supports.c ft_print_fd.c \
       ft_format_fd.c ft_float_fd.c
BONUS_SRCS = ft_printf_bonus.c ft_bonus.c ft_supports.c \
             ft_bflags_bonus.c ft_bsupports_bonus.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o)

MANDATORY_MARK = $(OBJ_DIR)/.mandatory_built
BONUS_MARK = $(OBJ_DIR)/.bonus_built

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(MANDATORY_MARK): | $(OBJ_DIR)
	$(RM) $(BONUS_MARK)
	touch $(MANDATORY_MARK)

$(NAME): $(OBJS) $(LIBFT) $(MANDATORY_MARK)
	$(CP) $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus: $(BONUS_MARK)

$(BONUS_MARK): $(BONUS_OBJS) $(LIBFT) | $(OBJ_DIR)
	$(CP) $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(BONUS_OBJS)
	$(RM) $(MANDATORY_MARK)
	touch $(BONUS_MARK)

$(OBJ_DIR)/ft_printf_bonus.o $(OBJ_DIR)/ft_bonus.o $(OBJ_DIR)/ft_bflags_bonus.o $(OBJ_DIR)/ft_bsupports_bonus.o: ft_printf_bonus.h

$(OBJ_DIR)/%.o: %.c ft_printf.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re