NAME        = philo

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -pthread
CPPFLAGS    = -Iincludes

SRC_DIR     = src
OBJ_DIR     = obj

SRCS        = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/pars.c \
	$(SRC_DIR)/utils/ft_utils.c \
	$(SRC_DIR)/utils/mutex_utils.c

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
