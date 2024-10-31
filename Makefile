# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 18:33:08 by vde-frei          #+#    #+#              #
#    Updated: 2023/10/18 07:32:12 by vde-frei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

SHELL := /bin/bash
COUNT := 0
SLEEP := sleep 0.1

BLACK  		 = \033[0;30m
RED    		 = \033[0;31m
GREEN  		 = \033[0;32m
YELLOW 		 = \033[0;33m
BLUE   		 = \033[0;34m
MAGENTA		 = \033[0;35m
CYAN   		 = \033[0;36m
WHITE  		 = \033[0;37m
RESET  		 = \033[0m

MANDATORY = Executable compiled
LBONUS = Bonus Executable compiled
CLEAN = Objects delete
FCLEAN = Program deleted
LIBNAME = GNL
BLIBNAME = GNL Bonus
COMP = Compiling

DFLAGS = -Wall -Wextra -Werror -g3 # TO DEBBUG
CFLAGS = -Wall -Werror -Wextra -O3 -fomit-frame-pointer -finline-functions # TO IMPROVE PERFORMANCE

SRC = src
BONUS = src/bonus
INC = includes
OBJ = obj

INCLUDES = -I$(INC)/

CFILES = $(addprefix $(SRC)/, get_next_line.c get_next_line_utils.c main.c)

BFILES = $(addprefix $(BONUS)/, get_next_line_bonus.c get_next_line_utils_bonus.c main.c)

OBJECT =  $(patsubst %, $(OBJ)/%, $(notdir $(CFILES:.c=.o)))

VALUE ?= 10
SFLAGS ?= -D BUFFER_SIZE=$(VALUE)

ifdef WITH_BONUS
	CFILES = $(BFILES)
	MANDATORY = $(LBONUS)
	MAGENTA = $(YELLOW)
	LIBNAME = $(BLIBNAME)
	SRC = $(BONUS)
endif

ifdef WITH_DEBBUG
	CFLAGS = $(DFLAGS)
endif

all: $(OBJ) $(NAME)

$(NAME): $(OBJECT)
	@$(CC) $(CFLAGS) $(SFLAGS) -o $@ $^
	@$(SLEEP)
	@printf "\n$(MAGENTA)$(MANDATORY)\n$(RESET)"

$(OBJ):
	@mkdir -p $(OBJ)

$(OBJ)/%.o: $(SRC)/%.c
	@$(eval COUNT=$(shell expr $(COUNT) + 1))
	@$(CC) $(CFLAGS) $(INCLUDES) $(SFLAGS) -c $< -o $@
	@printf "$(GREEN)$(LIBNAME) $(COMP) %d%%\r$(RESET)" $$(echo $$(($(COUNT) * 100 / $(words $(CFILES)))))

clean:
	@$(RM) -rf $(OBJ)
	@$(SLEEP)
	@printf "$(RED)$(CLEAN)$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@$(SLEEP)
	@printf "$(RED)$(FCLEAN)$(RESET)\n"

re: fclean all

bonus:
	@$(RM) -rf $(OBJ)
	@make WITH_BONUS=TRUE --no-print-directory
	@$(RM) -rf $(OBJ)

debbug:
	@make WITH_DEBBUG=TRUE --no-print-directory

.PHONY: all bonus clean fclean re debbug
