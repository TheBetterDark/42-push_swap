# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 23:59:26 by muabdi            #+#    #+#              #
#    Updated: 2024/07/23 20:05:50 by muabdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDES = ./includes
LIBS = ./libs

LIBFT = $(LIBS)/libft

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDEFLAGS = -I$(INCLUDES) -I$(LIBFT)/includes

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m

SRC_DIR = ./src
OBJ_DIR = ./bin

SRCS = $(SRC_DIR)/core/error.c \
		$(SRC_DIR)/core/main.c \
		$(SRC_DIR)/core/stack.c \
		$(SRC_DIR)/algorithm/check.c \
		$(SRC_DIR)/algorithm/sort_stack.c \
		$(SRC_DIR)/algorithm/sort_three.c \
		$(SRC_DIR)/algorithm/target_a.c \
		$(SRC_DIR)/algorithm/target_b.c \
		$(SRC_DIR)/algorithm/turk_sort.c \
		$(SRC_DIR)/rule/push.c \
		$(SRC_DIR)/rule/reverse_rotate.c \
		$(SRC_DIR)/rule/rotate.c \
		$(SRC_DIR)/rule/swap.c \
		$(SRC_DIR)/util/find.c \
		$(SRC_DIR)/util/list.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME) $(OBJ_DIR)

$(OBJ_DIR):
	@echo "${YELLOW}Creating object directory $(OBJ_DIR)...${NC}"
	@mkdir -p $(OBJ_DIR)
	@echo "${GREEN}Object directory $(OBJ_DIR) created.${NC}"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDEFLAGS) -c $< -o $@

${NAME}: $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $(NAME)
	@echo "${GREEN}$(NAME) created.${NC}"

all: $(NAME) $(OBJ_DIR)

clean:
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_DIR)

fclean:
	@make fclean -C $(LIBFT)
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@echo "${GREEN}$(NAME) cleaned.${NC}"

re: fclean all
	@echo "${GREEN}Target 're' completed.${NC}"

libs:
	@echo "${YELLOW}Updating submodules...${NC}"
	@git submodule update --init --recursive --remote
	@echo "${GREEN}Submodules updated.${NC}"

.PHONY: all clean fclean re libs
