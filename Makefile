# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 13:56:33 by mvolkman          #+#    #+#              #
#    Updated: 2024/04/22 16:28:53 by mvolkman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
# CFLAGS = -Wall -Wextra -Werror

# Source files for Pipex
SRC = \
	pipex.c \
	utils.c \

# Object files
OBJ = $(SRC:.c=.o)

# Library directories and flags for libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Include directories for libft
INCLUDES = -I$(LIBFT_DIR)/include -I./include

# Output executable name
NAME = pipex

# Colors used for terminal output
GREEN = \033[0;32m
BLUE = \033[0;34m
ORANGE = \033[38;5;214m
RED = \033[0;31m
YELLOW = \033[0;33m
WHITE = \033[0;37m

# Rules
all: $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(WHITE)"

$(NAME): $(OBJ) $(LIBFT)
	@echo "$(BLUE)Building $(NAME)$(WHITE)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(INCLUDES)
	@echo "$(GREEN)$(NAME) created successfully!$(WHITE)"

$(LIBFT):
	@echo "$(BLUE)Building $(LIBFT)$(WHITE)"
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	@echo "$(GREEN)Compiled $< successfully!$(WHITE)"

clean:
	@echo "$(RED)Cleaning object files...$(WHITE)"
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)Cleaning binaries...$(WHITE)"
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
