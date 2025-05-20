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
CFLAGS	:= -Wall -Wextra -Werror -I. -g
RM		:= rm -rf
AR		:= ar rcs

# Directories
SRC_DIR   	:= .
HEADER_DIR	:= .
SUBDIRS		:= 
OBJ_DIR  	:= _objs

# Files
NAME	 	 	:= gnl.a
SRC_FILES		:=	get_next_line.c \
					get_next_line_utils.c \
					
HEADER_FILES	:= 	get_next_line.h
OBJ_FILES		:= $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

# Macro to run target in all subdirs
define run_on_subdirs
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir $(1) --no-print-directory; \
	done
endef

# Main rules
all:		$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJ_FILES)
			@echo "Creating $(NAME)\n"
			$(call run_on_subdirs,all)
			@$(AR) $(NAME) $(OBJ_FILES) ../libft/libft.a

# Compilation of source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
			@echo "Compiling $<"
			@$(CC) $(CFLAGS) -c $< -o $@

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
