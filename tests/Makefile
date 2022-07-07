# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rubennijhuis <rubennijhuis@student.coda      +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/25 22:41:11 by rubennijhui   #+#    #+#                  #
#    Updated: 2022/07/07 17:18:20 by jobvan-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#=====================================#
#========== Setup variables ==========#
#=====================================#

ifdef CODAM
	CRITERION_DIR = -L /Users/$(USER)/.brew/Cellar/criterion/2.4.0_1/lib/
	CRITERION_INC = -I /Users/$(USER)/.brew/Cellar/criterion/2.4.0_1/include 
else
	CRITERION_DIR = -L /usr/local/Cellar/criterion/2.4.0_1/lib/
	CRITERION_INC = -I /usr/local/Cellar/criterion/2.4.0_1/include
endif

#=====================================#
#========= General variables =========#
#=====================================#

NAME := bin/tester
INCLUDE_DIR := ../include
PARENT_SRC_DIR := ../src
SRC_DIR := src
OBJS_DIR := objs

#=====================================#
#============ Input files ============#
#=====================================#

LIBS := ../libvec.a

LIBS_HEADERS := $(CRITERION_INC)

INC := -I $(INCLUDE_DIR) $(LIBS_HEADERS)

SRCS :=	main.c
HEADERS = $(INCLUDE_DIR)/libvec.h
OTHER_DEPS = $(PARENT_SRC_DIR)/main.c

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

#=====================================#
#========= Command arguments =========#
#=====================================#

CC = gcc
CFLAGS = -Wall -Werror -Wextra $(INC)
LDFLAGS = $(CRITERION_DIR) -lcriterion

#=====================================#
#=============== Rules ===============#
#=====================================#

objs/%.o: src/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $<
	@echo "🔨 Compiling: $<"
	
all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	@$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -o $@ -lm
	@echo "✅ Built $(NAME)"

run: $(NAME) $(LIBS)
	@./$(NAME)

../libvec.a:
	@make -C ../

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all run

.PHONY: all re run clean fclean