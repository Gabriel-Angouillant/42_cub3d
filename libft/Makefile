# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajasnin <ajasnin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 19:10:08 by augougea          #+#    #+#              #
#    Updated: 2024/05/09 04:08:54 by ajasnin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= 	libft.a

# sources ---------------------------------------------------------------------#

SRC_DIR		:=	src

SRCS_FILES	:= 	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_free_array.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
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
			ft_strtab.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c

SRC 		:=	$(addprefix $(SRC_DIR)/, $(SRCS_FILES))

OBJ_DIR		:=	obj
OBJ		:=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


# flags -----------------------------------------------------------------------#

CC 		:= 	gcc
CFLAGS 		:= 	-Wall -Wextra -Werror -g

# includes --------------------------------------------------------------------#

HEADER 		:= 	libft.h

# colors ----------------------------------------------------------------------#

DEF_COLOR	:=	 \033[0;39m
GRAY		:=	 \033[0;90m
RED		:=	 \033[0;91m
GREEN		:=	 \033[0;92m
YELLOW		:=	 \033[0;93m
BLUE		:=	 \033[0;94m
MAGENTA		:=	 \033[0;95m
CYAN		:=	 \033[0;96m
WHITE		:=	 \033[0;97m

#------------------------------------------------------------------------------#
# rules                                                                        #
#------------------------------------------------------------------------------#


all: $(NAME)

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(CYAN)$(NAME) executable files cleaned!$(DEF_COLOR)"

re: 	fclean all
	@echo "$(GREEN)cleaned and rebuilt for $(NAME)!$(DEF_COLOR)"

#------------------------------------------------------------------------------#
# compilation                                                                  #
#------------------------------------------------------------------------------#

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "$(YELLOW)$(NAME) compiling: $< $(DEF_COLOR)"
	@$(CC) -o $@ $(CFLAGS) -I includes -c $<

#------------------------------------------------------------------------------#
# linkage                                                                      #
#------------------------------------------------------------------------------#

$(NAME): $(OBJ)
	@ar rcs -o $(NAME) $(OBJ) 
	@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

#------------------------------------------------------------------------------#
# specifications                                                               #
#------------------------------------------------------------------------------#

.PHONY: all fclean clean re
