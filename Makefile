# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rubennijhuis <rubennijhuis@student.coda      +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/12 15:41:57 by rubennijhui   #+#    #+#                  #
#    Updated: 2022/07/22 18:57:38 by jobvan-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#=====================================#
#========= General variables =========#
#=====================================#

NAME := libvec
INCLUDE_DIR := include
SRC_DIR := src
OBJS_DIR := objs
OUTPUT := $(NAME).a

#=====================================#
#============ Input files ============#
#=====================================#

INC = -I $(INCLUDE_DIR)

SRCS =  main.c \
		cross.c \
		basic.c \
		angle.c \
		misc.c
	
HEADERS = $(INCLUDE_DIR)/libvec.h

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

#=====================================#
#========= Command arguments =========#
#=====================================#

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
# -Ofast -march=native -mtune=native

#=====================================#
#=============== Rules ===============#
#=====================================#

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) $(INC) -o $@ $<
	@echo "🔨 Compiling: $<"

all: $(NAME)

$(NAME): $(OUTPUT)

$(OUTPUT): $(OBJS)
	@ar -cr $@ $^
	@echo "✅ Built $(NAME) \n"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "🧹 Done cleaning objects"

get_src_files:
	@find $(SRC_DIR) | cut -b 5-

test: $(NAME)
	@make run -C tests/

fclean: clean
	@rm -f $(NAME).a
	@make fclean -C tests/
	@echo "🧹 Done cleaning archive"

norm:
	@echo "\033[92m========= $(NAME) norm ========\033[0m"
	@-norminette $(INCLUDE_DIR)
	@-norminette $(SRC_DIR)
	@echo "\033[92m========= $(NAME) norm ========\033[0m"

re: fclean all

.PHONY: all clean fclean re $(NAME)
