CFLAGS = -Wall -Wextra -Werror -g3

# ========== DIRECTORIES ==========

# ---------- MAIN ----------

SRC_DIR = src

# ---------- INSTRUCTIONS ----------

INSTRUCTIONS_DIR = instructions

# ---------- LIB ----------

LIB_DIR = lib

LIB_HASH_SET_DIR = hash_set

LIB_LIST_DIR = list

LIB_LIST_UTILS_DIR = utils

LIB_MEM_DIR = mem

LIB_PRINTF_DIR = printf

LIB_STACK_DIR = stack

LIB_STRING_DIR = string

LIB_UTILS_DIR = utils

LIB_GNL_DIR = get_next_line

# ---------- PARSE ----------

PARSE_DIR = parse

# ---------- ALGO ----------

ALGO_DIR = algo

ALGO_UTILS_DIR = algo_utils

ALGO_MEDIUM_DIR = medium

# ---------- BENCH ----------

BENCH_DIR = bench

# ---------- CHECKER ----------

CHECKER_DIR = checker

# ---------- HEADERS ----------

HEADERS_DIR = headers

# ---------- INSTRUCTIONS ----------

INCLUDES_INSTRUCTIONS =	-I./$(SRC_DIR)/$(INSTRUCTIONS_DIR) \
						-I./$(SRC_DIR)/$(INSTRUCTIONS_DIR)/$(HEADERS_DIR)

# ---------- LIB ----------

INCLUDES_LIB_HASH_SET =	-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_HASH_SET_DIR) \
						-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_HASH_SET_DIR)/$(HEADERS_DIR)

INCLUDES_LIB_LIST =		-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_LIST_DIR) \
						-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_LIST_DIR)/$(HEADERS_DIR)

INCLUDES_LIB_MEM =		-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_MEM_DIR) \
						-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_MEM_DIR)/$(HEADERS_DIR)

INCLUDES_LIB_STACK =	-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_STACK_DIR) \
						-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_STACK_DIR)/$(HEADERS_DIR)

INCLUDES_LIB_STRING =	-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_STRING_DIR) \
						-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_STRING_DIR)/$(HEADERS_DIR)

INCLUDES_LIB_MAIN =		-I./$(SRC_DIR)/$(LIB_DIR) \
						-I./$(SRC_DIR)/$(LIB_DIR)/$(HEADERS_DIR)

INCLUDES_PRINTF =		-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_PRINTF_DIR) \
						-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_PRINTF_DIR)/$(HEADERS_DIR)

INCLUDES_LIB_UTILS =		-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_UTILS_DIR) \
					-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_UTILS_DIR)/$(HEADERS_DIR)

INCLUDES_LIB_GNL =		-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_GNL_DIR) \
					-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_GNL_DIR)/$(HEADERS_DIR)


INCLUDES_LIB =			$(INCLUDES_LIB_MAIN) \
						$(INCLUDES_LIB_HASH_SET) \
						$(INCLUDES_LIB_LIST) \
						$(INCLUDES_LIB_MEM) \
						$(INCLUDES_PRINTF) \
						$(INCLUDES_LIB_STACK) \
						$(INCLUDES_LIB_STRING) \
						$(INCLUDES_LIB_UTILS) \
						$(INCLUDES_LIB_GNL)

# ---------- PARSE ----------

INCLUDES_PARSE = 		-I./$(SRC_DIR)/$(PARSE_DIR) -I./$(SRC_DIR)/$(PARSE_DIR)/$(HEADERS_DIR)

# ---------- ALGO ----------

INCLUDES_ALGO_UTILS =		-I./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_UTILS_DIR) -I./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_UTILS_DIR)/$(HEADERS_DIR)

INCLUDES_ALGO_MEDIUM = 		-I./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_MEDIUM_DIR) -I./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_MEDIUM_DIR)/$(HEADERS_DIR)

INCLUDES_ALGO = $(INCLUDES_ALGO_UTILS) $(INCLUDES_ALGO_MEDIUM)

# ---------- BENCH ----------

INCLUDES_BENCH =		-I./$(SRC_DIR)/$(BENCH_DIR)/ -I./$(SRC_DIR)/$(BENCH_DIR)/$(HEADERS_DIR)

# ---------- CHECKER ----------

INCLUDES_CHECKER =		-I./$(SRC_DIR)/$(CHECKER_DIR)/

# ---------- MAIN ----------

INCLUDES_MAIN = 		-I./$(SRC_DIR) -I./$(SRC_DIR)/$(HEADERS_DIR)


INCLUDES =			$(INCLUDES_INSTRUCTIONS) $(INCLUDES_LIB) $(INCLUDES_PARSE) $(INCLUDES_MAIN) $(INCLUDES_ALGO) $(INCLUDES_BENCH) $(INCLUDES_CHECKER)

# ========== FILES ==========

# ---------- MAIN ----------

MAIN_FILES =			./$(SRC_DIR)/push_swap.c \

# ---------- INSTRUCTIONS ----------

INSTRUCTIONS_FILES =	./$(SRC_DIR)/$(INSTRUCTIONS_DIR)/push.c \
						./$(SRC_DIR)/$(INSTRUCTIONS_DIR)/reverse_rotate.c \
						./$(SRC_DIR)/$(INSTRUCTIONS_DIR)/rotate.c \
						./$(SRC_DIR)/$(INSTRUCTIONS_DIR)/swap.c

# ---------- LIB ----------

LIB_HASH_SET_FILES =	./$(SRC_DIR)/$(LIB_DIR)/$(LIB_HASH_SET_DIR)/hash_set.c \

LIB_LIST_FILES =		./$(SRC_DIR)/$(LIB_DIR)/$(LIB_LIST_DIR)/ft_lstadd.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_LIST_DIR)/ft_lstclear.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_LIST_DIR)/ft_lstnew.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_LIST_DIR)/ft_lstremove.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_LIST_DIR)/$(LIB_LIST_UTILS_DIR)/list_utils.c

LIB_MEM_FILES =			./$(SRC_DIR)/$(LIB_DIR)/$(LIB_MEM_DIR)/mem.c

LIB_PRINTF_FILES =		./$(SRC_DIR)/$(LIB_DIR)/$(LIB_PRINTF_DIR)/ft_printf.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_PRINTF_DIR)/parse.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_PRINTF_DIR)/print.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_PRINTF_DIR)/utils.c

LIB_STACK_FILES=		./$(SRC_DIR)/$(LIB_DIR)/$(LIB_STACK_DIR)/ft_stackadd.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_STACK_DIR)/ft_stacknew.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_STACK_DIR)/ft_stackremove.c

LIB_STRING_FILES =		./$(SRC_DIR)/$(LIB_DIR)/$(LIB_STRING_DIR)/string.c \

LIB_UTILS_FILES =		./$(SRC_DIR)/$(LIB_DIR)/$(LIB_UTILS_DIR)/check_sort.c \

LIB_GNL_FILES =			./$(SRC_DIR)/$(LIB_DIR)/$(LIB_GNL_DIR)/get_next_line.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_GNL_DIR)/get_next_line_utils.c

LIB_FILES =				$(LIB_HASH_SET_FILES) \
						$(LIB_LIST_FILES) \
						$(LIB_MEM_FILES) \
						$(LIB_STRING_FILES) \
						$(LIB_STACK_FILES) \
						$(LIB_PRINTF_FILES) \
						$(LIB_UTILS_FILES) \
						$(LIB_GNL_FILES)

# ---------- PARSE ----------

PARSE_FILES =			./$(SRC_DIR)/$(PARSE_DIR)/parse.c \
						./$(SRC_DIR)/$(PARSE_DIR)/parse_utils.c \
						./$(SRC_DIR)/$(PARSE_DIR)/normalise_args.c \
						./$(SRC_DIR)/$(PARSE_DIR)/free.c

# ---------- ALGO ----------

ALGO_UTILS_FILES =		./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_UTILS_DIR)/algo_utils.c

ALGO_MEDIUM_FILES =		./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_MEDIUM_DIR)/medium.c \
						./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_MEDIUM_DIR)/medium_utils.c

ALGO_FILES =			$(ALGO_UTILS_FILES) $(ALGO_MEDIUM_FILES)

# ---------- BENCH ----------

BENCH_FILES = 			./$(SRC_DIR)/$(BENCH_DIR)/bench.c \
						./$(SRC_DIR)/$(BENCH_DIR)/bench_utils.c

# ---------- CHECKER ----------

CHECKER_FILES = 		./$(SRC_DIR)/$(CHECKER_DIR)/checker.c \
						./$(SRC_DIR)/$(CHECKER_DIR)/checker_utils.c

# ---------- ALL ----------

ALL_FILES = 			$(MAIN_FILES) \
						$(INSTRUCTIONS_FILES) \
						$(LIB_FILES) \
						$(PARSE_FILES) \
						$(ALGO_FILES) \
						$(BENCH_FILES) \
						$(CHECKER_FILES) \

# ========== OBJ ==========

# ---------- MAIN ----------
SRCS_OBJ = $(MAIN_FILES:.c=.o)

# ---------- INSTRUCTIONS ----------

INSTRUCTIONS_OBJ = $(INSTRUCTIONS_FILES:.c=.o)

# ---------- LIB ----------

LIB_OBJ = $(LIB_FILES:.c=.o)

# ---------- PARSE ----------

PARSE_OBJ = $(PARSE_FILES:.c=.o)

# ---------- ALGO ----------

ALGO_OBJ = $(ALGO_FILES:.c=.o)

# ---------- BENCH ----------

BENCH_OBJ = $(BENCH_FILES:.c=.o)

# ---------- CHECKER ----------

CHECKER_OBJ = $(CHECKER_FILES:.c=.o)

# ========== DFILES ==========

DFILES = $(ALL_OBJ:.o=.d)

# ========== NAMES ==========

NAME_MAIN_DEBUG = push_swap_debug

NAME_MAIN = push_swap

NAME_INSTRUCTIONS = instructions.a

NAME_LIB = lib.a

NAME_PARSE = parse.a

NAME_ALGO = algo.a

NAME_BENCH = bench.a

NAME_CHECKER = checker

# ========== RULES ==========

# ---------- MAIN ----------

all: $(NAME_MAIN)

$(NAME_MAIN): $(SRCS_OBJ) $(NAME_ALGO) $(NAME_INSTRUCTIONS) $(NAME_PARSE) $(NAME_LIB) $(NAME_BENCH)
	$(CC) $(CFLAGS) $(SRCS_OBJ) $(NAME_ALGO) $(NAME_INSTRUCTIONS) $(NAME_PARSE) $(NAME_LIB) $(NAME_BENCH) -o $@

bonus: $(NAME_CHECKER)

$(NAME_CHECKER): $(CHECKER_OBJ) $(NAME_PARSE) $(NAME_INSTRUCTIONS) $(NAME_LIB)
	$(CC) $(CFLAGS) $(CHECKER_OBJ) $(NAME_PARSE) $(NAME_INSTRUCTIONS) $(NAME_LIB) -o $@

debug: $(NAME_MAIN_DEBUG)

$(NAME_MAIN_DEBUG): $(ALL_FILES)
	$(CC) $(CFLAGS) -g3 $(ALL_FILES) -o $@ $(INCLUDES)

# ---------- INSTRUCTIONS ----------

instructions: $(NAME_INSTRUCTIONS)

$(NAME_INSTRUCTIONS): $(INSTRUCTIONS_OBJ)
	ar rcs $@ $^

# ---------- LIB ----------

lib: $(NAME_LIB)

$(NAME_LIB): $(LIB_OBJ)
	ar rcs $@ $^

# ---------- PARSE ----------

parse: $(NAME_PARSE)

$(NAME_PARSE): $(PARSE_OBJ)
	ar rcs $@ $^

# ---------- ALGO ----------

algo: $(NAME_ALGO)

$(NAME_ALGO): $(ALGO_OBJ)
	ar rcs $@ $^

# ---------- BENCH ----------

bench: $(NAME_ALGO)

$(NAME_BENCH): $(BENCH_OBJ)
	ar rcs $@ $^

# ########## TESTS ##########

# ========== DIRECTORIES ==========

TESTS_DIR = tests

TESTS_INSTRUCTIONS_DIR = instructions

TESTS_UTILS_DIR = utils

# ========== HEADERS =========

TESTS_INCLUDES =	-I$(TESTS_DIR) \
					-I$(TESTS_DIR)/$(TESTS_INSTRUCTIONS_DIR) \
					-I$(TESTS_DIR)/$(TESTS_INSTRUCTIONS_DIR)/headers

# ========== FILES ==========

TESTS_FILES =	./$(TESTS_DIR)/$(TESTS_INSTRUCTIONS_DIR)/tests_instructions.c \
				./$(TESTS_DIR)/$(TESTS_INSTRUCTIONS_DIR)/$(TESTS_UTILS_DIR)/print.c \
				./$(TESTS_DIR)/$(TESTS_INSTRUCTIONS_DIR)/tests_reverse_rotate.c \
				./$(TESTS_DIR)/$(TESTS_INSTRUCTIONS_DIR)/tests_rotate.c \
				./$(TESTS_DIR)/$(TESTS_INSTRUCTIONS_DIR)/tests_swap.c \
				./$(TESTS_DIR)/$(TESTS_INSTRUCTIONS_DIR)/tests_push.c

# ========== NAMES ==========

NAME_TESTS = push_swap_tests

# ========== RULES ==========

# ---------- MAIN ----------

tests: $(NAME_TESTS)

$(NAME_TESTS): $(TESTS_FILES) $(INSTRUCTIONS_FILES) $(LIB_FILES)
	$(CC) $(CFLAGS) -g3 $(TESTS_FILES) $(INSTRUCTIONS_FILES) $(LIB_FILES) $(INCLUDES) $(TESTS_INCLUDES) -o $@

# ########## IMPLICIT RUlES ##########

%.o: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@ $(INCLUDES)

.PHONY: all clean fclean re instructions lib parse

-include $(DFILES)

# ========== ALL ==========

ALL_OBJ = $(SRCS_OBJ) $(INSTRUCTIONS_OBJ) $(LIB_OBJ) $(PARSE_OBJ) $(ALGO_OBJ) $(BENCH_OBJ) $(CHECKER_OBJ)

# ---------- CLEAN ----------

clean:
	rm -rf $(DFILES) $(ALL_OBJ) $(NAME_TESTS) $(NAME_INSTRUCTIONS) $(NAME_PARSE) $(NAME_LIB) $(NAME_ALGO) $(NAME_BENCH)

fclean: clean
	rm -rf $(NAME_MAIN) $(NAME_MAIN_DEBUG) $(NAME_CHECKER)

# ---------- re ----------

re: fclean all
