NAME		= so_long
INCLUDES	= includes/
SRC_DIR		= sources/
OBJ_DIR		= obj/

CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror -g3
PRFLAGS     = -ldl -lglfw -pthread -lm
RM			= rm -rf

LIBFT_DIR	= $(INCLUDES)Libft/
LIBFT		= $(LIBFT_DIR)libft.a

MLX_DIR		= $(INCLUDES)MLX42/
MLX			= $(MLX_DIR)build/libmlx42.a $(PRFLAGS) 

MAP_DIR 	= map/
MAP_FILES	= init_map check_map check_path

ASSET_DIR 	= assets/
ASSET_FILES	= init_assets display_assets display_assets_utils 

PLAYER_DIR 	= player/
PLAYER_FILES	= player player_utils

SRC_FILES	+= main utils
SRC_FILES  	+= $(addprefix $(MAP_DIR), $(MAP_FILES))
SRC_FILES  	+= $(addprefix $(ASSET_DIR), $(ASSET_FILES))
SRC_FILES  	+= $(addprefix $(PLAYER_DIR), $(PLAYER_FILES))

SRC         = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ         = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJ_CACHE 	= .cache_exists


all: 			 $(MLX) $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) CFLAGS+=$(LIBFT_CFLAGS)

$(MLX):
	@make -C $(MLX_DIR)build 

$(NAME): 		$(OBJ)
					$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)
					@echo "\033[0;32m$(shell echo $(NAME) | tr '[:lower:]' '[:upper:]') : COMPILED\033[0m"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_CACHE)
					@echo "Compiling $<"
					@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(OBJ_CACHE):
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(OBJ_DIR)$(MAP_DIR)
					@mkdir -p $(OBJ_DIR)$(PLAYER_DIR)
					@mkdir -p $(OBJ_DIR)$(ASSET_DIR)

clean:
					@make clean -C $(LIBFT_DIR)
					$(RM) $(OBJ_DIR)
					$(RM) $(OBJ_CACHE)
					@echo "so_long and libs object files cleaned!"

fclean: 		clean
					@make fclean -C $(LIBFT_DIR)
					$(RM) $(NAME)
					@echo "so_long and libs executable files cleaned!"
					rm -f $(MLX_DIR)build/CMakeCache.txt

re: 			fclean all
					@echo "Cleaned and rebuilt everything for so_long!"

.PHONY:			all clean fclean re

.SILENT:

