## ## ## ## ## ## ## ## ## ## ## ## ## ## # #
#                FILE NAME                  #
## ## ## ## ## ## ## ## ## ## ## ## ## ## # #

NAME = get_next_line

## ## ## ## ## ## ## ## ## ## ## ## ## ## # #
#                VARIABLES                  #
## ## ## ## ## ## ## ## ## ## ## ## ## ## # #

SRC = ./get_next_line.c ./get_next_line_utils.c ./main.c
OBJ = $(SRC:.c=.o)
BSRC = get_next_line_bonus.c get_next_line_utils_bonus.c ./main.c
HEADER = get_next_line.h
BHEADER = get_next_line_bonus.h
CFLAGS = -Wall -Wextra -Werror -g3 -O3 -I./includes
DFLAGS = -Wall -Wextra -Werror -g3 -I./includes
VALUE ?= 0
SFLAGS ?= -D BUFFER_SIZE=$(VALUE)
## ## ## ## ## ## ## ## ## ## ## ## ## ## # #
#                COMPILATION                #
## ## ## ## ## ## ## ## ## ## ## ## ## ## # #

ifdef WITH_BONUS
	SRC = $(BSRC)
	HEADER += $(BHEADER)
endif

ifdef DEBUGGING
	CFLAGS = $(DFLAGS)
endif

## ## ## ## ## ## ## ## ## ## ## ## ## ## # #
#                COMPILATION                #
## ## ## ## ## ## ## ## ## ## ## ## ## ## # #

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(SFLAGS) $(CFLAGS) $(OBJ) -o $@

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

bonusdeb:
	@make WITH_BONUS=TRUE DEBUGGING=TRUE --no-print-directory
## ## ## ## ## ## ## ## ## ## ## ## ## ## # #
#                CLEAN FILE                 #
## ## ## ## ## ## ## ## ## ## ## ## ## ## # #

clean:
	@rm -f $(NAME) *.o

fclean: clean

## ## ## ## ## ## ## ## ## ## ## ## ## ## # #
#                   REMAKE                  #
## ## ## ## ## ## ## ## ## ## ## ## ## ## # #

re: clean all
