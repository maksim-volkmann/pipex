# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 13:56:33 by mvolkman          #+#    #+#              #
#    Updated: 2024/04/29 11:22:49 by mvolkman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

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

testme:
	@echo "$(BLUE)./pipex src.txt \"cat\" \"wc\" dest.txt$(WHITE)"
	@echo "$(GREEN)< src.txt cat | wc > dest2.txt$(WHITE)"
	@echo ""

	@echo "$(BLUE)./pipex src.txt \"wc -w\" \"sort\" dest.txt$(WHITE)"
	@echo "$(GREEN)< src.txt wc -w | sort > dest2.txt$(WHITE)"
	@echo ""

	@echo "$(BLUE)./pipex src.txt \"ls -l\" \"grep txt\" dest.txt$(WHITE)"
	@echo "$(GREEN)< src.txt ls -l | grep txt > dest2.txt$(WHITE)"
	@echo ""

	@echo "$(BLUE)./pipex src.txt \"head -n 5\" \"tail -n 3\" dest.txt$(WHITE)"
	@echo "$(GREEN)< src.txt head -n 5 | tail -n 3 > dest2.txt$(WHITE)"
	@echo ""

	@echo "$(BLUE)./pipex src.txt \"cat\" \"sort\" dest.txt$(WHITE)"
	@echo "$(GREEN)< src.txt cat | sort > dest2.txt$(WHITE)"
	@echo ""

	@echo "$(BLUE)./pipex src.txt \"grep txt\" \"wc -l\" dest.txt$(WHITE)"
	@echo "$(GREEN)< src.txt grep txt | wc -l > dest2.txt$(WHITE)"
	@echo ""

	@echo "$(BLUE)./pipex src.txt \"nl\" \"head -n 10\" dest.txt$(WHITE)"
	@echo "$(GREEN)< src.txt nl | head -n 10 > dest2.txt$(WHITE)"
	@echo ""

	@echo "$(BLUE)./pipex src.txt \"tail -n 20\" \"sort -r\" dest.txt$(WHITE)"
	@echo "$(GREEN)< src.txt tail -n 20 | sort -r > dest2.txt$(WHITE)"
	@echo ""

	@echo "$(BLUE)./pipex src.txt \"head -n 1\" \"tr a A\" dest.txt$(WHITE)"
	@echo "$(GREEN)< src.txt head -n 1 | tr a A > dest2.txt$(WHITE)"
	@echo ""

	@echo "$(BLUE)./pipex src.txt \"/bin/grep txt\" \"wc -l\" dest.txt$(WHITE)"
	@echo "$(GREEN)< src.txt /bin/grep txt | wc -l > dest2.txt$(WHITE)"
	@echo ""

	@echo "$(BLUE)./pipex src.txt \"/bin/cat\" \"sort\" dest.txt$(WHITE)"
	@echo "$(GREEN)< src.txt /bin/cat | sort > dest2.txt$(WHITE)"
	@echo ""

	@echo "$(BLUE)./pipex src.txt \"head -n 10\" \"/usr/bin/sort -r\" dest.txt$(WHITE)"
	@echo "$(GREEN)< src.txt head -n 10 | /usr/bin/sort -r > dest2.txt$(WHITE)"


.PHONY: all clean fclean re testme
