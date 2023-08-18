## ## ## ## ## ## ## ## ## ## ## ## ## ## # #
#                FILE NAME                  #
## ## ## ## ## ## ## ## ## ## ## ## ## ## # #

NAME = get_next_line

## ## ## ## ## ## ## ## ## ## ## ## ## ## # #
#                VARIABLES                  #
## ## ## ## ## ## ## ## ## ## ## ## ## ## # #

SRC = get_next_line.c
BSRC = get_next_line_bonus.c
UTILS = get_next_line_utils.c
BUTILS = get_next_line_utils_bonus.c
HEADER = get_next_line.h
BHEADER = get_next_line_bonus.h
CFLAGS = -Wall -Wextra -Werror -g3 -O3 -I.

## ## ## ## ## ## ## ## ## ## ## ## ## ## # #
#                COMPILATION                #
## ## ## ## ## ## ## ## ## ## ## ## ## ## # #

ifdef WITH_BONUS
	SRC += $(BSRC)
	UTILS += $(BUTILS)
	HEADER += $(BHEADER)
endif

## ## ## ## ## ## ## ## ## ## ## ## ## ## # #
#                COMPILATION                #
## ## ## ## ## ## ## ## ## ## ## ## ## ## # #

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $< -o $@

## ## ## ## ## ## ## ## ## ## ## ## ## ## # #
#                BONUS COMP                 #
## ## ## ## ## ## ## ## ## ## ## ## ## ## # #

bonus:
	@make WITH_BONUS=TRUE --no-print-directory

## ## ## ## ## ## ## ## ## ## ## ## ## ## # #
#                CLEAN FILE                 #
## ## ## ## ## ## ## ## ## ## ## ## ## ## # #

clean:
	@rm -f $(NAME)

fclean: clean

## ## ## ## ## ## ## ## ## ## ## ## ## ## # #
#                   REMAKE                  #
## ## ## ## ## ## ## ## ## ## ## ## ## ## # #

re: clean all
