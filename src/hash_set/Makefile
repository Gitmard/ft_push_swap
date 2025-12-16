CFLAGS = -Wall -Wextra -Werror

SRC_DIR=./

LIB_DIR = ../lib

INCLUDES=-Iheaders -I$(LIB_DIR) -I$(LIB_DIR)/headers

SRC_FILES = $(SRC_DIR)/hash_set.c \

TESTS_FILES = $(TESTS_DIR)/main.c \
		$(TESTS_DIR)/tests_mandatory.c

SRCS_OBJ = $(SRC_FILES:.c=.o)

ALL_OBJ = $(SRCS_OBJ) $(BONUS_OBJ)

DFILES = $(ALL_OBJ:.o=.d)

NAME = hash_set.a

all: $(NAME)

$(NAME) : $(SRCS_OBJ)
	ar rcs $(NAME) $(SRCS_OBJ)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) -MMD -MP $< -o $@ $(INCLUDES)

clean:
	rm -rf $(ALL_OBJ) $(DFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

-include : $(DFILES)
