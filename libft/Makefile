# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 14:50:49 by lspiteri          #+#    #+#              #
#    Updated: 2025/04/21 13:57:39 by lspiteri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================ #
# 					              Makefile
# ============================================================================ #
# Compiler and Flags
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -I.
RM		:= rm -rf
AR		:= ar rcs

# Directories
SRC_DIR   	:= _srcs
HEADER_DIR	:= _srcs
OBJ_DIR  	:= _objs
NAME	  	:= libft.a

# Source and Object files
SRC_FILES		:=	ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_realloc.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_findchr.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_putstr_fd.c \
					ft_putstr.c \
					ft_split.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strmapi.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strtrim.c \
					ft_substr.c \
					ft_tolower.c \
					ft_toupper.c
HEADER_FILES	:= libft.h
OBJ_FILES		:= $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

# Main rules
all:		$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJ_FILES)
			@echo "Creating the archive $(NAME)\n"
			@$(AR) $(NAME) $(OBJ_FILES)

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

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

# QOL rules

norm:
			@echo "Running norminette on source files...\n"
			@norminette $(addprefix $(SRC_DIR)/, $(SRC_FILES))
			@norminette $(addprefix $(HEADER_DIR)/, $(HEADER_FILES))

# Phony targets
.PHONY:		all clean fclean re norm t
