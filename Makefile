NAME        = philo

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
CPPFLAGS    = -Iincludes
OBJ_DIR     = obj

SRCS        = \
	src/main.c \
	src/pars.c \
	src/utils/ft_utils.c \
	src/utils/mutex_utils.c \
	src/utils/time_utils.c \
	src/init.c \
	src/utils/sleep_utils.c \
	src/utils/print_utils.c \
	src/utils/mutex_utils_two.c \
	src/fill_philo.c \
	src/thread_start.c \
	src/philo_action.c \
	src/philo_routine.c \
	src/monitoring.c \
	srtc/philo_more.c \

OBJS        = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(sort $(dir $(SRCS)))

RM          = rm -f
MKDIR       = mkdir -p

GREEN       = \033[0;32m
YELLOW      = \033[0;33m
BLUE        = \033[0;34m
RED         = \033[0;31m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN)✔ $(NAME) built successfully$(RESET)\n"

$(OBJ_DIR)/%.o: %.c
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@printf "$(BLUE)• Compiled:$(RESET) %s\n" "$<"

clean:
	@$(RM) -r $(OBJ_DIR)
	@printf "$(YELLOW)✦ Object files removed$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED)✦ Executable removed$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re