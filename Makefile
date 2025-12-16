CFLAGS = -Wall -Wextra -Werror

INCLUDES=-Ilib

SRC_FILES = \

SRCS_OBJ = $(SRC_FILES:.c=.o)

ALL_OBJ = $(SRCS_OBJ)

DFILES = $(ALL_OBJ:.o=.d)

NAME = push_swap.a

NAME_HASH_SET = hash_set.a

NAME_LIB = lib.a

NAME_PARSE = parse.a

LIB_DIR = src/lib

HASH_SET_DIR = src/hash_set

PARSE_DIR = src/parse

all: $(NAME) lib hash_set

hash_set : $(NAME_HASH_SET)

$(NAME_HASH_SET):
	make -C $(HASH_SET_DIR) all
	mv $(HAST_SET_DIR)/$(NAME_HASH_SET) $(NAME_HASH_SET)

lib: $(NAME_LIB)

$(NAME_LIB):
	make -C $(LIB_DIR)
	mv $(LIB_DIR)/$(NAME_LIB) $(NAME_LIB)

$(NAME) : $(SRCS_OBJ)
	ar rcs $(NAME) $(SRCS_OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) -MMD -MP $< -o $@ $(INCLUDES)

clean:
	rm -rf $(ALL_OBJ) $(DFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

fclean-all: fclean
	make -C $(LIB_DIR) fclean
	make -C $(HASH_SET_DIR) fclean

.PHONY: all bonus clean fclean re fclean-all

-include : $(DFILES)
