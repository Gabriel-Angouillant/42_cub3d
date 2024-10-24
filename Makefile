# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 19:10:08 by augougea          #+#    #+#              #
#    Updated: 2024/06/02 18:00:01 by augougea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:=	cub3D

# sources ---------------------------------------------------------------------#

SRC_DIR		:=	src

SRC_FILES 	:=		charge/charge_map.c \
				charge/charge_path.c \
				charge/charge_rgb.c \
				charge/check_path.c \
				error/error.c \
				free/free.c \
				gnl/get_next_line.c \
				init/init_fd.c \
				init/init_file.c \
				init/init_game.c \
				main/load_game.c \
				main/main.c \
				parse/parse_format_file.c \
				parse/parse_format_map.c \
				parse/parse_map.c \
				parse/parse_player.c \
				program/hook.c \
				program/move.c \
				program/rotate.c \
				program/start_game.c \
				rendering/dda.c \
				rendering/raycasting.c \
				rendering/texturing.c \
				utils/clear_window.c \
				utils/ft_check_access.c \
				utils/ft_check_extension.c \
				utils/ft_index_map.c \
				utils/ft_len_tab2d.c \
				utils/ft_replace_char.c \
				utils/ft_str_to_find.c \
				utils/get_texture_size.c \
				utils/set_player_dir.c

SRC 		:=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR		:=	obj
OBJ		:=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# library ---------------------------------------------------------------------#

LIBFT_DIR	:=	libft
LIBFT		:=	libft/libft.a
LIB 		:=	-L $(LIBFT_DIR) -lft -lm

MACROLIB_DIR	:= 	MacroLibX
MACROLIB	:=	MacroLibX/libmlx.so
MACRO		:=	$(MACROLIB) -lSDL2


# includes --------------------------------------------------------------------#

HEAD_DIR 	:=	includes/

HEAD_FILES 	:=	define.h \
			include.h \
			libcub3D.h \
			structure.h

HEAD 		:=	$(addprefix $(HEAD_DIR), $(HEAD_FILES))

INC 		:=	-I$(HEAD_DIR) -I$(LIBFT_DIR) -I$(MACROLIB_DIR)

# flags -----------------------------------------------------------------------#

CC		:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -g
RM		:=	rm -rf

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

clean:
	make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ_DIR)
	@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"

fclean: clean
	make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@echo "$(CYAN)$(NAME) executable files cleaned!$(DEF_COLOR)"

re: 	fclean all
	@echo "$(GREEN)cleaned and rebuilt for $(NAME)!$(DEF_COLOR)"

#------------------------------------------------------------------------------#
# compilation                                                                  #
#------------------------------------------------------------------------------#

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "$(YELLOW)$(NAME) compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

#------------------------------------------------------------------------------#
# linkage                                                                      #
#------------------------------------------------------------------------------#

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR) -j
	@make -C $(MACROLIB_DIR) -j
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) $(MACRO) $(INC) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

#------------------------------------------------------------------------------#
# specifications                                                               #
#------------------------------------------------------------------------------#

.PHONY: all clean fclean re

