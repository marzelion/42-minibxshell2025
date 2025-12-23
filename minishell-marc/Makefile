#	$(wildcard $(SRCS_DIR)*.c) \
	$(wildcard $(SRCS_DIR)*/*.c) \
	$(wildcard $(SRCS_DIR)*/*/*.cmak)

#1. Variables
NAME =  minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADERS = minishell.h \
	$(wildcard srcs/*/*.h)
#2. Directorios
SRCS_DIR = srcs/
SRCS = srcs/built-ins/main.c \
	srcs/built-ins/pwd.c \
	srcs/built-ins/env.c \
	srcs/built-ins/echo.c \
	srcs/built-ins/exit.c \
	srcs/built-ins/utils.c \
	srcs/built-ins/cd.c

#OBJECT RULES
OBJ_DIR = obj/
OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJ_DIR)%.o)
#3. Librerias
LIBFT_DIR = libraries/full_libft
FT_PRINTF_DIR = libraries/ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
#INCLUDES
INCLUDES = -I. -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -Isrcs/built-ins
#rules
all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(HEADERS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -lreadline -o $(NAME)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

leaker: CFLAGS += -g3 -fsanitize=address
leaker: fclean $(NAME)

re: fclean all

.PHONY: all clean fclean leaker re
