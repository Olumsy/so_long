# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 14:50:49 by lspiteri          #+#    #+#              #
#    Updated: 2025/05/20 01:30:14 by lspiteri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ======================================================================= #
# 					              Makefile
# ======================================================================= #
# Compiler and Flags
CC		:= cc
CFLAGS	= -Wall -Wextra -Werror -I. -g -fsanitize=address
RM		:= rm -rf
AR		:= ar rcs

# Directories
SRC_DIR   	:= _srcs
HEADER_DIR	:= .
SUBDIRS		:= minilibx-linux libft 
OBJ_DIR  	:= _objs
MLX_DIR = minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
# Files
NAME	 	 	:= so_long
SRC_FILES		:=	map1.c \
					map2.c \
					read_map.c \
					input_management.c \
					so_long.c \
					backtracking.c \
					point.c \
					graphics.c \
					parsing.c \
					
					
HEADER_FILES	:= so_long.h
OBJ_FILES		:= $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

# Macro to run target in all subdirs
define run_on_subdirs
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir $(1) --no-print-directory || echo "> No rule '$(1)' in $$dir (ignored)"; \
	done
endef

# Main rules
all:		$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJ_FILES)
			@echo "Creating $(NAME)\n"
			$(call run_on_subdirs,all)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) libft/libft.a $(MLX) -L$(MLX_DIR)
# Compilation of source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
			@echo "Compiling $<"
			@$(CC) $(CFLAGS) -Imlx -c $< -o $@

# Creating necessary directories
$(OBJ_DIR):
			@echo "Creating object directory $(OBJ_DIR)"
			@mkdir -p $(OBJ_DIR)

# Clean rules
clean:
			$(RM) $(OBJ_DIR)
			$(call run_on_subdirs,clean)

fclean:		
			$(RM) $(OBJ_DIR)
			$(RM) $(NAME)
			$(call run_on_subdirs,fclean)

re:			fclean all

# QOL rules
norm:
			@echo "Running norminette on source files..."
			@norminette $(addprefix $(SRC_DIR)/, $(SRC_FILES))
			@norminette $(addprefix $(HEADER_DIR)/, $(HEADER_FILES))

# Phony targets
.PHONY:		all clean fclean re norm
