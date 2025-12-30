
SRCS := ft_free.c ft_perror.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strlen.c \
      ft_strchr.c ft_strrchr.c ft_bzero.c \
      ft_memset.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
      ft_strncmp.c ft_memchr.c \
      ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
      ft_atoi.c \
      ft_calloc.c ft_strdup.c \
      ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
      ft_itoa.c ft_strmapi.c ft_striteri.c \
      ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
      ft_puthex.c \
      ft_intarrayutils.c

SRCS_BONUS := $(SRCS) \
      ft_lstnew_bonus.c ft_lstdelone_bonus.c  ft_lstadd_front_bonus.c \
      ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
      ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
      get_next_line_bonus.c get_next_line_utils_bonus.c

DEFINE = 
# Example call to set buffer size
# BUFFER_SIZE_FLAG=1 BUFFER_SIZE_VAL=BUFFER_SIZE=42 make
#BUFFER_SIZE_FLAG=1 BUFFER_SIZE_VAL=BUFFER_SIZE=2147483647 make --debug -f Makefile
#BUFFER_SIZE_FLAG=1 BUFFER_SIZE_VAL=BUFFER_SIZE=10000000 make --debug -f Makefile
# BUFFER_SIZE_FLAG=1 BUFFER_SIZE_VAL=BUFFER_SIZE=9223372036854775807 make
ifeq ($(BUFFER_SIZE_FLAG), 1)
DEFINE += -D$(BUFFER_SIZE_VAL)
else
DEFINE += -DBUFFER_SIZE=1024
endif
# --------------- END DEFINE

INCLUDE = $(DEFINE)
ifeq ($(MAKECMDGOALS), fclean all bonus)
INCLUDE += -D_FTBONUS
endif
ifeq ($(MAKECMDGOALS), bonus_print_debug)
INCLUDE += -D_FTBONUS -D_DEBUG_PRINTF
endif
ifeq ($(MAKECMDGOALS), bonus_debug)
INCLUDE += -g
endif
OBJS := $(SRCS:.c=.o)
OBJS_DEBUG := $(SRCS:.c=.oo)
DEPS := $(SRCS:.c=.d)

OBJS_BONUS := $(SRCS_BONUS:.c=.o)
OBJS_BONUS_DEBUG := $(SRCS_BONUS:.c=.oo)
DEPS_BONUS := $(SRCS_BONUS:.c=.d)

NAME:=libft_old.a
NAME_BONUS:=libft.a
NAME_DEBUG:=libft_d.a

all: $(NAME_BONUS) libft.h get_next_line_bonus.h

bonus : $(NAME_BONUS) libft.h get_next_line_bonus.h

bonus_print_debug : $(NAME_BONUS) libft.h get_next_line_bonus.h

bonus_debug : $(NAME_DEBUG) libft.h get_next_line_bonus.h
	rm -f $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(NAME_BONUS) : $(OBJS_BONUS)
	ar rcs $(NAME_BONUS) $(OBJS_BONUS)

$(NAME_DEBUG): $(OBJS_BONUS_DEBUG)
	ar rcs $(NAME_DEBUG) $(OBJS_BONUS_DEBUG)

#added MMD and -include *.d wathcout not use $^!!
%.o: %.c 
	cc $(INCLUDE) -Wall -Wextra -Werror -c -MMD $< -o $@
	
%.oo: %.c 
	cc $(INCLUDE) -Wall -Wextra -Werror -c -g -MMD $< -o $@
	
clean:
	rm -f $(OBJS_BONUS) $(OBJS_BONUS_DEBUG) $(DEPS_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -f $(NAME_DEBUG)

re: fclean all

.PHONY: all clean fclean re bonus

-include *.d
