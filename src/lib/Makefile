CFLAGS = -Wall -Wextra -Werror

LIST_DIR = list/

MEM_DIR = mem/

INCLUDES=-I./ -Iheaders -I$(MEM_DIR)/headers -I$(LIST_DIR)/headers

SRC_FILES = ./$(LIST_DIR)ft_lstadd.c \
	./$(LIST_DIR)ft_lstclear.c \
	./$(LIST_DIR)ft_lstnew.c \
	./$(LIST_DIR)ft_lstremove.c \
	./$(LIST_DIR)ft_lstadd.c \
	./$(MEM_DIR)mem.c

SRCS_OBJ = $(SRC_FILES:.c=.o)

ALL_OBJ = $(SRCS_OBJ)

DFILES = $(ALL_OBJ:.o=.d)

NAME = lib.a

all: $(NAME)

$(NAME) : $(SRCS_OBJ)
	ar rcs $(NAME) $(SRCS_OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) -MMD -MP $< -o $@ $(INCLUDES)

clean:
	rm -rf $(ALL_OBJ) $(DFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

-include : $(DFILES)
