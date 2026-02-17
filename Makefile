
SRCS := src/e_envmgr.c src/e_envmgr_crud.c \
		src/u_util_pipe.c \
		src/m_minishell.c \
		src/builtin/pwd.c

SRCS_PIPEX := src/pipex/pipex.c src/pipex/pipex_main.c \
		src/pipex/pipex_utils.c src/pipex/pipex_process.c

SRCS += $(SRCS_PIPEX)

H_INCLUDES :=  include/mx_utils.h include/pipex.h \
				include/minishellx.h

SRCS_BONUS := $(SRCS) src/main.c

H_INCLUDES_BONUS := $(H_INCLUDES)

INCLUDE = 

ifeq ($(MAKECMDGOALS), bonus)
INCLUDE += -D_FTBONUS -DHERE_DOC_S="\"here_doc\""
SRCS_BONUS := $(SRCS) src/main_bonus.c
else
INCLUDE += -DHERE_DOC_S="\"\n\""
endif

ifeq ($(MAKECMDGOALS), clean)
INCLUDE += -D_FTBONUS
SRCS_BONUS += src/main_bonus.c
endif

ifeq ($(MAKECMDGOALS), fclean)
INCLUDE += -D_FTBONUS
SRCS_BONUS += src/main_bonus.c
endif

ifeq ($(MAKECMDGOALS), debugs)
INCLUDE += -g 
endif

INCLUDE += -I. -I../ -Iinclude -I../include \
			-I./libftprintf/include \
			-Ilibft -I../libft \
			-Ilibftprint -I../libftprintf
			
H_INCLU := $(H_INCLUDES:.h)

H_INCLU_BONUS := $(H_INCLUDES:.h)

OBJS := $(SRCS_BONUS:.c=.o) $(H_INCLU_BONUS)
DEPS := $(SRCS_BONUS:.c=.d)


LIBFT:=libft/libft.a
LIBFT_DEBUG:=libft/libft_d.a
LIBPRINTF:=libftprintf/libftprintf.a
LIBPRINTF_DEBUG:=libftprintf/libftprintf_d.a
NAME:=minishell
NAME_DEBUG:=dminishell
NAME_DEBUGPRINT:=minishell_pd
PIPEX_NAME:=pipex
PIPEX_NAME_DEBUG:=dpipex
PIPEX_NAME_DEBUGPRINT:=pipex_pd

all: $(NAME)

bonus: $(NAME)

printd: $(NAME_DEBUGPRINT)

debugs: $(NAME_DEBUG)

$(LIBFT) :
	make -C libft bonus
$(LIBFT_DEBUG) :
	make -C libft bonus_debug
$(LIBPRINTF) :
	make -C libftprintf
$(LIBPRINTF_DEBUG) :
	make -C libftprintf debug
$(PIPEX_NAME_DEBUGPRINT): $(LIBFT) $(LIBPRINTF_DEBUG) $(H_INCLUDES) $(OBJS)
	cc $(INCLUDE) -Wall -Wextra -Werror $(OBJS) \
	-Llibftprintf -lftprintf_d -Llibft -lft \
	 -o $(PIPEX_NAME_DEBUGPRINT)
$(PIPEX_NAME_DEBUG): $(LIBFT) $(LIBPRINTF_DEBUG) $(H_INCLUDES) $(OBJS)
	cc $(INCLUDE) -Wall -Wextra -Werror $(OBJS) \
	-Llibftprintf -lftprintf_d -Llibft -lft \
	 -o $(PIPEX_NAME_DEBUG)
$(PIPEX_NAME): $(LIBFT) $(LIBPRINTF_DEBUG) $(H_INCLUDES) $(OBJS)
	cc $(INCLUDE) -Wall -Wextra -Werror $(OBJS) \
	-Llibftprintf -lftprintf_d -Llibft -lft \
	 -o $(PIPEX_NAME)	 
$(NAME_DEBUGPRINT): $(LIBFT) $(LIBPRINTF_DEBUG) $(H_INCLUDES) $(OBJS)
	cc $(INCLUDE) -Wall -Wextra -Werror $(OBJS) \
	-Llibftprintf -lftprintf_d -Llibft -lft -lreadline \
	 -o $(NAME_DEBUGPRINT)	
$(NAME): $(LIBFT) $(LIBPRINTF) $(H_INCLUDES) $(OBJS) Makefile
	cc $(INCLUDE) -Wall -Wextra -Werror $(OBJS) \
	-Llibftprintf -lftprintf -Llibft -lft -lreadline \
	-o $(NAME)

$(NAME_DEBUG): $(LIBFT_DEBUG) $(LIBPRINTF_DEBUG) $(H_INCLUDES) $(OBJS)
	cc $(INCLUDE) -Wall -Wextra -Werror $(OBJS) \
	-Llibftprintf -lftprintf_d -Llibft -lft_d -lreadline \
	-o $(NAME_DEBUG)

#added MMD and -include *.d wathcout not use $^!!
%.o: %.c
	cc $(INCLUDE) -Wall -Wextra -Werror -c -MMD $< -o $@

%.h:

backup:
	if [ -f $(NAME) ]; then \
		mv $(NAME) $(NAME).old; \
	fi
	@if [ -f $(NAME_DEBUG) ]; then \
		mv $(NAME_DEBUG) $(NAME_DEBUG).old; \
	fi
	@if [ -f $(NAME_DEBUGPRINT) ]; then \
		mv $(NAME_DEBUGPRINT) $(NAME_DEBUGPRINT).old; \
	fi
	
clean: backup
	rm -f $(PIPEX_NAME) $(PIPEX_NAME_DEBUG) $(PIPEX_NAME_DEBUG_PRINT)
	rm -f $(NAME) $(NAME_DEBUG) $(NAME_DEBUGPRINT) $(OBJS) $(DEPS)
	
fclean: clean
	rm -f $(NAME).old $(NAME_DEBUG).old $(NAME_DEBUGPRINT).old
	rm -f $(PIPEX_NAME) $(PIPEX_NAME_DEBUG) $(PIPEX_NAME_DEBUG_PRINT)
	rm -f $(NAME) $(NAME_DEBUG) $(NAME_DEBUGPRINT) $(OBJS) $(DEPS)
	rm -f $(NAME) $(NAME_DEBUG) $(NAME_DEBUGPRINT) $(OBJS) $(DEPS)
	make -C libftprintf fclean
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus

-include $(OBJS:.o=.d)
