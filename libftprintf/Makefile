
SRCS := ft_printf_parse.c ft_printf_convhelp.c \
	ft_printf.c ft_printf_convimpl.c ft_printf_convimpl_hex.c \
	ft_debugprintf.c

SRCS_BONUS := $(SRCS) 

INCLUDE = 
ifeq ($(MAKECMDGOALS), fclean all bonus)
INCLUDE += -D_FTBONUS
endif
ifeq ($(MAKECMDGOALS), bonus_print_debug)
INCLUDE += -D_FTBONUS -D_DEBUG_PRINTF
endif
ifeq ($(MAKECMDGOALS), debug)
INCLUDE += -g -D_FTBONUS -D_DEBUG_PRINTF
endif

OBJS := $(SRCS:.c=.o)
OBJS_DEBUG := $(SRCS:.c=.oo)
DEPS := $(SRCS:.c=.d)

OBJS_BONUS := $(SRCS_BONUS:.c=.o)
OBJS_BONUS_DEBUG := $(SRCS_BONUS:.c=.oo)
DEPS_BONUS := $(SRCS_BONUS:.c=.d)

INCLUDE += -I. -I../


NAME:=libftprintf.a
NAME_BONUS:=libftprintf_bz.a
NAME_DEBUG:=libftprintf_d.a

all: $(NAME)

bonus : $(NAME_BONUS)

#obviate the "bonus", compile the debug printf in the lib for $(NAME)
bonus_print_debug : $(NAME_BONUS)

debug : $(NAME_DEBUG) $(OBJS_BONUS_DEBUG)

#libftprintf/$(NAME): $(OBJS) include/ft_printf.h include/ft_printf_convimpl.h
#	ar rcs $@ $^
	
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(NAME_BONUS) : $(OBJS_BONUS)
	rm -f $(NAME_DEBUG)
	ar rcs $(NAME) $(OBJS_BONUS)
	ar rcs $(NAME_BONUS) $(OBJS_BONUS)

$(NAME_DEBUG): $(OBJS_BONUS_DEBUG)
	ar rcs $(NAME_DEBUG) $(OBJS_BONUS_DEBUG)

#added MMD and -include *.d wathcout not use $^!!
%.o: %.c
	cc -g $(INCLUDE) -Wall -Wextra -Werror  -c -MMD $< -o $@
%.oo: %.c
	cc $(INCLUDE) -Wall -Wextra -Werror  -c -g -MMD $< -o $@

clean:
	rm -f $(OBJS_BONUS) $(OBJS_BONUS_DEBUG) $(DEPS_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -f $(NAME_DEBUG)
	
re: fclean all

.PHONY: all clean fclean re bonus

-include *.d
