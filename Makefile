NAME        = push_swap
BONUS_NAME   = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

FT_PRINTF_DIR = ft_printf
LIBFT_DIR    = ft_printf/libft
GNL_DIR     = get_next_line

INCLUDES    = -I. -I$(FT_PRINTF_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR)

OBJ_DIR     = objs

SRCS        = main.c \
              error.c \
              ft_push_swap.c \
              ft_sort.c \
              ft_support.c \
              ft_bench.c \
              ft_parse_number.c \
              ft_allocate.c \
              ft_swap.c \
              ft_push.c \
              ft_rotate.c \
              ft_simple_sort.c \
              ft_reverse_rotate.c \
              ft_medium_sort.c \
              ft_assign_index.c \
              ft_complex_sort.c \
              ft_complex_partition.c

BONUS_SRCS  = error.c \
              ft_support.c \
              ft_parse_number.c \
              ft_bench.c \
              ft_swap.c \
              ft_push.c \
              ft_rotate.c \
              ft_reverse_rotate.c \
              fd_push_swap_bonus.c \
              ft_checker_init_bonus.c \
              ft_checker_execute_bonus.c \
              ft_checker_ops_bonus.c

OBJS        = $(SRCS:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS  = $(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o)

FT_PRINTF   = $(FT_PRINTF_DIR)/libftprintf.a
GNL_OBJS    = $(GNL_DIR)/get_next_line.o \
              $(GNL_DIR)/get_next_line_utils.o

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) -o $(NAME)

$(BONUS_NAME): $(FT_PRINTF) $(BONUS_OBJS) $(GNL_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(GNL_OBJS) $(FT_PRINTF) -o $(BONUS_NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(GNL_DIR)/%.o: $(GNL_DIR)/%.c $(GNL_DIR)/get_next_line.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME) $(BONUS_NAME) $(GNL_OBJS)
	@make -C $(FT_PRINTF_DIR) clean

fclean: clean
	@make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re