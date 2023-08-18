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
DFLAGS = -Wall -Wextra -Werror -g3 -I.
VALUE ?= 0
SFLAGS ?= -D BUFFER_SIZE=$(VALUE)
## ## ## ## ## ## ## ## ## ## ## ## ## ## # #
#                COMPILATION                #
## ## ## ## ## ## ## ## ## ## ## ## ## ## # #

ifdef WITH_BONUS
	SRC += $(BSRC)
	UTILS += $(BUTILS)
	HEADER += $(BHEADER)
endif

ifdef DEBUGGING
	CFLAGS = $(DFLAGS)
endif

## ## ## ## ## ## ## ## ## ## ## ## ## ## # #
#                COMPILATION                #
## ## ## ## ## ## ## ## ## ## ## ## ## ## # #

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(SFLAGS) $(CFLAGS) $< -o $@

## ## ## ## ## ## ## ## ## ## ## ## ## ## # #
#                DEBUGGING                  #
## ## ## ## ## ## ## ## ## ## ## ## ## ## # #

deb:
	@make DEBUGGING=TRUE --no-print-directory

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
